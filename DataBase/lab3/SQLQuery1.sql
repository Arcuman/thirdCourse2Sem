exec SumOrderDate '2010-01-01' , '2025-02-02'

go
declare @Addres CustomAddress 
	set @Addres = 'sad asd'
	select @Addres.ToString()
go

go
declare @Addres CustomAddress 
	set @Addres = 'sa@d asd'
	select @Addres.ToString()
go