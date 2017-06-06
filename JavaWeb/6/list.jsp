<%@ page import="com.mysql.jdbc.Connection" %>
<%@ page import="java.sql.*" %>
<%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/11/7
  Time: 16:31
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>list</title>
</head>
<style>
    td {
        text-align: center;
        vertical-align: middle;
    }
</style>
<body>
<form name="myForm" action="list.jsp" method="post">
    <table>
        <tr>
            <td><label for="id">id</label></td>
            <td><input type="text" name="id" id="id"></td>
        </tr>
        <tr>
            <td><label for="username">username</label></td>
            <td><input type="text" name="username" id="username"></td>
        </tr>
        <tr>
            <td><label for="link">link</label></td>
            <td><input type="text" name="link" id="link"></td>
        </tr>
        <tr>
            <td><label for="pwd">pwd</label></td>
            <td><input type="text" name="pwd" id="pwd"></td>
        </tr>
        <tr>
            <td><label for="roles">roles</label></td>
            <td><input type="text" name="roles" id="roles"></td>
        </tr>
        <tr>
            <td><label for="uid">uid</label></td>
            <td><input type="text" name="uid" id="uid"></td>
        </tr>
        <tr>
            <td></td>
            <td><input type="submit" value="查询"></td>
        </tr>
    </table>


</form>
<%
    request.setCharacterEncoding("utf-8");
    String param[] = new String[6];
    param[0] = request.getParameter("id");                //id
    param[1] = request.getParameter("username");   //username
    param[2] = request.getParameter("link");            //link
    param[3] = request.getParameter("pwd");              //pwd
    param[4] = request.getParameter("roles");          //roles
    param[5] = request.getParameter("uid");              //uid
    if (param[0] == null)
      for (int i=0;i<6;i++)
           param[i]="";
    try {
        Class.forName("com.mysql.jdbc.Driver");
        String url = "jdbc:mysql://localhost:3306/mydatebase?useUnicode=true&characterEncoding=utf-8";
        String user = "root";
        String pw = "123456";
        Connection connect = (Connection) DriverManager.getConnection(url, user, pw);
        String sql = "select *from student where id like? and username like? and link like? and pwd like? and roles like? and uid like? ";
        PreparedStatement preparedStatement = connect.prepareStatement(sql);
        for (int i = 0; i < param.length; i++)
            preparedStatement.setString(i + 1, "%" + param[i] + "%");
        ResultSet re = preparedStatement.executeQuery();
        out.println("<table border='1px' cellspacing='0' >");
        out.println("<tr><td>id</td><td>link</td><td>pwd</td><td>roles</td><td>uid</td><td>username</td></tr>");
        while (re.next())
            out.println("<tr><td>" + re.getInt("id") + "</td><td>" + re.getString("link") + "</td><td>" + re.getString("pwd") + "</td><td>" + re.getString("roles") + "</td><td>" + re.getString("uid") + "</td><td>" + re.getString("username") + "</td></tr>");
        out.println("</table>");
        re.close();
        preparedStatement.close();
        connect.close();
    } catch (Exception e) {
        e.printStackTrace();
    }


%>
<br>
<br>
<a href="new.jsp">增加学生</a>
</body>
</html>
