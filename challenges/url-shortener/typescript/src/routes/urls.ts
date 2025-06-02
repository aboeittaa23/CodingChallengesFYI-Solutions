import { Router, Request, Response } from "express";
import { UrlShortenerService } from "../services/urlShortener";

const router = Router();
const urlService = new UrlShortenerService();

router.post("/shorten", (req: Request, res: Response) => {
    const { url } = req.body;
    if (!url) {
        res.status(400).json({ error: "URL is required" });
        return;
    }
    try {
        const shortUrl = urlService.shortenUrl(url);
        res.json({
            "Long Url": url,
            "Short Url": shortUrl,
        });
    } catch (error) {
        res.status(500).json({ error: error.message });
        return;
    }
});

router.get("/expand/:shortUrl", (req: Request, res: Response) => {
    const { shortUrl } = req.params;
    const longUrl = urlService.expandUrl(shortUrl);

    if (!longUrl) {
        res.status(404).json({ error: "Short URL not found" });
        return;
    }

    res.json({
        "Short Url": shortUrl,
        "Long Url": longUrl,
    });
});

export default router;
