let Sequelize = require("sequelize");
let Model = Sequelize.Model;

class Tour extends Model {
}

class Client extends Model {
}

class Tour_application extends Model {
}

function internalORM(sequelize) {
    Tour.init(
        {
            tour_id: {
                type: Sequelize.INTEGER,
                autoIncrement: true,
                primaryKey: true,
                allowNull: false
            },
            tour_name: {type: Sequelize.STRING, allowNull: false},
            tour_description: {type: Sequelize.STRING, allowNull: false},
            country: {type: Sequelize.STRING, allowNull: false}
        },
        {sequelize, modelName: 'Tour', tableName: 'Tour', timestamps: false}
    );

    Client.init(
        {
            client_id: {
                type: Sequelize.INTEGER,
                autoIncrement: true,
                primaryKey: true,
                allowNull: false
            },
            name: {type: Sequelize.STRING, allowNull: false},
            surname: {type: Sequelize.STRING, allowNull: false},
            patronymic: {type: Sequelize.STRING, allowNull: false},
            phone: {type: Sequelize.STRING, allowNull: false},
            passport: {type: Sequelize.STRING, allowNull: false}
        },
        {sequelize, modelName: 'Client', tableName: 'Client', timestamps: false}
    );

    Tour_application.init(
        {
            tour_application_id: {
                type: Sequelize.INTEGER,
                autoIncrement: true,
                primaryKey: true,
                allowNull: false
            },
            tour_id: {
                type: Sequelize.INTEGER, allowNull: false,
                references: {model: Tour, key: 'tour_id'}
            },
            client_id: {
                type: Sequelize.INTEGER, allowNull: false,
                references: {model: Client, key: 'client_id'}
            },
            contract: {type: Sequelize.STRING, allowNull: false},
            is_confirmed: {type: Sequelize.STRING, allowNull: false}
        },
        {sequelize, modelName: 'Tour_application', tableName: 'Tour_application', timestamps: false}
    );

    //sequelize.sync({force:true}).catch(error => console.log(error));
}

exports.ORM = (sequelize) => {
    internalORM(sequelize);
    return {Tour, Client, Tour_application}
}