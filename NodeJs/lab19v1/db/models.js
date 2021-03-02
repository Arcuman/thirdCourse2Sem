const dbConfig = require("./config.js");
const Sequelize = require("sequelize");
const sequelize = new Sequelize(dbConfig.config)

const db = {};

db.Sequelize = Sequelize;
db.sequelize = sequelize;

db.orders = require("../components/Order/order.model")(sequelize);
db.customers = require("../components/Cutomer/customer.model")(sequelize);
db.products = require("../components/Product/pruduct.model")(sequelize);

db.orders.belongsTo(db.customers);
db.orders.belongsTo(db.products);

module.exports = db;