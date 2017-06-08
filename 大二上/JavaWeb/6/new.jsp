<%@ page import="java.util.Enumeration" %>
<%@ page import="java.util.LinkedHashMap" %>
<%@ page import="java.util.Map" %>
<%@ page import="java.sql.*" %><%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/11/7
  Time: 20:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>new</title>
</head>
<body>
<form name="myForm2" action="newConfirm.jsp" method="post" onsubmit="return yznzheng()">
    <table>
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
            <td><input type="submit" value="添加"></td>
            <td><input type="reset" value="重置"></td>
        </tr>
    </table>
</form>
</body>
<script>
  function yznzheng() {
       if(document.getElementById("username").value.trim()=="")
       {
           alert("姓名不能为空！");
           document.getElementById("username").focus();
           return false;
       }
       else if(document.getElementById("link").value.trim()=="")
      {
          alert("link不能为空！");
          document.getElementById("link").focus();
          return false;
      }
       else if(document.getElementById("pwd").value.trim()=="")
       {
           alert("密码不能为空！");
           document.getElementById("pwd").focus();
           return false;
       }
       else if(document.getElementById("roles").value.trim()=="")
       {
           alert("roles不能为空！");
           document.getElementById("roles").focus();
           return false;
       }
       else if(document.getElementById("uid").value.trim()=="")
       {
           alert("学号不能为空！");
           document.getElementById("uid").focus();
           return false;
       }
  }
</script>
</html>
