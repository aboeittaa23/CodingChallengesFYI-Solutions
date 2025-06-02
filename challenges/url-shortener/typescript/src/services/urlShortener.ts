import * as crypto from "crypto";

export class UrlShortenerService {
    private urlMap = new Map<string, string>();

    shortenUrl(longUrl: string): string {
        let shortUrl: string = this.generateShortUrl(longUrl);

        if (this.urlMap.has(shortUrl)) {
            if (this.urlMap.get(shortUrl) === longUrl) {
                return shortUrl;
            }
            throw new Error(`Hash collision detected for ${longUrl}`);
        }

        this.urlMap.set(shortUrl, longUrl);
        return shortUrl;
    }

    expandUrl(shortUrl: string): string {
        return this.urlMap.get(shortUrl) || "";
    }

    private generateShortUrl(longUrl: string): string {
        const hash = crypto.createHash("md5").update(longUrl).digest("hex");
        return hash.substring(0, 8);
    }
}
