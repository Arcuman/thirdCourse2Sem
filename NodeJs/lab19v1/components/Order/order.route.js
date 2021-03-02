const express = require('express');
const orderController = require("./order.controller");
const router = express.Router();

router.get('/:orderId', orderController.get);
router.get('/', orderController.getAll);
router.post('/', orderController.create);
router.put('/:orderId', orderController.update);
router.delete('/:orderId', orderController.delete);
module.exports = router;