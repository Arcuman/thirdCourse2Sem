let Sequelize = require("sequelize");
let config = require('../config').config;
let sequelize = new Sequelize(config);
let db = require('../models/DB').ORM(sequelize);

exports.addTour = function(request, response){
    const tour_name = request.body.tour_name;
    const tour_description = request.body.tour_description;
    const country = request.body.country;
    sequelize.authenticate().then(() => {
        db.Tour.create({tour_name: tour_name, tour_description: tour_description, country: country})
            .then(tours => response.json(tours))
            .catch((err) => response.status(400).send(err))
    });
};

exports.updateTour = function(request, response){
    const tour_id = request.body.tour_id;
    const tour_name = request.body.tour_name;
    const tour_description = request.body.tour_description;
    const country = request.body.country;
    sequelize.authenticate().then(() => {
        db.Tour.update({tour_name: tour_name, tour_description: tour_description, country: country}, {where:{tour_id: tour_id}})
            .then(applications => response.json(applications))
            .catch((err) => response.status(400).send(err))
    });
};


exports.removeTour = function(request, response){
    const tour_id = request.params.tour_id;
    sequelize.authenticate().then(() => {
        db.Tour.destroy({where:{tour_id: tour_id}})
            .then(count => response.send(JSON.stringify({"rows deleted": count})))
            .catch((err) => response.status(400).send(err))
    });
};

exports.getTours = function(request, response){
    sequelize.authenticate().then(() => {
        db.Tour.findAll().then(tours => response.json(tours))
    });
};