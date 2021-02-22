const express = require('express');
const router = express.Router();

/* GET users listing. */
router.get('/', (req, res, next) => {
  res.send('Product Get');
});
router.post('/', (req, res, next) => {
  res.send('Product Post');
});
router.put('/', (req, res, next) => {
  res.send('Product Put');
});
router.delete('/', (req, res, next) => {
  res.send('Product Delete');
});
module.exports = router;