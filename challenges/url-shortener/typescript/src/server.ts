import express, { Express, Request, Response } from "express";

const app: Express = express();
const PORT = 3000;

// Middleware to parse JSON
app.use(express.json());

// Basic test route
app.get("/", (req: Request, res: Response) => {
    res.json({ message: "Server is running!" });
});

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
