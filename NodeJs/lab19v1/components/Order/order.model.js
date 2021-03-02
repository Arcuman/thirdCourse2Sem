let Sequelize = require("sequelize");
module.exports = (sequelize) =>
    sequelize.define("order", {
        id: {
            type: Sequelize.INTEGER,
            autoIncrement: true,
            primaryKey: true,
            allowNull: false
        },
    });