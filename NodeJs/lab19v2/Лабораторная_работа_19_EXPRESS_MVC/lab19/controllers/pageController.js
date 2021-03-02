exports.home = function (request, response) {
    response.render("home.hbs");
};

exports.addApplication = function (request, response) {
    response.render("addApplication.hbs");
};

exports.deleteApplication = function (request, response) {
    response.render("deleteApplication.hbs");
};

exports.addTour = function (request, response) {
    response.render("addTour.hbs");
};
