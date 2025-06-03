import { Router, Request, Response } from "express";
import { UrlShortenerService } from "../services/urlShortener";

const router = Router();
const urlService = new UrlShortenerService();

router.post("/", (req: Request, res: Response) => {
    const { url } = req.body;
    if (!url) {
        res.status(400).json({ error: "URL is required" });
        return;
    }
    try {
        const short_url = urlService.shortenUrl(url);
        res.json({
            key: short_url,
            long_url: url,
            short_url: `http://localhost:${process.env.PORT}/${short_url}`,
        });
    } catch (error) {
        res.status(500).json({ error: error.message });
        return;
    }
});

router.get("/:short_url", (req: Request, res: Response) => {
    const { short_url } = req.params;
    const long_url = urlService.expandUrl(short_url);

    if (!long_url) {
        res.status(404).json({ error: "Short URL not found" });
        return;
    }

    res.json({
        short_url: short_url,
        long_url: long_url,
    });
});

export default router;
