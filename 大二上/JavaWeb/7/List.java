import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 * Created by xiuFeng on 2016/11/15.
 */
public class List extends HttpServlet {
    public List() {
        super();
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        resp.setCharacterEncoding("utf-8");
        PrintWriter out = resp.getWriter();
        try {
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/mydatebase?useUnicode=true&characterEncoding=utf-8";
            String user = "root";
            String pw = "123456";
            Connection connect = (Connection) DriverManager.getConnection(url, user, pw);
            String sql = "select *from student";
            Statement statement = connect.createStatement();
            ResultSet re = statement.executeQuery(sql);
            out.println("<table border='1px' cellspacing='0' >");
            out.println("<tr><td>id</td><td>link</td><td>pwd</td><td>roles</td><td>uid</td><td>username</td></tr>");
            while (re.next())
                out.println("<tr><td>" + re.getInt("id") + "</td><td>" + re.getString("link") + "</td><td>" + re.getString("pwd") + "</td><td>" + re.getString("roles") + "</td><td>" + re.getString("uid") + "</td><td>" + re.getString("username") + "</td></tr>");
            out.println("</table>");
            re.close();
            statement.close();
            connect.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.println("<br><br><a href='new.jsp'>增加学生</a>");
        out.flush();
        out.close();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }

    @Override
    public void destroy() {
        super.destroy();
    }
}
