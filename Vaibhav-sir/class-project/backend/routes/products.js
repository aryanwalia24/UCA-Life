import { error } from "console";
import express from "express";
import fileSystem from "fs";

const router = express.Router();

router.get("/", (req, res) => {
  console.log("Response now from router");
  let fileData = fileSystem.readFileSync("../data/db.json", { encoding: "utf-8" });

  const products = JSON.parse(fileData)?.products;
  console.log("The products data is: ", products);
  if (products && products.length > 0) {
    res.send(products);
  } else {
    res.status(204);
    res.send();
  }
});

router.post("/", (req, res) => {
  const product = req.body;
  // Logic to update the content in file
  let db;
  try {
    db = fileSystem.readFileSync("../data/db.json", { encoding: "utf-8" });
  } catch (error) {
    res.status(500);
    return res.send({
      message: "Problem connecting with database",
      error: error,
    });
  }
  let dbParsed = JSON.parse(db);
  let currentProductsList = dbParsed.products;
  let updatedProductsList = [...currentProductsList, product];
  let updatedDbParsed = { ...dbParsed, products: updatedProductsList };
  let updatedDb = JSON.stringify(updatedDbParsed);

  try {
    fileSystem.writeFileSync("../data/db.json", updatedDb);
    res.send({ message: "Post api success", product: product });
  } catch (error) {
    res.status(500);
    res.send({ error: error, message: "Post api failure" });
  }
});

router.put("/", (req, res) => {
  const product = req.body;
  console.log(product);
  let db;
  try {
    db = fileSystem.readFileSync("../data/db.json", { encoding: "utf-8" });
  } catch {
    res.status(500);
    return res.send({
      message: "Problem connecting with database",
      error: error
    });
  }
  let dbParsed = JSON.parse(db);
  let currentProductsList = dbParsed.products;

  // update the list updated data
  let productToBeUpdatedIndex = currentProductsList.findIndex(
    (item) => item.id === product.id
  );
  if (productToBeUpdatedIndex > -1) {
    currentProductsList[productToBeUpdatedIndex] = product;
  } else {
    res.status(400);
    res.send({ error: "Product doesn't exist." });
  }

  let updatedDbParsed = { ...dbParsed, products: currentProductsList };
  let updatedDb = JSON.stringify(updatedDbParsed);
  try {
    fileSystem.writeFileSync("../data/db.json", updatedDb);
    res.send({ message: "Put api success", product: product });
  } catch (error) {
    res.status(500);
    res.send({ error: error, message: "Put api failure" });
  }
});

router.delete("/", (req, res) => {
  const product = req.body;
  let db;
  try {
    db = fileSystem.readFileSync("../data/db.json", { encoding: "utf-8" });
  } catch (error) {
    res.status(500);
    res.send({
      message: "Problem connecting with database",
      error: error
    });
  }

  let dbParsed = JSON.parse(db);
  let currentProductsList = dbParsed.products;

  // Update the product list with updated data
  let updatedProductsList = currentProductsList.filter(
    (item) => item.id !== product.id
  );

  let updatedDbParsed = { ...dbParsed, products: updatedProductsList };
  let updatedDb = JSON.stringify(updatedDbParsed);
  
  try {
    fileSystem.writeFileSync("../data/db.json", updatedDb);
    res.send({ message: "Product removed successfully", product: product });
  } catch (error) {
    res.status(500);
    res.send({ error: error, message: "Delete api failure" });
  }
});

export default router;
