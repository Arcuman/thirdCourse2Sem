const express = require("express");
const tourController = require("../controllers/tourController.js");
const tourRouter = express.Router();

tourRouter.get("/", tourController.getTours);
tourRouter.post("/post", tourController.addTour);
tourRouter.put("/put", tourController.updateTour);
tourRouter.delete("/delete/:tour_id", tourController.removeTour);

module.exports = tourRouter;