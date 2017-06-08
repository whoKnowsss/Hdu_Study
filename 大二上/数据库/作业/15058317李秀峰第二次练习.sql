-- Lab3_3  
-- 1.0创建表格
use northwind
create table aaa(
 id int  identity (1,1) not null ,
 student_id char(8) not null primary key,
 name varchar(20) not null,
 sex char(2) not null default'男',
 age int null,
 institute nvarchar(10) not null default'计算机软件'
)
-- 1.1 15112003、张三、男
use northwind 
insert  aaa (student_id,name,sex)
values  ('15112003','张三',default)
go
-- 1.2 15112004、李四、女、21
insert aaa (student_id,name,sex,age)
values ('15112004','李四','女',21)
go
-- 1.3 15112005、王刚、男、20、会计
insert aaa (student_id,name,sex,age,institute)
values ('15112005','王刚',default,20,'会计')

-- 1.4 15112006、赵梅、女、20、计算机软件
insert into aaa
values('15112006','赵梅','女',20,default)

-- 1.5 15112007、李敏勇、男、计算机科学
insert into aaa (student_id,name,sex,institute)
values('15112007','李敏勇',default,'计算机科学')

-- 2.1 将学号15112005的同学的专业改为“外语”
update  aaa set institute='外语' where student_id='15112003'

-- 2.2  将王刚的年龄改为21
update  aaa set age=21 where name='王刚'

-- 3.1 将学号15112003的同学删除
delete from aaa where student_id='15112003'

-- 3.2 将“计算机软件”的同学删除
delete from aaa where institute='计算机软件'

-- 1．	查询customers表中的所有数据；
select * from customers

-- 2．	查询employees表中的雇员姓名（姓和名中间用空格分开）、雇用时间、地址（address）、邮编（postalcode），显示的列名用中文表示；
select  FirstName+' '+LastName as '姓名',HireDate as '雇用时间',address as '地址', postalcode as '邮编' from employees

-- 3．	查询products表中的供应商号(supplierID)；
select supplierID from products

-- 4．	查询products表中的供应商号(supplierID)，消除重复的行；
select distinct supplierID from products 

-- 5．	查询products表中的供应商号(supplierID)、产品类别号(categoryid)；
select supplierID,categoryid from products

-- 6．	查询products表中的供应商号(supplierID)、产品类别号(categoryid)，消除重复的行；
select distinct supplierID, categoryid from products

-- 7．	查询orders表中的订单号、客户号、雇员号、订单日期（orderdate）、供货日期（requiredDate），并按订单日期升序排列；
select orderid,customerid,employeeid,orderdate,requireddate from orders order by orderdate

-- 8．	查询products表中的产品名称、供应商号（supplierID）、产品单价（unitPrice）、库存量（unitsInStock），并按产品单价降序、库存升序排列;
select productname,supplierID,unitPrice,unitsInStock from products 
order by  unitPrice desc , unitsInStock asc

-- 9．	显示题8中查询结果的前10％.
select top 10 percent  productname,supplierID,unitPrice,unitsInStock from products 
order by  unitPrice desc , unitsInStock asc









-- Lab3_4  数据查询（二）

-- 1:查询全体学生的学号与姓名 
select sno,sname from student

-- 2:查询全体学生的姓名及年龄
select sname,sage from student

-- 3:查询全体学生的姓名, 年龄及所在系（用“系名”来表示列名）。
select sname,sage,Sdept as '系名'  from student

-- 4:查询选修了课程的学生学号
select distinct sno from sc

-- 1:查询计算机系全体学生的姓名
select sname from student where Sdept='cs'

-- 2:查询所有年龄在20岁以下的学生姓名及其年龄
select sname,sage from student where sage<20

-- 3:查询年龄在20到23间的学生的姓名,系别及年龄
select sname,ssex,sage from student where sage between 20 and 23

-- 4:查询年龄不在20到23间的学生的姓名,系别及年龄
select sname,ssex,sage from student where sage not between 20 and 23

-- 5:查询不是信息系(IS)和计算机系(CS)学生的姓名和性别
select sname,ssex from student where sdept!='IS' and sdept!='CS' 

-- 6:查询所有姓刘的学生的姓名,学号和性别
select sname,sno,ssex from student where sname like '刘%'

-- 7: 查询姓“李”且名为一个汉字的学生的姓名
select sname from student where sname like '李_'

-- 8:查询名字中第2个字为”敏”字的学生姓名和学号
select sname,sno from student where sname like '_敏%'

-- 9:查询所有不姓刘的学生姓名
select sname from student where sname not like '刘%'

-- 10:查询全体学生情况,结果按所在系的号升序排列,同一系中的学生按年龄降序
select * from student order by sdept asc,sage desc

-- 1:查询学生的总人数
select count(*) as '总人数' from student

-- 2:查询选修了课程的学生人数
select count(*)  as '人数'from (select distinct sno from sc  ) a

-- 3:计算选2号课程的学生平均成绩
select avg(grade)  as '平均成绩' from (select grade from sc  where cno =2) a

-- 4:查询选修3号课程的学生最高分数
select max(grade)  as '最高分' from (select grade from sc  where cno =3) a

-- 5:求各个课程号及相应的选课人数
select cno  as '课程号',count(*) as '选修人数' from sc group by cno

-- 6:查询选修了2门以上的课程的学生学号
select sno as '学号' from(select sno,count(*) as 'num' from sc group by sno) a where num>2 

-- 1、	查询选修了2门课程（含2门）的学生的学号和平均成绩，并根据平均成绩降序排列。
select sno,平均成绩 from (select sno,avg(grade) as '平均成绩',count(*) as 'num' from sc group by sno) a where num>=2 order by 平均成绩 desc

-- 2、	查询各学分等级的课程数目
select credit, count(*) as '该学分对应的课程数目' from course group by credit

-- 3、	查询18岁以上（含18）的男女生的人数
select ssex, count(*) as '人数' from student where sage>=18 group by ssex

-- 4、	查询人数多于2人（含2人）的系的编号及人数
select * from(select sdept, count(*) as '人数' from student group by sdept) a where 人数>=2

