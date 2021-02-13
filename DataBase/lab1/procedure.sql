
--PRODUCTS
CREATE OR ALTER PROCEDURE GetProducts AS
BEGIN 
	SELECT * FROM products
END

go
CREATE OR ALTER PROCEDURE GetProductById
	@product_id int
AS
BEGIN 
	SELECT * FROM products where product_id = @product_id
END

GO
CREATE OR ALTER PROCEDURE AddProduct
    @name NVARCHAR(255),
    @count INT,
    @price DECIMAL (10, 2)
AS
BEGIN
INSERT INTO products(product_name, price, quantity) 
VALUES(@name, @price, @count)
END;
go

Create OR ALTER Procedure UpdateProduct
		@product_id int, 
		@name NVARCHAR(255),
		@quantity int,
		@price DECIMAL (10, 2)
AS
Begin
	UPDATE products 
	SET  price = @price, product_name = @name, quantity = @quantity 
	where products.product_id = @product_id
End;
go 

go
Create or Alter Procedure DeleteProduct
		@product_id int
AS
Begin
	DELETE products where products.product_id = @product_id;
End;
go 

--CUSTOMERS
CREATE OR ALTER PROCEDURE GetCustomers AS
BEGIN 
	SELECT * FROM customers
END

go
CREATE OR ALTER PROCEDURE GetCustomerById
	@customer_id int
AS
BEGIN 
	SELECT * FROM customers where customer_id = @customer_id
END

go
CREATE OR ALTER PROCEDURE GetProductById
	@product_id int
AS
BEGIN 
	SELECT * FROM products where product_id = @product_id
END

GO
CREATE OR ALTER PROCEDURE AddCustomer
    @first_name NVARCHAR(255),
	@last_name NVARCHAR(255),
	@email NVARCHAR(255),
	@address NVARCHAR(255),
	@city NVARCHAR(50)
AS
BEGIN
INSERT INTO customers(first_name, last_name, email, address, city) 
VALUES(@first_name, @last_name, @email, @address, @city)
END;
go

Create OR ALTER Procedure UpdateCustomer
		@customer_id int, 
		@first_name NVARCHAR(255),
		@last_name NVARCHAR(255),
		@email NVARCHAR(255),
		@address NVARCHAR(255),
		@city NVARCHAR(50)
AS
Begin
	UPDATE customers 
	SET  first_name = @first_name,
	last_name = @last_name, email = @email,
	address = @address, city = @city
	where customer_id = @customer_id
End;
go 

go
Create or Alter Procedure DeleteCustomerById
		@customer_id int
AS
Begin
	DELETE customers where customers.customer_id = @customer_id;
End;
go 

--ORDERS
CREATE OR ALTER PROCEDURE GetOrders AS
BEGIN 
	SELECT * FROM orders
END

go
CREATE OR ALTER PROCEDURE GetOrderById
	@order_id int
AS
BEGIN 
	SELECT * FROM orders where order_id = @order_id
END

go
CREATE OR ALTER PROCEDURE GetOrderByCustomId
	@customer_id int
AS
BEGIN 
	SELECT * FROM orders where customer_id = @customer_id
END

GO
CREATE OR ALTER PROCEDURE AddOrder
    @customer_id int,
	@order_date DATE,
	@required_date DATE
AS
BEGIN
INSERT INTO orders(customer_id, order_status, order_date, required_date, shipped_date) 
VALUES(@customer_id, 1, @order_date, @required_date, null)
END;
go

Create OR ALTER Procedure UpdateOrderStatus
		@order_id int, 
		@order_status TINYINT
AS
Begin
	UPDATE orders 
	SET  order_status = @order_status
	where order_id = @order_id
End;
go

Create OR ALTER Procedure UpdateOrderSnippedDate
		@order_id int, 
		@snipped_date DATE
AS
Begin
	UPDATE orders 
	SET  orders.shipped_date = @snipped_date
	where order_id = @order_id
End;
go

go
Create or Alter Procedure DeleteOrderById
		@order_id int
AS
Begin
	DELETE orders where orders.order_id = @order_id;
End;
go 

--ORDER ITEMS
go
CREATE OR ALTER PROCEDURE GetOrderItems AS
BEGIN 
	SELECT * FROM order_items
END

go
CREATE OR ALTER PROCEDURE GetOrderItemById
	@order_item_id int
AS
BEGIN 
	SELECT * FROM order_items where order_item_id = @order_item_id
END

go
CREATE OR ALTER PROCEDURE GetOrderItemByOrderId
	@order_id int
AS
BEGIN 
	SELECT * FROM order_items where order_id = @order_id
END


GO
CREATE OR ALTER PROCEDURE AddOrderItem
    @order_id int,
	@product_id int,
	@quantity int
AS
BEGIN
INSERT INTO order_items(order_id, product_id, quantity) 
VALUES(@order_id, @product_id, @quantity)
END;
go

go
Create or Alter Procedure DeleteOrderItemById
		@order_item_id int
AS
Begin
	DELETE order_items where order_items.order_item_id = @order_item_id;
End;
go 