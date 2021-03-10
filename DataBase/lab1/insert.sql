exec AddProduct  'Product1', 5, 203
exec AddProduct  'Product2', 3, 203
exec AddProduct  'Product3', 1, 203
exec AddProduct  'Product4', 2, 203

exec AddCustomer 'Anton', 'Borisov', 'wef@mail.ru', 'Belaruskaya 21', 'Mogilev'
exec AddCustomer 'Nikita', 'Petrov', 'wef@mail.ru', 'Belaruskaya 21', 'Minsk'
exec AddCustomer 'Misha', 'Sidrob', 'wef@mail.ru', 'Belaruskaya 21', 'Brest'

go
begin
declare @nowDate Date =  CAST( GETDATE() AS Date );
declare @order_id int 
exec AddOrder 1, @nowDate , @nowDate, @order_id out
exec AddOrderItem @order_id , 1 , 2 
exec AddOrderItem @order_id, 3 , 1
exec AddOrderItem @order_id, 2 , 2
end

exec GetProducts
exec GetCustomers
exec GetOrders

select SUM(total_price) from orders where order_date >= '2020-01-01' and order_date < '2022-01-01'
exec GetOrderItems