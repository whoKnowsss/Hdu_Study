<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="java.sql.Statement" %>
<%@ page import="java.sql.ResultSet" %><%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/11/8
  Time: 15:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>newConfirm</title>
</head>
<body>
<%
    request.setCharacterEncoding("utf-8");
    String username = request.getParameter("username");   //username
    String link = request.getParameter("link");            //link
    String pwd = request.getParameter("pwd");              //pwd
    String roles = request.getParameter("roles");          //roles
    String uid = request.getParameter("uid");              //uid
    if (username == null) {
        out.print("没有信息传输！");
    } else {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/mydatebase?useUnicode=true&characterEncoding=utf-8";
            String user = "root";
            String pw = "123456";
            Connection connect = (Connection) DriverManager.getConnection(url, user, pw);
            String sql = "insert into student values(null,'"+link+"','"+pwd+"','"+roles+"','"+uid+"','"+username+"')";
            Statement statement = connect.createStatement();
            int re = statement.executeUpdate(sql);
            if (re>0)
                out.println("新建学生成功!");
            else
                out.println("新建学生失败!");
            statement.close();
            connect.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
%>
<div id='mes'>5秒后返回list页面！</div>
</body>
<script>
    var sec = document.getElementById("mes");
    var i = 5;
    var timer = setInterval(function () {
        i--;
        sec.innerHTML = i + "秒后返回list页面！";
        if (i == 1) {
            location.href = "list.jsp";
        }
    }, 1000);
</script>
</html>
