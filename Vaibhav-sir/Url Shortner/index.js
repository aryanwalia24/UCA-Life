const express = require("express");
const app = express();
const PORT = 8001;

const { connectMongoDB } = require("./connect.js");
const urlRoute = require("./routes/url");
const URL = require("./models/url");

connectMongoDB("mongodb://127.0.0.1:27017/UrlShortner")
  .then(() => console.log("Mongoose Connected"))
  .catch(err => console.log("Mogoose Error ", err));

app.use(express.json());

app.use("/url", urlRoute);

app.listen(PORT, () => {
  console.log(`Server started at Port: ${PORT}`);
});
