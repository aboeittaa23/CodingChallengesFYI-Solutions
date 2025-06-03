import express, { Express, Request, Response } from "express";
import router from "./routes/urls";
import dotenv from "dotenv";

// Load environment variables
dotenv.config();
const PORT = process.env.PORT || 3000;
const DOMAIN = process.env.DOMAIN || "http://localhost";

const app: Express = express();

app.use(express.json());
app.use("/", router);

app.listen(PORT, () => {
    console.log(`Server running at ${DOMAIN}:${PORT}`);
});
