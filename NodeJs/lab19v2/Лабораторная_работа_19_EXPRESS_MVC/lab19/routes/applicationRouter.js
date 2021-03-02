const express = require("express");
const applicationController = require("../controllers/applicationController.js");
const applicationRouter = express.Router();

applicationRouter.get("/", applicationController.getApplications);
applicationRouter.post("/post", applicationController.addApplication);
applicationRouter.put("/put", applicationController.updateApplication);
applicationRouter.delete("/delete/:tour_application_id", applicationController.removeApplication);

module.exports = applicationRouter;