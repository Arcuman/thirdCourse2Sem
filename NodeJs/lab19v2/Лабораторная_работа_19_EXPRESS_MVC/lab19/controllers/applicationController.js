let Sequelize = require("sequelize");
let config = require('../config').config;
let sequelize = new Sequelize(config);
let db = require('../models/DB').ORM(sequelize);

exports.addApplication = function(request, response){
    const tour_id = request.body.tour_id;
    const client_id = request.body.client_id;
    const contract = request.body.contract;
    const is_confirmed = request.body.is_confirmed;
    sequelize.authenticate().then(() => {
        db.Tour_application.create({tour_id: tour_id, client_id: client_id, contract: contract, is_confirmed: is_confirmed})
            .then(applications => response.json(applications))
            .catch((err) => response.status(400).send(err))
    });
};

exports.updateApplication = function(request, response){
    const tour_application_id = request.body.tour_application_id;
    const is_confirmed = request.body.is_confirmed;
    sequelize.authenticate().then(() => {
        db.Tour_application.update({is_confirmed: is_confirmed}, {where:{tour_application_id: tour_application_id}})
            .then(applications => response.json(applications))
            .catch((err) => response.status(400).send(err))
    });
};


exports.removeApplication = function(request, response){
    const tour_application_id = request.params.tour_application_id;
    sequelize.authenticate().then(() => {
        db.Tour_application.destroy({where:{tour_application_id: tour_application_id}})
            .then(count => response.send(JSON.stringify({"rows deleted": count})))
            .catch((err) => response.status(400).send(err))
    });
};

exports.getApplications = function(request, response){
    sequelize.authenticate().then(() => {
        db.Tour_application.findAll().then(applications => response.json(applications))
    });
};