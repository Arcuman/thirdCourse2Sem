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
exec AddOrder 1, @nowDate , @nowDate
exec AddOrderItem 1 , 1 , 2
exec AddOrderItem 1 , 3 , 2
exec AddOrderItem 1 , 2 , 2
end

exec GetProducts
exec GetCustomers
exec GetOrders
exec GetOrderItems