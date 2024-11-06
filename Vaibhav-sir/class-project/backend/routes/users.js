import { error } from "console";
import express from "express";
import fileSystem from "fs";

const router = express.Router();

// router.get("/", (req, res) => {
//     console.log("Response now from router");
//     let fileData = fileSystem.readFileSync("../data/db.json", { encoding: "utf-8" });

//     const users = JSON.parse(fileData)?.users;
//     console.log("The Users data is: ", users);
//     if (users && users.length > 0) {
//       res.send(users);
//     } else {
//       res.status(204);
//       res.send();
//     }
// });

// Create post route for signup page to add a new user
router.post("/", (req, res) => {
  const { firstName, lastName, email, password } = req.body;
  const newUser = {
    id: new Date().getTime().toString(),
    firstName,
    lastName,
    email,
    password
  };

  let db;
  try {
    db = fileSystem.readFileSync("../data/db.json", { encoding: "utf-8" });
  } catch (error) {
    res.status(500);
    return res.send({
      message: "Problem connecting with database",
      error: error
    });
  }

  let dbParsed = JSON.parse(db);
  let currentUsersList = dbParsed.users || [];
  let updatedUsersList = [...currentUsersList, newUser];
  let updatedDbParsed = { ...dbParsed, users: updatedUsersList };
  let updatedDb = JSON.stringify(updatedDbParsed);
  console.log(updatedDb);
  // console.log("Updated Users List: ", updatedUsersList);
  try {
    fileSystem.writeFileSync("../data/db.json", updatedDb);
    res.status(201).send({ message: "User added successfully", user: newUser });
  } catch (error) {
    res.status(500).send({ error: error, message: "Failed to add user" });
  }
});

// SignIn functionality
router.post("/signin", (req, res) => {
  const { email, password } = req.body;
  try {
    const db = fileSystem.readFileSync("../data/db.json", {
      encoding: "utf-8"
    });
    const dbParsed = JSON.parse(db);
    const users = dbParsed.users || [];
    const user = users.find(
      user => user.email === email && user.password === password
    );
    if (user) {
      console.log("Success");
      res.status(200).send({
        message: "Login successful",
        user: {
          id: user.id,
          email: user.email,
          firstName: user.firstName,
          lastName: user.lastName
        }
      });
    } else {
        console.log("fails");
      res.status(401).send({ message: "Invalid email or password" });
    }
  } catch (error) {
    res.status(500).send({
      message: "Error during signin",
      error: error
    });
  }
});

export default router;
