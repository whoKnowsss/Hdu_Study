<%@ page import="java.util.*" %><%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/10/30
  Time: 13:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>

</head>
<body>
<%
    request.setCharacterEncoding("UTF-8");
    String post[] =request.getParameterValues("data");               //post传过来的东西
    Set<String> now =(Set<String>) session.getAttribute("list");  //现在session里的东西
    Set<String> set = new HashSet<String>();
    if(post!=null)
     Collections.addAll(set, post);
   if(now!=null)
      set.addAll(now);
    session.setAttribute("list",set);
%>

</body>
<script language="JavaScript">
    history.go(-1);
</script>
</html>
