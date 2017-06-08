<%--
  Created by IntelliJ IDEA.
  User: xiuFeng
  Date: 2016/10/27
  Time: 19:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>用户注册</title>
</head>
<body>
<form id="myForm" action="post.jsp" method="post" onsubmit="return  yanzheng()">
    <table>
        <tr>
            <td><label for="name">用户名</label></td>
            <td><input type="text" name="用户名" id="name"></td>
        </tr>
        <tr>
            <td><label for="p1">密码</label></td>
            <td><input type="password" name="密码" id="p1"></td>
        </tr>
        <tr>
            <td><label for="p2">确认密码</label></td>
            <td><input type="password" name="确认密码" id="p2"></td>
        </tr>
        <tr>
            <td><label for="city">籍贯</label></td>
            <td><select id="city" name="籍贯">
                <option>北京</option>
                <option selected>杭州</option>
                <option>上海</option>
            </select></td>
        </tr>
        <tr>
            <td><label>出生年月</label></td>
            <td><select id="year" name="年">
                <%
                    for (int i = 0; i <= 30; i++)
                        out.print(" <option>" + (1990 + i) + "</option>");
                %>
            </select>
                <select id="month" name="月">
                    <%
                        for (int i = 1; i <= 12; i++)
                            out.print(" <option>" + i + "</option>");
                    %>
                </select>
                <select id="day" name="日">
                    <%
                        for (int i = 1; i <= 31; i++)
                            out.print(" <option>" + i + "</option>");
                    %>
                </select></td>
        </tr>
        <tr>
            <td><label>性别</label></td>
            <td><input type="radio" name="性别" value="男">男
                <input type="radio" name="性别" value="女">女
            </td>
        </tr>
        <tr>
            <td><label for="hobby">爱好</label></td>
            <td><input type="text" name="爱好" id="hobby"></td>
        </tr>

        <tr>
            <td><label for="height">身高</label></td>
            <td><input type="text" placeholder="如：170" name="身高" id="height" style="width:60px;">cm</td>
        </tr>
        <tr>
            <td><label for="email">邮箱</label></td>
            <td><input type="text" name="邮箱" id="email"></td>
        </tr>
        <tr>
            <td><label for="phone">手机</label></td>
            <td><input type="text" name="手机" id="phone"></td>
        </tr>
        <tr>
            <td><label for="jieshao">个人介绍</label></td>
            <td><textarea id="jieshao" name="个人介绍"></textarea></td>
        </tr>

        <tr>
            <td><input type="submit" value="确认"></td>
            <td><input type="reset" value="重置"></td>
        </tr>


    </table>
</form>
</body>
<script language="JavaScript">
    function yanzheng() {
        var regNameStrSe = /^\w{6,10}$/;
        var regNameStrFirst = /^[a-z|A-Z].*$/;
        var regEmailStr = /^\w+@\w+.\w+$/;
        var regPhoneStr1 = /^\d*$/;
        var regPhoneStr2 = /^\d{11}$/;
        var regHeightStr = /^\d{3}$/;
        var email = document.getElementById("email").value;
        var name = document.getElementById("name").value;
        var p1 = document.getElementById("p1").value;
        var p2 = document.getElementById("p2").value;
        var height = document.getElementById("height").value;
        var phone = document.getElementById("phone").value;
        var intro = document.getElementById("jieshao").value;
        var hobby = document.getElementById("hobby").value;
        var checked1 = false;                          //性别检测
        var ras = document.getElementsByName("性别");
        for (var a = 0; a < ras.length; a++)
            checked1 = checked1 || ras[a].checked;
        if (name.trim() == "") {
            alert("名称不能为空！");
            return false;
        }
        else if (!regNameStrFirst.test(name)) {
            alert("用户名得用字母开头！");
            return false;
        }
        else if (!regNameStrSe.test(name)) {
            alert("用户名长度在6到10位！");
            return false;
        }
        else if (p1.trim() == "") {
            alert("请输入密码");
            return false;
        }
        else if (p2.trim() == "") {
            alert("请输入确认密码");
            return false;
        }
        else if (p1 != p2) {
            alert("密码和确认密码不一样！");
            return false;
        }
        else if (!checked1) {
            alert("请选择性别！");
            return false;
        }
        else if (hobby.trim() == "") {
            alert("请输入爱好！");
            return false;
        }
        else if (height.trim() == "") {
            alert("身高不能为空！");
            return false;
        }
        else if (!regHeightStr.test(height)) {
            alert("身高为纯数字，如“170”！");
            return false;
        }
        else if (email.trim() == "") {
            alert("邮箱不能为空！");
            return false;
        }
        else if (!regEmailStr.test(email)) {
            alert("邮箱格式错误");
            return false;
        }
        else if (phone.trim() == "") {
            alert("请输入手机号！");
            return false;
        }
        else if (!regPhoneStr1.test(phone)) {
            alert("手机号格式错误，为纯数字");
            return false;
        }
        else if (!regPhoneStr2.test(phone)) {
            alert("手机号位数错误，为11位");
            return false;
        }
        else if (intro.trim() == "") {
            alert("请输入个人介绍！");
            return false;
        }
    }
</script>
</html>
