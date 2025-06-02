import { Router, Request, Response } from "express";
import { UrlShortenerService } from "../services/urlShortener";

const router = Router();
const urlService = new UrlShortenerService();

router.post("/shorten", (req: Request, res: Response) => {
    const longUrl = req.body.url;
    const shortUrl = urlService.shortenUrl(longUrl);
    res.json({ shortUrl });
});

router.get("/expand/:shortUrl", (req: Request, res: Response) => {
    const shortUrl = req.params.shortUrl;
    // Sanitize: Only allow 8-character alphanumeric strings
    // if (!/^[a-zA-Z0-9]{8}$/.test(shortUrl)) {
    //     return res.status(400).send("Invalid short URL format.");
    // }
    const longUrl = urlService.expandUrl(shortUrl);
    res.send(longUrl);
});

export default router;
