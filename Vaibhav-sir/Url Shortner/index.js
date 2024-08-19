const express = require("express");
const path = require("path");
const app = express();
const PORT = 8001;

const { connectMongoDB } = require("./connect.js");
const urlRoute = require("./routes/url");
const staticRoute = require("./routes/staticRouter");
const URL = require("./models/url");
const { ALL } = require("dns");

connectMongoDB("mongodb://127.0.0.1:27017/UrlShortner")
  .then(() => console.log("Mongoose Connected"))
  .catch(err => console.log("Mogoose Error ", err));

app.set("view engine", "ejs");
app.set("views", path.resolve("./views"));

app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.use("/url", urlRoute);
app.use("/", staticRoute);

app.listen(PORT, () => {
  console.log(`Server started at Port: ${PORT}`);
});
