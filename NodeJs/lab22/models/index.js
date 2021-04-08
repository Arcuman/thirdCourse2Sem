const config = require('../config');
const Sequelize = require("sequelize");

const sequelize = new Sequelize(config.db)

module.exports = {
    users: require("./users")(Sequelize, sequelize),
    sequelize,
    Sequelize,
};
