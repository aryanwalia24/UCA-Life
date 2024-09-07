const express = require("express");
const path = require("path");
const cookieParser = require("cookie-parser");
const app = express();
const PORT = 8001;

const { connectMongoDB } = require("./connect.js");
const URL = require("./models/url");
const { restrictUserToLogin, checkAuth } = require("./middlewares/auth");

const urlRoute = require("./routes/url");
const userRoute = require("./routes/user");
const staticRoute = require("./routes/staticRouter");

connectMongoDB("mongodb://127.0.0.1:27017/UrlShortner")
  .then(() => console.log("Mongoose Connected"))
  .catch(err => console.log("Mogoose Error ", err));

app.set("view engine", "ejs");
app.set("views", path.resolve("./views"));

app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());

app.use("/url", restrictUserToLogin, urlRoute);
app.use("/user", userRoute);
app.use("/", checkAuth, staticRoute);

app.listen(PORT, () => {
  console.log(`Server started at Port: ${PORT}`);
});
