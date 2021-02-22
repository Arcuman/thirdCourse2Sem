const express = require('express');
const router = express.Router();

/* GET users listing. */
router.get('/', (req, res, next) => {
  res.send('Customer Get');
});
router.post('/', (req, res, next) => {
  res.send('Customer Post');
});
router.put('/', (req, res, next) => {
  res.send('Customer Put');
});
router.delete('/', (req, res, next) => {
  res.send('Customer Delete');
});
module.exports = router;