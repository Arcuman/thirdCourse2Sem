const express = require('express');
const loginRoute = express.Router();
const Users = require('./../models/users');

loginRoute.get('/', (request, response) => {
    response.sendFile('login.html', {root: './views'});
});

loginRoute.post('/', (request, response) => {
    const {firstName, lastName} = request.body;
    const user = Users.getUserByFirstName(firstName);
    if (!user || user.lastName !== lastName) {
        response.status(403).sendFile('login.html', {root: './views'});
    } else {
        response.redirect(`/home?id=${user.id}&firstName=${user.firstName}&lastName=${user.lastName}`);
    }
});

module.exports = loginRoute;
