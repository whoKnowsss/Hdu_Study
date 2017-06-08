<%@ page import="java.util.*" %><%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/10/27
  Time: 20:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>post</title>
</head>
<body>
<%
    Map map = new LinkedHashMap();
    request.setCharacterEncoding("UTF-8");
    Enumeration paramNames = request.getParameterNames();
    while (paramNames.hasMoreElements()) {
        String paramName = (String) paramNames.nextElement();
        String[] paramValues = request.getParameterValues(paramName);
        if (paramValues.length == 1) {
            String paramValue = paramValues[0];
            if (paramValue.length() != 0) {
                map.put(paramName, paramValue);
            }
        }
    }
    Set<Map.Entry<String, String>> set = map.entrySet();
    out.print("<table>");
    for (Map.Entry entry : set) {
        out.print("<tr><td>"+entry.getKey() +"</td>"+  "<td>"+entry.getValue()+"</td><tr>");
    }
    out.print("</table>");
%>

</body>
</html>
