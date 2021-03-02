const express = require("express");
const clientController = require("../controllers/clientController.js");
const clientRouter = express.Router();

clientRouter.get("/", clientController.getClients);
clientRouter.post("/post", clientController.addClient);
clientRouter.put("/put", clientController.updateClient);
clientRouter.delete("/delete/:client_id", clientController.removeClient);
module.exports = clientRouter;