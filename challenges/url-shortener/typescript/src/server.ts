import express, { Express, Request, Response } from "express";
import router from "./routes/urls";

const app: Express = express();

app.use(express.json());
app.use("/", router);

app.listen(process.env.PORT, () => {
    console.log(`Server running at http://localhost:${process.env.PORT}`);
});
