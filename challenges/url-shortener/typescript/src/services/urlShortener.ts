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

        const shortUrl = this.generateShortUrl(longUrl);

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
        const longUrl = this.urlMap.get(shortUrl);
        if (!longUrl) {
            throw new Error("Short URL not found");
        }
        return longUrl;
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
        const hash = crypto
            .createHash(UrlShortenerService.HASH_ALGORITHM)
            .update(longUrl)
            .digest("hex");

        return hash.substring(0, UrlShortenerService.SHORT_URL_LENGTH);
    }

    private saveUrl(shortUrl: string, longUrl: string): void {
        try {
            // Ensure directory exists
            const dir = path.dirname(this.dataFilePath);
            if (!fs.existsSync(dir)) {
                fs.mkdirSync(dir, { recursive: true });
            }

            // Append to CSV file
            const line = `${shortUrl},${longUrl}\n`;
            fs.appendFileSync(this.dataFilePath, line);
        } catch (error) {
            throw new Error(`Could not append to file ${this.dataFilePath}`);
        }
    }

    private loadUrls(): void {
        if (!fs.existsSync(this.dataFilePath)) {
            console.log(`Creating new URL database at ${this.dataFilePath}`);
            return;
        }

        try {
            const data = fs.readFileSync(this.dataFilePath, "utf-8");
            const lines = data.split("\n").filter((line) => line.trim());

            for (const line of lines) {
                const commaIndex = line.indexOf(",");
                if (commaIndex === -1) {
                    console.warn(`Skipping invalid line: ${line}`);
                    continue;
                }

                const shortUrl = line.substring(0, commaIndex);
                const longUrl = line.substring(commaIndex + 1);

                if (shortUrl && longUrl) {
                    this.urlMap.set(shortUrl, longUrl);
                }
            }
        } catch (error) {
            console.error(`Failed to load URLs: ${error.message}`);
        }
    }
}
