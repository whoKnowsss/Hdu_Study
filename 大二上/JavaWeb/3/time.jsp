<%@ page import="java.util.Date" %>
<%@ page import="java.text.SimpleDateFormat" %><%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/10/24
  Time: 8:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>time</title>
</head>
<body>
<%
    Date now = new Date();
    SimpleDateFormat sdf = new SimpleDateFormat("H:m:ss");
    out.print("服务端时间为" + sdf.format(now)+"<br>");
%>
</body>
<script language="JavaScript">

    var date = new Date();
    var hou = date.getHours();
    var min = date.getMinutes();
    var se = date.getSeconds();
    document.write("客户端时间为" + hou + ":" + min + ":" + se);

</script>
</html>
