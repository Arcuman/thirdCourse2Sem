const express = require('express');
const userService = require("../Services/UsersServices");
const router = express.Router();

router.get('/', async (req, res) => {
    const users = await userService.GetAll()
    return res.send(users);
});
router.get('/:id', async (req, res) => {
    const id = req.params.id
    const user = await userService.GetById(id)
    if(!user)
        return res.status(404).send('User not found');
    return res.send(user);
});
module.exports = router;
