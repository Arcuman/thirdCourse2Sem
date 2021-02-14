
const Users = [
    {
        id: 1,
        firstName: 'Anton',
        lastName: 'Borisov'
    },
    {
        id: 2,
        firstName: 'Vadim',
        lastName: 'Ginko'
    },
    {
        id: 3,
        firstName: 'Maks',
        lastName: 'Primakov'
    }
];

module.exports = {
    getUserByFirstName: (firstName) => {
        return Users.find(user => user.firstName === firstName);
    },

    createUser: ({firstName, lastName}) => {
        const id = Users.length + 1;
        const newUser = {id, firstName, lastName};
        Users.push(newUser);
        return newUser;
    }
};
