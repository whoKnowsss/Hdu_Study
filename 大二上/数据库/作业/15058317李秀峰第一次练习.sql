
/*****************3.1*****************/

-- 练习2: 在SQL查询分析器中用Transact-SQL 语句修改数据库
ALTER DATABASE ClassNorthwind
remove file(
  name='ClassNorthwind_Data2',
  filename='d:\ClassNorthwind_Data2.ndf',
  size=30mb
)

-- 1.	为了显示SQL Server实例中的全部数据库，用户应当在查询窗口输入并执行下述系统存储过程： 
exec sp_helpdb

-- 2.	为了显示ClassNorthwind数据库的信息，用户应当在查询窗口输入并执行下述系统存储过程：
exec sp_helpdb newbak


-- 1.	编写和执行将ClassNorthwind事务日志文件的最大长度增加到50 MB的语句.
ALTER DATABASE ClassNorthwind
modify file (
   name='ClassNorthwind_log',
   maxsize=50mb
)

-- 2.	编写和执行将ClassNorthwind 辅助数据文件收缩到10MB的语句.
DBCC SHRINKFILE('ClassNorthwind_Data2',10)



/*********************3.2***********************/

--创建test表 
use mydb1
create table test
(
test_id int  primary key,
test_name varchar(20) ,
teacher_id int not null,
)
 
 --创建test_score表   
use mydb1
create table test_score
(
student_id int not null,
test_id int not null,
score int ,
)
  
--1.	将student表中的student_id的数据类型修改为int型；
use mydb1
alter table student drop constraint PK__student
alter table student alter column student_id int not null 
alter table student add  primary key(student_id)

--2.	在student表中添加字段phone，类型是varchar，长度是50；
use mydb1
alter table student add phone varchar(50)

-- 3.	在teacher表中将name的长度修改为30；
use mydb1
alter table student	alter column name varchar(30)	

-- 4.	在student表中添加专业列institute，最长是10个汉字，不允许为空，默认值为“计算机软件”；
use mydb1
alter table student	
add institute varchar(20) not null default'计算机软件'

-- 5.	修改Student表中列sex上的默认值为‘女’；
use mydb1
alter table student	drop constraint DF__student__sex
alter table student add constraint DF__student__sex default '女' for sex

-- 6.	在teacher表中对age列添加约束，年龄在18-60之间；
use mydb1
alter table teacher
add constraint age_check check (age between 18 and 60)

-- 7.	在teacher表中添加约束，工作时间必须大于生日；
use mydb1
alter table teacher
add constraint c1 check (workdate>birthdate)

-- 8.	将test_score表中的student_id和test_id设置为“主键”；
use mydb1
alter table test_score
add constraint p1 primary key(student_id,test_id)

-- 9.	将test_score表中的score设置检查约束，成绩值在0-100之间；
use mydb1
alter table test_score
add constraint c2 check(score>=0 and score<=100)

-- 10.	设置外键：test表中的teacher_id参照teacher表中的teacher_id；
use mydb1
alter table test
add constraint f1 foreign key(teacher_id) references teacher(teacher_id)

-- 11.	设置外键：test_score表中的student_id参照student表中的student_id，test_id参照test表中的test_id。
use mydb1
alter table test_score add constraint f2 foreign key(student_id) references student(student_id)
alter table test_score add constraint f3 foreign key(test_id) references test(test_id)