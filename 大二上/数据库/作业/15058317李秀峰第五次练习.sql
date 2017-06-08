-- Lab7 ：存储过程


--一、创建如下的简单存储过程：
--1、用于获得成绩小于60或大于90分的学生的学号、姓名和课程名称
create proc pro_stu1
as
begin
select a.sno,sname,cname from student a join sc b on a.sno=b.sno
join course c on b.cno=c.cno
where grade>60 and grade<90
end 
--2、用于获得成绩在60至80分之间的学生的学号和课程号
create proc pro_stu2
as
begin
select sno,a.cno from sc join course a on sc.cno=a.cno
where grade between 60 and 80
end
--3、用于获得选修3号课程的学生最高分数
create proc pro_stu3
as
begin
select max(grade) 最高分数 from sc
where cno='3'
end
--4、用于获得选修了2门课程（含2门）的学生的学号和平均成绩，并根据平均成绩降序排列。
create proc pro_stu4
as
begin
select sno,avg(grade) 平均分 from sc
group by sno
having count(cno)>=2
order by avg(grade) desc
end

--二、创建如下的带输入参数的存储过程：
--1、根据用户输入的学号，获得课程号、课程名和成绩；
create proc pro_stu5
@Sno int
as
begin
select course.cno,cname,grade from sc join course on sc.cno=course.cno
where sno=@Sno
end

--2、根据用户输入的学号，删除“学生成绩”表中的记录；
create proc pro_stu6
@Sno int
as 
begin
delete from sc 
where sno=@Sno
end

--3、把用户输入的学生学号、姓名、性别、年龄、系名等信息，插入到学生表中
create proc pro_stu7
@Sno int,@sname varchar(20),@sex nvarchar(1),@age tinyint,@dept varchar(40)
as
begin 
insert into student values(@Sno,@sname,@sex,@age,@dept)
end
g
--4、根据用户输入的学号，计算这个学生的平均分；如果平均分大于等于90分，则输出字符串“平均分大于等于90分”，如果平均分小于90分，则输出字符串“平均分小于90分”
create proc pro_stu8
@Sno int
as
begin
declare @avg decimal(10,2)
select @avg=avg(grade) from sc
where sno=@Sno
if @avg>=90 
begin 
print '平均分大于等于90分'
end
if @avg<90  
begin
print '平均分小于90分'
end
end

--5、根据用户输入的学号，查询此学生所属的系，如果是计算机系（即系名列的值为’CS’），则给他参加的每次考试成绩加5分，如果是其他系，则给他参加的每次考试成绩加2分
create proc pro_stu9
@Sno int
as
begin
declare @Sdept varchar(40)
select @Sdept=sdept from student
where sno=@Sno
if @Sdept='cs'
update sc 
set grade=grade+5 where sno=@Sno
else
update sc
set grade=grade+2 where sno=@Sno
end

--三、语法练习（选做）
--按照国家和性别进行分组，得出结果如下 
SELECT country,        
       SUM( CASE WHEN sex = '1' THEN        
                      Population END)as 男,  --男性人口       
       SUM( CASE WHEN sex = '2' THEN        
                      Population END)as 女  --女性人口          
FROM  tableA        
GROUP BY country 