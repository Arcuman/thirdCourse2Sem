const express = require("express");
const pageController = require("../controllers/pageController.js");
const pageRouter = express.Router();

pageRouter.get("/home", pageController.home);
pageRouter.get("/addTour", pageController.addTour);
pageRouter.get("/addApplication", pageController.addApplication);
pageRouter.get("/deleteApplication", pageController.deleteApplication);

module.exports = pageRouter;