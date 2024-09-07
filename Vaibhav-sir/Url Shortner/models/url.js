const mongoose = require("mongoose");

const urlShema = new mongoose.Schema(
  {
    shortId: {
      type: String,
      required: true,
      unique: true
    },
    redirectUrl: {
      type: String,
      required: true
    },
    createdBy: {
      type: mongoose.Schema.Types.ObjectId,
      ref: "users"
    },
    visitHistory: [{ timestamps: { type: Number } }]
  },
  { timestamps: true }
);

const URL = mongoose.model("url", urlShema);

module.exports = URL;
