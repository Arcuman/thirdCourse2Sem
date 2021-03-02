const express = require('express');
const productController = require("./product.controller");
const router = express.Router();

/* GET users listing. */
router.get('/:productId', productController.get);
router.get('/', productController.getAll);
router.post('/', productController.create);
router.put('/:productId', productController.update);
router.delete('/:productId', productController.delete);
module.exports = router;