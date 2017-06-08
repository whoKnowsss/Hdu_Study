-- Lab3_6  数据查询（四）

-- 1、查询参加了三次以上的学生姓名
select sname from student where sno in(select sno from sc group by sno having count(*)>=3)
select sname from sc left join student on sc.sno=student.sno group by sname having count(sname)>=3

-- 2、查询平均分大于88的学生姓名
select sname from student where sno in(select sno from sc group by sno having avg(grade)>88)
select sname from sc left join student on sc.sno=student.sno group by sname having avg(grade)>88

-- 3、查询在2007年4月22日参加过考试的学生姓名
select sname from student where sno in(select sno from sc group by sno,testtime having testtime='2007-4-22')
select sname from sc left join student on sc.sno=student.sno group by sname,testtime having testtime='2007-4-22'


-- *4、查询参加过考试的每个学生考的最好的那次考试的情况，显示sno,cno,grade
select sno,cno,grade from sc s1 where grade=(select max(grade) from sc s2 where s1.sno=s2.sno)


-- Lab3-7 视图

-- 1)	建立先修课程(cpno)为空的课程视图
create view v_course as select * from course where cpno=null

-- 2)	建立成绩高于90分的女生成绩视图（包括学号，姓名，课程号及成绩列）
create view v_girlGrade(sno,sname,cno,grade) as select student.sno,sname,sc.cno,grade from student,sc where (student.sno=sc.sno and sc.grade>90 and student.ssex='女')

--3)	建立视图S_AVGAGE（其中包括性别SSEX与平均年龄AVG_AGE两列）用以反映男生、女生的平均年龄
create view S_AVGAGE(ssex,AVG_AGE) as select ssex,avg(sage) from student group by ssex

-- 2.对前面创建的视图S_AVGAGE执行更新操作：
-- UPDATE S_AVGAGE
-- SET AVG_AGE = 85
-- WHERE  ssex = '女'
-- 上述语句能否成功执行？为什么？
不能，对视图‘S_AVGAGE’的更新失败，因其包含派生域，AVG_AGE是avg函数出来的，无法修改

-- ①用查询分析器，创建一个显示Northwind的Employees表中lastname,firstname,city三个字段的视图EmployeeView。
create view EmployeeView(lastname,firstname,city) as select lastname,firstname,city from Employees

-- ②在查询分析器中执行： select * from EmployeeView。

-- ③在查询分析器中查看该视图的定义内容。
sp_help EmployeeView

-- ①把上面创建的视图加密
alter view EmployeeView with encryption as select lastname,firstname,city from Employees

-- ②在查询分析器中查看该视图的文本内容。
sp_helptext EmployeeView

-- ②向视图插入一行数据  315-41-6425、Jackson、Mike、1、315-41-6425、BU1032、1、150：
insert into au_title(author_au_id,au_lname,au_fname,contract) values ('315-41-6425'，'Jackson'，'Mike'，1)
insert into au_title(author_au_id,title_id,au_ord,royaltyper) values ('315-41-6425'，'BU1032'，1，150)

-- ③通过视图更改数据：
-- 将au_id为315-41-6425的au_lname改为Tom
update au_title set au_lname ='Tom' where author_au_id='315-41-6425'

