package testOpencv;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Scalar;

/**
 * Servlet implementation class testOpencv
 */
@WebServlet("/testOpencv")
public class testOpencv extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public testOpencv() {
    	
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
		response.getWriter().println("Hello OpenCV " + Core.VERSION);
		response.getWriter().println("NATIVE_LIBRARY_NAME:" + Core.NATIVE_LIBRARY_NAME);
        Mat m1  = Mat.zeros(1, 3, CvType.CV_8UC1);
        Mat m2  = Mat.zeros(1, 3, CvType.CV_8UC3);

        Mat m3  = Mat.ones(5, 5,CvType.CV_8UC1);
        Mat m6  = Mat.ones(5, 5,CvType.CV_8UC3);
       
        Mat m7  = Mat.eye(3, 3, CvType.CV_8UC1);
        Mat m8  = Mat.eye(3, 3, CvType.CV_8UC3);
        Mat m9  = new Mat(5, 10, CvType.CV_8UC1,new Scalar(0));
        
        response.getWriter().println("m1 = " + m1.dump());
        response.getWriter().println("m2 = " + m2.dump());
        response.getWriter().println("m3 = " + m3.dump());
        response.getWriter().println("m7 = " + m7.dump());
        response.getWriter().println("m8 = " + m8.dump());
        response.getWriter().println("m9 = " + m8.dump());
        
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	}

}
