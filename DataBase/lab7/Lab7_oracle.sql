--1
create table Report1 
(
    id NUMBER GENERATED by default on null as IDENTITY,
    xm XMLTYPE
);

--2     
create or replace function CreateXML 
return xmltype 
as
  xml xmltype;
  b      NVARCHAR2(600);
begin
   b:= 'Select vac.Id, Company, can.Position,
				FName, SName, Age, Sex, Salary,SYSTIMESTAMP 
from VACANCY vac join CANDIDATE can on vac.Id = can.Job'  ;
        
  dbms_output.put_line(b);
        
  select xmlelement("XML",
      xmlelement(evalname('Tab'),
      dbms_xmlgen.getxmltype( b )))
  into xml
  from dual;
  return xml;
end CreateXML;

set SERVEROUTPUT ON
select (CreateXML).GETSTRINGVAL() from dual;

---------------------------------

--3
CREATE OR REPLACE PROCEDURE INSERTXML(
    id integer,
    x IN XMLTYPE)
IS
BEGIN
  INSERT INTO Report1 (id, xm) 
  VALUES (id, x);
  COMMIT;
END;

begin 
    INSERTXML(2, CreateXML);
end;

select * from Report1;
select r.xm.GETSTRINGVAL() from Report1 r;

--4
create index xml_index on Report1(extractvalue(xm,'/XML/Tab/ROWSET/ROW/ID[0]/text()')); 
  
--5
create or replace procedure FINDXML(word  in VARCHAR2, aa out VARCHAR2 ) 
is
begin
      select r.xm.GETSTRINGVAL() xml
      into aa from Report1 r
      where r.xm.EXISTSNODE('/XML/Tab/ROWSET/ROW[ID='''||word||''']')=1;
end FINDXML;
--------------------
DECLARE 
    word VARCHAR2(4000); 
BEGIN
  FINDXML('1', word);
  DBMS_OUTPUT.PUT_LINE( word );
END;

set SERVEROUTPUT ON

