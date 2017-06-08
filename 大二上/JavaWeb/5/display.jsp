<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.Set" %>
<%@ page import="java.util.Iterator" %>
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
    <title>购物车</title>
</head>
<body>
<h3>你选择的结果是：</h3>
<%
    Set<String> getN = (Set<String>) session.getAttribute("list");
    if (getN != null)
        for (Iterator it = getN.iterator(); it.hasNext(); )
            out.print(it.next().toString() + "<br>");

%>

</body>
</html>
