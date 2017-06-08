<%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/10/30
  Time: 13:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>球</title>
</head>
<body>
<h5>各种球大甩卖，一律八块：</h5>
<form name="buyBall" id="buyBall" action="data.jsp" method="post">
    <input type="checkbox" name="data" value="篮球">篮球<br>
    <input type="checkbox" name="data" value="足球">足球<br>
    <input type="checkbox" name="data" value="排球">排球<br>
    <input type="submit" value="提交"><input type="reset" value="全部重写">
    <a href="buy2.jsp">买点别的</a>&nbsp;&nbsp;<a href="display.jsp">查看购物车</a>
</form>
</body>
</html>
