import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * Created by xiuFeng on 2016/11/27.
 */
public class gbkFilter implements Filter {
    protected String encoding = null;

    public gbkFilter() {
        super();
    }

    public void init(FilterConfig filterConfig) throws ServletException {
        this.encoding = filterConfig.getInitParameter("encoding");  //获取web.xml设置的编码格式
    }

    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        try {
            //转换
            HttpServletRequest request = (HttpServletRequest) servletRequest;
            HttpServletResponse response = (HttpServletResponse) servletResponse;
            HttpSession session = request.getSession();
            if (encoding != null)
            {
                request.setCharacterEncoding(encoding);
                response.setCharacterEncoding(encoding);
            }
            //   servletResponse.setCharacterEncoding(encoding);
            filterChain.doFilter(request, response);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void destroy() {

    }
}
