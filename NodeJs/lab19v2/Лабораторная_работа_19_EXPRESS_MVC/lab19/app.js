const app = require("express")();
const bodyParser = require("body-parser");
const clientRouter = require("./routes/clientRouter.js");
const applicationRouter = require("./routes/applicationRouter.js");
const tourRouter = require("./routes/tourRouter.js");
const homeRouter = require("./routes/pageRouter.js");

app.set("view engine", "hbs");
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.use("/clients", clientRouter);
app.use("/tours", tourRouter);
app.use("/applications", applicationRouter);

app.use("/", homeRouter);

app.use(function (req, res, next) {
    res.status(404).send("Not Found")
});

app.listen(3000);