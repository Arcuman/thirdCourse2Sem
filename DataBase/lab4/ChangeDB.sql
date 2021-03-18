go
use Store;

create table mapCoord
(
	Id int identity(1,1) constraint TOWN_ID_PK PRIMARY KEY,
	Point geometry
);

insert into mapCoord(Point) 
	values (geometry::STGeomFromText('Point(1 1)', 0)),
			(geometry::STGeomFromText('Point(10 21)', 0));

go
alter table Customers
	add Customer_Addr int constraint CHOME_ID_FK foreign key references mapCoord(Id);

go
alter table CANDIDATE
	add Place int constraint COFFICE_ID_FK foreign key references MAP(Id);

go
alter table WORKER
	add Place int constraint WOFFICE_ID_FK foreign key references MAP(Id);
