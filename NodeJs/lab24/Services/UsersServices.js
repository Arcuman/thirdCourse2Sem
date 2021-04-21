const Users = require("../models/index").users;

module.exports = {
    AddUsers: async (json) => {
        return await Users.create({
            username: json["username"],
            password: json["password"],
            age: json["age"],
        });
    },
    FindByUsername: async (json) => {
        return await Users.findAll({
            where: { username: json["username"] },
            raw: true,
        });
    },
    GetAll: async () => {
        return await Users.findAll({
            attributes: ['id', 'username', 'age']
        });
    },
    GetById: async (id) => {
        return await Users.findByPk(id, {

            attributes: ['id', 'username', 'age']
        });
    },
};
