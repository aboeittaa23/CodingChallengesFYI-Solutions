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

    shortenUrl(long_url: string): string {
        // Validate URL
        if (!this.isValidUrl(long_url)) {
            throw new Error("Invalid URL format");
        }

        const short_url = this.generateShortUrl(long_url);

        // Check for existing mapping
        if (this.urlMap.has(short_url)) {
            if (this.urlMap.get(short_url) === long_url) {
                return short_url;
            }
            throw new Error(`Hash collision detected for ${long_url}`);
        }

        // Save new mapping
        this.urlMap.set(short_url, long_url);
        this.saveUrl(short_url, long_url);

        return short_url;
    }

    expandUrl(short_url: string): string {
        const long_url = this.urlMap.get(short_url);
        if (!long_url) {
            throw new Error("Short URL not found");
        }
        return long_url;
    }

    private isValidUrl(url: string): boolean {
        try {
            new URL(url);
            return true;
        } catch {
            return false;
        }
    }

    private generateShortUrl(long_url: string): string {
        const hash = crypto
            .createHash(UrlShortenerService.HASH_ALGORITHM)
            .update(long_url)
            .digest("hex");

        return hash.substring(0, UrlShortenerService.SHORT_URL_LENGTH);
    }

    private saveUrl(short_url: string, long_url: string): void {
        try {
            // Ensure directory exists
            const dir = path.dirname(this.dataFilePath);
            if (!fs.existsSync(dir)) {
                fs.mkdirSync(dir, { recursive: true });
            }

            // Append to CSV file
            const line = `${short_url},${long_url}\n`;
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

                const short_url = line.substring(0, commaIndex);
                const long_url = line.substring(commaIndex + 1);

                if (short_url && long_url) {
                    this.urlMap.set(short_url, long_url);
                }
            }
        } catch (error) {
            console.error(`Failed to load URLs: ${error.message}`);
        }
    }
}
