const express = require('express');
const customerController = require("./customer.controller");
const router = express.Router();

router.get('/:customerId', customerController.get);
router.get('/', customerController.getAll);
router.post('/', customerController.create);
router.put('/:customerId', customerController.update);
router.delete('/:customerId', customerController.delete);
module.exports = router;