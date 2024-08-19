const URL = require("../models/url");

async function handleGenerateNewURL(req, res) {
  const { nanoid } = await import("nanoid");
  const body = req.body;
  if (!body || !body.url) {
    return res.status(400).json({ err: "url is required" });
  }
  const shortID = nanoid(8);
  await URL.create({
    shortId: shortID,
    redirectUrl: body.url,
    visitHistory: []
  });
  return res.render("home", { id: shortID });
}

async function handleRedirection(req, res) {
  const shortId = req.params.shortId;
  try {
    const entry = await URL.findOneAndUpdate(
      { shortId },
      {
        $push: {
          visitHistory: {
            timestamp: Date.now()
          }
        }
      },
      { new: true }
    );

    if (!entry) {
      return res.status(404).json({ error: "URL entry not found" });
    }
    res.redirect(entry.redirectUrl);
  } catch (error) {
    console.error("Error updating visit history:", error);
    res.status(500).json({ error: "Server error" });
  }
}

async function handleAnalytics(req, res) {
  const shortId = req.params.shortId;
  try {
    const result = await URL.findOne({ shortId });
    return res.json({
      totalclicks: result.visitHistory.length,
      anaylytics: result.visitHistory
    });
  } catch (error) {
    console.error("Error fetching Anaylytics : ", error);
    res.status(500).json({ error: "Server error" });
  }
}

module.exports = {
  handleGenerateNewURL,
  handleRedirection,
  handleAnalytics
};
