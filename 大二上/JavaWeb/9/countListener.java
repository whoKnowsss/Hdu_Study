import javax.servlet.ServletContext;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

/**
 * Created by xiuFeng on 2016/11/27.
 */
public class countListener implements HttpSessionListener {

    private static int count = 0;

    public void sessionCreated(HttpSessionEvent httpSessionEvent) {
        count++;
        ServletContext application = httpSessionEvent.getSession().getServletContext();
        application.setAttribute("count", count);
    }

    public void sessionDestroyed(HttpSessionEvent httpSessionEvent) {
        count--;
        ServletContext application = httpSessionEvent.getSession().getServletContext();
        application.setAttribute("count", count);
    }
}
