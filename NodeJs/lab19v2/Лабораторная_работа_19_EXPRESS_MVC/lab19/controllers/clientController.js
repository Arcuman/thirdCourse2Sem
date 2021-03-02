let Sequelize = require("sequelize");
let config = require('../config').config;
let sequelize = new Sequelize(config);
let db = require('../models/DB').ORM(sequelize);

exports.addClient = function(request, response){
    const name = request.body.name;
    const surname = request.body.surname;
    const patronymic = request.body.patronymic;
    const phone = request.body.phone;
    const passport = request.body.passport;
    sequelize.authenticate().then(() => {
        db.Client.create({name: name, surname: surname, patronymic: patronymic, phone: phone, passport: passport})
                 .then(clients => response.json(clients))
                 .catch((err) => response.status(400).send(err))
    });
};

exports.updateClient = function(request, response){
    const client_id = request.body.client_id;
    const name = request.body.name;
    const surname = request.body.surname;
    const patronymic = request.body.patronymic;
    const phone = request.body.phone;
    const passport = request.body.passport;
    sequelize.authenticate().then(() => {
        db.Client.update({name: name, surname: surname, patronymic: patronymic, phone: phone, passport: passport}, {where:{client_id: client_id}})
                 .then(clients => response.json(clients))
                 .catch((err) => response.status(400).send(err))
    });
};


exports.removeClient = function(request, response){
    const client_id = request.params.client_id;
    sequelize.authenticate().then(() => {
        db.Client.destroy({where:{client_id: client_id}})
                 .then(count => response.send(JSON.stringify({"rows deleted": count})))
                 .catch((err) => response.status(400).send(err))
    });
};

exports.getClients = function(request, response){
    sequelize.authenticate().then(() => {
        db.Client.findAll().then(clients => response.json(clients))
    });
};