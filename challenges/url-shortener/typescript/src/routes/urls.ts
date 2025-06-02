import { Router, Request, Response } from "express";
import { UrlShortenerService } from "../services/urlShortener";

const router = Router();
const urlService = new UrlShortenerService();

router.post("/shorten", (req: Request, res: Response) => {
    const { url } = req.body;
    if (!url) {
        return res.status(400).json({ error: "URL is required" });
    }
    try {
        const shortUrl = urlService.shortenUrl(url);
        res.json({
            "Short Url": shortUrl,
            "Long Url": url,
        });
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

router.get("/expand/:shortUrl", (req: Request, res: Response) => {
    const { shortUrl } = req.params;
    const longUrl = urlService.expandUrl(shortUrl);

    if (!longUrl) {
        return res.status(404).json({ error: "Short URL not found" });
    }

    res.json({
        "Short Url": shortUrl,
        "Long Url": longUrl,
    });
});

export default router;
