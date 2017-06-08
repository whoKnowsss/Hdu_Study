-- Lab3_5

-- 练习一：
-- 1、	修改表sc，增加一个列scid，数据类型为int，不可为空，且此列为标识列，种子=1，增量=1。
alter table sc add scid int not null identity(1,1)

-- 2、	删除表sc上的主键pk_sc
alter table sc drop pk_sc  

-- 3、	在表sc上增加列scid为主键
alter table sc add  primary key (scid)

-- 4、	修改表sc，增加一个考试时间列testtime，数据类型为datetime，可以为空。
alter table sc add  testtime datetime null

-- 7、	查询选修“信息系统”课程的学生的学号
select sno from sc,course where (sc.cno=course.cno) and (cname='信息系统')

-- 8、	查询学生“李敏勇”的平均分
select avg(grade) from student  join sc on student.sno=sc.sno  where sname='李敏勇'

-- 9、	查询选修“数学”课程的平均分
select avg(grade) from sc  join course on course.cno=sc.cno  where cname='数学'

-- 10、	查询学生“李敏勇”，成绩大于80分的课程号、成绩
select grade,cno from sc  join student on student.sno=sc.sno  where sname='李敏勇' and grade>80

-- 11、	查询至少有一门课程成绩大于90分的学生的姓名
select distinct sname from student join sc on student.sno=sc.sno where grade>90

-- 12、	查询没有一门考试科目成绩低于85分的学生的姓名
select  distinct sname from student join sc on student.sno=sc.sno where student.sno!=all(select sc.sno from sc where grade<85)

-- 13、查询所有学生的成绩情况，显示的列名包括学生姓名、课程号、考试时间、成绩，注意结果集中也应包括未选修课程的学生。
select sname,cno,testtime,grade from student left join sc on student.sno=sc.sno 

-- 14、查询所有课程的成绩情况，显示的列名包括学生课程名称、学生学号、考试时间、成绩，注意结果集中也应包括未考试的课程。
select cname,sno,testtime,grade from course left join sc on course.cno=sc.cno 

-- 15、查询学生选修课程的考试情况，显示的列名包括学生姓名、课程名称、考试时间、成绩
select  sname,cname,testtime,grade from (select sno,cname,testtime,grade from sc join  course on sc.cno=course.cno)a join student on a.sno=student.sno

-- 16、查询所在系相同的学生，显示的列名包括学生姓名、系名、相同系的学生姓名，剔除自己跟自己系相同的情况。
select a.sname,a.sdept,b.sname from student a  join student b on a.sdept=b.sdept where a.sno<b.sno

-- 17、查询学分相同的课程，显示的列名包括课程名称、学分、相同学分的另一课程名称
select a.cname,a.credit,b.cname from course a join course b on a.credit=b.credit where a.cno<b.cno


-- 二、使用pubs数据库
-- 1、	查找出版过书籍的出版商名及其出版的书籍名称
select b.pub_name,a.title from titles a join publishers b on a.pub_id=b.pub_id 

-- 2、	查找所有出版商及其出版的书籍名，按出版商姓名排序
select b.pub_name,a.title from publishers b left join titles a on a.pub_id=b.pub_id  order by b.pub_name 

-- 3、查找所有书籍的名称及其出版商名 
select b.pub_name,a.title from titles a join publishers b on a.pub_id=b.pub_id

-- 4、查询所有书籍的作者（如果一本书有多个作者，请都列出来）
select title,au_lname from titles a left join titleauthor b on a.title_id=b.title_id left join authors d on b.au_id=d.au_id

-- 5、查询具有作者和出版商的书籍的名称，及其该书的作者人数和该书的出版商。
select title,count(title) author_count,b.pub_name from titles a join publishers b on a.pub_id=b.pub_id join titleauthor c on a.title_id=c.title_id group by title,b.pub_name

-- 6、查询所有书籍的作者人数、出版商姓名及书籍名称。
select a.title,count(c.au_id) author_count,b.pub_name from titles a left join titleauthor c on a.title_id=c.title_id left join publishers b on b.pub_id=a.pub_id group by title,b.pub_name

-- 1、	查询Employees表中，每一位员工的领导，需要显示员工名和领导名（提示：“员工的领导”为字段reprotTo）（提示：使用自联接）
select b.lastname+' '+b.firstname EmplyoeeName,a.lastname+' '+a.firstname LeaderName from Employees a join Employees b on a.EmployeeID=b.ReportsTo

-- 2、	查询属于同一种类categoryID的产品(products、categories表)。（共77条记录）
select b.CategoryName 种类,a.ProductName 产品 from products a join categories b on a.CategoryID=b.CategoryID

-- 3.查询每一种类的产品个数(products、categories表)
select b.CategoryName 种类,count(b.CategoryID) 产品个数 from Products a join Categories b on a.CategoryID=b.CategoryID group by a.CategoryID,b.CategoryName

-- 4.查询所有供应商供应的产品的个数及平均价格，并按平均价格降序排列（suppliers、products表）（共29条记录）
select distinct a.CompanyName 供应商,count(*) 个数,avg(b.UnitPrice) 平均价格 from Suppliers a left join Products b on a.SupplierID=b.SupplierID group by a.SupplierID,a.CompanyName order by 平均价格 desc

-- 5.查询‘1998-2-18’下订单的客户名及订购了几种产品（orders、order details、customers、products表）
select c.companyname 客户名,count(p.productname) 产品种类 from orders o join [order details] od on o.orderid=od.orderid join customers c on o.customerid=c.customerid join products p on od.productid=p.productid where o.orderdate='1998-2-18' group by c.companyname

--6.查询‘Around the Horn’客户购买的产品的名称及购买时间（orders、order details、products表）（30条记录）
select c.productname,a.orderdate from orders a join [order details] od on a.orderid=od.orderid  join customers b on a.customerid=b.customerid join products c on od.productid=c.productid where b.companyname='Around the Horn'

--7.查询订购'22'号产品的客户及其订购的数量，并按数量降序排序（customers、order details、orders表）
select a.companyname 客户名,od.quantity 订购数量 from customers a join orders b on b.customerid=a.customerid join [order details] od on b.orderid=od.orderid  where od.productid='22' order by 订购数量 desc

--8.查询所有客户订购的产品类别个数及产品数量（customers、orders、order details、products表）（91条记录）
select a.companyname,count(c.categoryid) 产品类别个数,sum(od.quantity) 产品数量 from customers a left join orders b on b.customerid=a.customerid left join [order details] od on b.orderid=od.orderid  left join products c on od.productid=c.productid group by a.companyname order by 产品数量

--9.查询被客户订购数量最多的前10种产品的名称及订购数量（包括并列项）（products、order details表）
select top 10 with ties a.productname,sum(od.quantity) 订购数量 from [order details] od join products a on od.productid=a.productid group by a.productname order by 订购数量 desc

--10.查询都住在‘美国’的雇员和客户(Employees、Customers表)（18条记录）
select a.lastname+' '+a.firstname 美国的雇员和客户 from employees a where a.country='USA' union select b.companyname from customers b where b.country='USA'

















