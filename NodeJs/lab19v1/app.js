const createError = require('http-errors');
const express = require('express');
const logger = require('morgan');
const bodyParser = require('body-parser');

const ordersRouter = require('./components/Order/order.route');
const customersRouter = require('./components/Cutomer/customer.route')
const productsRouter = require('./components/Product/product.route');

const app = express();

app.use(bodyParser());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.use('/orders', ordersRouter);
app.use('/customers', customersRouter);
app.use('/products', productsRouter);

app.use((req, res, next) => {
  next(createError(404));
});

app.use((err, req, res, next) => {
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  res.status(err.status || 500);
  res.render('error');
});

const db = require("./db/models");

db.sequelize.sync().then(()=>{
  app.listen(3000, () => {
    console.log(`Server is running on port ${3000}.`);
  });
});
