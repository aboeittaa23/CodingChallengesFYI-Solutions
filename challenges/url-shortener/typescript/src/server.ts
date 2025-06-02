import express, { Express, Request, Response } from "express";
import router from "./routes/urls";

const app: Express = express();
const PORT = 3000;

app.use(express.json());
app.use("/api", router);

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
