create database planeSale
create table plane(
id int primary key identity(1,1),
plane_id varchar(10) not null unique,
model varchar(20) not null,
seat int not null)
create table flight(
id int primary key identity(1,1),
flight_id  varchar(10) not null,
start_place varchar(10) not null,
end_place varchar(10) not null,
start_time datetime not null,
flight_time numeric not null)
create table tickets(
id int primary key identity(1,1),
tickets_id	varchar(10) not null unique,
flight_id  varchar(10) not null,
traveler_id	varchar(10) not null,
seating_list  varchar(10) not null unique,
cabin_rating varchar(10)  not null,
updata_time	timestamp not null,
ticket_status	int not null,  --0是未购买，1是已购买未使用，2是已过期未使用，3是成功使用
evaluate ntext null)
create table userAccount(
id int primary key identity(1,1),
user_type int not null,   --0是普通用户，1是管理员
account varchar(20) not null,
password varchar(20) not null default '123456',
identity_id varchar(20) not null
)
create table traveler(
id int primary key identity(1,1),
traveler_id varchar(10) not null unique,
name nvarchar(10) not null,
sex int not null, --0男,1女
id_card	varchar(20) not null unique,
phone varchar (11) not null,
email varchar(30) null)
create table bill(
id int primary key identity(1,1),
bill_id varchar(10) not null unique,
travel_id varchar(10) not null,
tickets_id varchar(10) not null,
payments float not null,
updata_time timestamp not null,
status int not null)   --0是未付，1是已付，3是特殊
create table activity(
id int primary key identity(1,1),
sponsor_id varchar(10) not null unique,
start_time datetime not null,
content ntext null,
summarize ntext null,
updata_time timestamp not null,
status int not null)   --0是还没开始，1是正在进行，2是已结束

