const express = require("express");
const {
  handleGenerateNewURL,
  handleRedirection,
  handleAnalytics
} = require("../controllers/url");
const router = express.Router();

router.route("/").post(handleGenerateNewURL);

router.route("/:shortId").get(handleRedirection);

router.route("/analytics/:shortId").get(handleAnalytics);

module.exports = router;
