const express = require("express");
const URL = require("../models/url");

const router = express.Router();

router.route("/").get(async (req, res) => {
  if (!req.user) return res.redirect("/login");
  const allUrls = await URL.find({ createdBy: req.user._id });
  return res.render("home", {
    urls: allUrls
  });
});

router.route("/signup").get(async (req, res) => {
  return res.render("signup");
});

router.route("/login").get(async (req, res) => {
  return res.render("login");
});

module.exports = router;
