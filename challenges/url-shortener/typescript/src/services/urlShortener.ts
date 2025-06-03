import * as crypto from "crypto";
import * as fs from "fs";
import * as path from "path";

export class UrlShortenerService {
    private static readonly SHORT_URL_LENGTH = 8;
    private static readonly HASH_ALGORITHM = "md5";
    private static readonly DATA_DIR = "data";
    private static readonly DATA_FILE = "urls.csv";

    private urlMap = new Map<string, string>();
    private dataFilePath = path.join(
        UrlShortenerService.DATA_DIR,
        UrlShortenerService.DATA_FILE
    );

    constructor() {
        this.loadUrls();
    }

    shortenUrl(longUrl: string): string {
        // Validate URL
        if (!this.isValidUrl(longUrl)) {
            throw new Error("Invalid URL format");
        }

        const shortUrl: string = this.generateShortUrl(longUrl);

        // Check for existing mapping
        if (this.urlMap.has(shortUrl)) {
            if (this.urlMap.get(shortUrl) === longUrl) {
                return shortUrl;
            }
            throw new Error(`Hash collision detected for ${longUrl}`);
        }

        // Save new mapping
        this.urlMap.set(shortUrl, longUrl);
        this.saveUrl(shortUrl, longUrl);

        return shortUrl;
    }

    expandUrl(shortUrl: string): string {
        return this.urlMap.get(shortUrl) || "";
    }

    private isValidUrl(url: string): boolean {
        try {
            new URL(url);
            return true;
        } catch {
            return false;
        }
    }

    private generateShortUrl(longUrl: string): string {
        const hash = crypto.createHash("md5").update(longUrl).digest("hex");
        return hash.substring(0, 8);
    }

    private saveUrl(shortUrl: string, longUrl: string) {
        try {
            const dir = path.dirname(this.dataFilePath);
            if (!fs.existsSync(dir)) {
                fs.mkdirSync(dir, { recursive: true });
            }
            fs.appendFileSync(this.dataFilePath, `${shortUrl},${longUrl}\n`);
        } catch (error) {
            throw new Error(`Could not append to file ${this.dataFilePath}`);
        }
    }

    private loadUrls() {
        if (!fs.existsSync(this.dataFilePath)) {
            console.error("No existing URL file found. Starting fresh.");
            return;
        }
        const data = fs.readFileSync(this.dataFilePath, "utf-8");
        const lines = data.split("\n");
        for (const line of lines) {
            if (!line.trim()) continue; // skip empty lines
            const pos = line.indexOf(",");
            if (pos !== -1) {
                const shortUrl = line.substring(0, pos);
                const longUrl = line.substring(pos + 1);
                this.urlMap.set(shortUrl, longUrl);
            }
        }
    }
}
