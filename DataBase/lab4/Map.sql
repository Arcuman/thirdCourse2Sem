use Store
select top 100 name, qgs_fid, geom, geom.ToString() as WKT, geom.STSrid as SRID from map

declare @g geometry = geometry::STGeomFromText('Point(0 0)', 0);
select @g.STBuffer(5), @g.STBuffer(5).ToString() as WKT from map

DECLARE @g geography;  
SET @g = geography::STGeomFromText('LINESTRING(-122.360 47.656, -122.343 47.656)', 4326);  
SELECT @g.ToString();  

go
use Store;

--3. пересечение, исключение или объединение данных
declare @g1 geometry; 
select @g1 = geom from MAP where qgs_fid = 27;
declare @g2 geometry; 
select @g2 = geom from MAP where qgs_fid = 17;
select @g1.STIntersects(@g2) as [Пересеклось], @g1.STCrosses(@g2) as [Объединилось], @g1.STContains(@g2) as [Исключилось];

go
declare @g1 geometry; 
select @g1 = Point from mapCoord where Id = (select Customer_Addr from customers where customer_id = 1);
declare @g2 geometry; 
select @g2 = Point from mapCoord where Id = (select Customer_Addr from customers where customer_id = 3);
select @g1.STIntersects(@g2) as [Пересеклось], @g1.STCrosses(@g2) as [Объединилось], @g1.STContains(@g2) as [Исключилось];

--3. Расстояние
go
declare @g1 geometry; 
select @g1 = geom from MAP where qgs_fid = 1;
declare @g2 geometry; 
select @g2 = geom from MAP where qgs_fid = 2;
Select @g1.STDistance(@g2) as D;

go
declare @g1 geometry; 
select @g1 = geom from MAP where qgs_fid = 27;
declare @g2 geometry; 
select @g2 = geom from MAP where qgs_fid = 17;
Select @g1.STDistance(@g2) as D;

go
declare @g1 geometry; 
select @g1 = Point from mapCoord where Id = (select Customer_Addr from customers where customer_id = 1);
declare @g2 geometry; 
select @g2 = Point from mapCoord where Id = (select Customer_Addr from customers where customer_id = 2);
Select @g1.STDistance(@g2), @g1, @g2;

--6. Change map object
Declare @m geometry = geometry::STGeomFromText('LINESTRING(6 6, 3 2.2, 17 17)', 0);
select @m.ToString(), @m.Reduce(10000).ToString() as Reduced;

DECLARE @g geography = 'LineString(120 45, 120.1 45.1, 199.9 45.2, 120 46)'  
SELECT @g.ToString(), @g.Reduce(10000).ToString()

DECLARE @g geometry;  
DECLARE @h geometry;  
SET @g = geometry::STGeomFromText('LINESTRING(0 2, 2 0)', 0);  
SET @h = geometry::STGeomFromText('LINESTRING(0 0, 2 2)', 0);  
SELECT @g.STIntersects(@h);  

