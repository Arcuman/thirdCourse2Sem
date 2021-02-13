drop table order_items;
drop table orders;
drop table customers;
drop table products;

CREATE TABLE products (
	product_id INT IDENTITY (1, 1) PRIMARY KEY,
	product_name NVARCHAR (255) NOT NULL,
	price DECIMAL (10, 2) NOT NULL,
	quantity INT,
);

CREATE TABLE customers (
	customer_id INT IDENTITY (1, 1) PRIMARY KEY,
	first_name NVARCHAR (255) NOT NULL,
	last_name NVARCHAR (255) NOT NULL,
	email NVARCHAR (255) NOT NULL,
	address NVARCHAR (255),
	city NVARCHAR (50)
);

-- Order status: 1 = Pending; 2 = Processing; 3 = Rejected; 4 = Completed
CREATE TABLE orders (
	order_id INT IDENTITY (1, 1) PRIMARY KEY,
	customer_id INT,
	order_status tinyint NOT NULL,
	order_date DATE NOT NULL,
	required_date DATE NOT NULL,
	shipped_date DATE,
	FOREIGN KEY (customer_id) 
        REFERENCES customers (customer_id) 
        ON DELETE CASCADE ON UPDATE CASCADE,
);

CREATE TABLE order_items(
	order_item_id INT IDENTITY (1, 1) PRIMARY KEY,
	order_id INT,
	product_id INT NOT NULL,
	quantity INT NOT NULL,
	FOREIGN KEY (order_id) 
        REFERENCES orders (order_id) 
        ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (product_id) 
        REFERENCES products (product_id) 
        ON DELETE CASCADE ON UPDATE CASCADE
);