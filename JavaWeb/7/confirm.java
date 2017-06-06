import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

/**
 * Created by xiuFeng on 2016/11/15.
 */
public class confirm extends HttpServlet {
    public confirm() {
        super();
    }

    @Override
    public void destroy() {
        super.destroy();
    }

    private void doGoBack(HttpServletRequest req, HttpServletResponse resp,PrintWriter out) throws ServletException, IOException {
        out.println("<div id='mes'>5秒后返回list页面！</div>" +
                "<script>" +
                "var sec = document.getElementById('mes');" +
                "    var i = 5;" +
                "    var timer = setInterval(function () {" +
                "        i--;" +
                "        sec.innerHTML = i + '秒后返回list页面！';" +
                "        if (i == 1) {" +
                "            location.href = 'list';" +
                "        }" +
                "    }, 1000);" +
                "</script>");
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setCharacterEncoding("utf-8");
        PrintWriter out = resp.getWriter();
        out.print("没有信息传输！");
        this.doGoBack(req, resp,out);
        out.flush();
        out.close();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setCharacterEncoding("utf-8");
        req.setCharacterEncoding("utf-8");
        PrintWriter out = resp.getWriter();
        String username = req.getParameter("username");   //username
        String link = req.getParameter("link");            //link
        String pwd = req.getParameter("pwd");              //pwd
        String roles = req.getParameter("roles");          //roles
        String uid = req.getParameter("uid");              //uid
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
        this.doGoBack(req, resp,out);
        out.flush();
        out.close();
    }
}
