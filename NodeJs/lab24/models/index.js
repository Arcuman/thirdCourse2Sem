const config = require('../config');
const Sequelize = require("sequelize");

const sequelize = new Sequelize(config.db)
const db = {};

db.Sequelize = Sequelize;
db.sequelize = sequelize;

db.users = require("./users")(Sequelize, sequelize);
db.repos = require("./repos")(Sequelize, sequelize);
db.commits = require("./commits")(Sequelize, sequelize);

db.users.hasMany(db.repos, { as: "repos" });
db.repos.belongsTo(db.users);

db.repos.hasMany(db.repos, { as: "commits" });
db.commits.belongsTo(db.repos);

module.exports = db;
