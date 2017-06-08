<%@page import="java.text.SimpleDateFormat"%>
<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<html>
 <head>
  <title>显示时间</title>
 </head>
 <%
  Date date = new Date();
  int hour = new Date().getHours();
  Calendar cal=Calendar.getInstance();
  String dayOfWeekTime="";
  String m="";
  
  int dayOfWeek=cal.get(Calendar.DAY_OF_WEEK);
  switch(dayOfWeek){
   case 1:dayOfWeekTime="星期天";break;
   case 2:dayOfWeekTime="星期一";break;
   case 3:dayOfWeekTime="星期二";break;
   case 4:dayOfWeekTime="星期三";break;
   case 5:dayOfWeekTime="星期四";break;
   case 6:dayOfWeekTime="星期五";break;
   case 7:dayOfWeekTime="星期六";break;
  }
  SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
  String timeString = sdf.format(date);

  if(hour>=0 && hour<=12)
   m="上午";
else
   m="下午";
%>
 <body>
  <h1>
   今天是：<%=dayOfWeekTime %> <%=m%> <%=timeString%>
  </h1>
 </body>
</html>