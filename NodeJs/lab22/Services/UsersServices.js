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
};
