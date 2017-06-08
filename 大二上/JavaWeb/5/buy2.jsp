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
    <title>肉</title>
</head>
<body>
<h5>各种肉大甩卖，一律十块：</h5>
<form name="buyMeet" id="buyMeet" action="data.jsp" method="post">
    <input type="checkbox" name="data" value="猪肉">猪肉<br>
    <input type="checkbox" name="data" value="牛肉">牛肉<br>
    <input type="checkbox" name="data" value="羊肉">羊肉<br>
    <input type="submit" value="提交"><input type="reset" value="全部重写">
    <a href="buy1.jsp">买点别的</a>&nbsp;&nbsp;<a href="display.jsp">查看购物车</a>
</form>
</body>
</html>
