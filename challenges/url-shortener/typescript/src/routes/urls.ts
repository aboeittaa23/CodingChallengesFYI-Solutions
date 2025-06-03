import { Router, Request, Response } from "express";
import { UrlShortenerService } from "../services/urlShortener";
import dotenv from "dotenv";

// Load environment variables
dotenv.config();
const PORT = process.env.PORT || 3000;
const DOMAIN = process.env.DOMAIN || "http://localhost";

const router = Router();
const urlService = new UrlShortenerService();

router.post("/", (req: Request, res: Response) => {
    const { url } = req.body;
    if (!url) {
        res.status(400).send("Missing field: url\n");
        return;
    }
    try {
        const short_url = urlService.shortenUrl(url);
        res.json({
            key: short_url,
            long_url: url,
            short_url: `${DOMAIN}:${PORT}/${short_url}`,
        });
    } catch (error) {
        res.status(500).send(error.message);
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
