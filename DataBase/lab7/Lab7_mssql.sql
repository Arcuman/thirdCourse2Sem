go
use Store


--TASK1
create table Report
(
    id         INTEGER primary key identity (1,1),
    xml_column XML
);
--TASK2

create procedure generateXML
as
declare @x XML
    set @x = (
        select products.product_id,
               product_name,
               order_products.quantity [Order Quantity],
               products.quantity       [Left Quantity]
        from products
                 join order_products
                      on order_products.product_id = products.product_id
        FOR XML AUTO);
SELECT @x
go

execute generateXML;

--TASK3
go
create procedure InsertInReport
as
DECLARE @s XML
    SET @s = (select products.product_id,
               product_name,
               order_products.quantity [Order Quantity],
               products.quantity       [Left Quantity]
        from products
                 join order_products
                      on order_products.product_id = products.product_id
        FOR XML raw );
insert into Report
values (@s);
go

execute InsertInReport
select *
from Report;

--task4
create primary xml index My_XML_Index on Report (xml_column)

create xml index Second_XML_Index on Report (xml_column)
    using xml index My_XML_Index for path

--task5
go
create procedure SelectData
as
select xml_column.query('/row') as [xml_column]
from Report
for xml auto, type;
go

execute SelectData

select xml_column.value('(/row/@product_name)[2]', 'nvarchar(max)') as [xml_column]
from Report
for xml auto, type;

select r.Id,
       m.c.value('@product_name', 'nvarchar(max)') as [product_name]
from Report as r
         outer apply r.xml_column.nodes('/row') as m(c)

select xml_column.query('/row') as [xml_column]
from Report
for xml auto, type;
