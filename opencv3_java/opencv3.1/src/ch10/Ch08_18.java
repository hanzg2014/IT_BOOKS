package ch10;

import java.util.ArrayList;
import java.util.List;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfInt;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;
import org.opencv.imgproc.Moments;

   public class Ch08_18 {
      public static void main( String[] args )
      {
         try{
            System.loadLibrary( Core.NATIVE_LIBRARY_NAME );
            Mat source = Imgcodecs.imread("C://opencv3.1//samples//IloveOpencv.jpg",
            		Imgcodecs.CV_LOAD_IMAGE_GRAYSCALE);
            Mat target = Imgcodecs.imread("C://opencv3.1//samples//IloveOpencv-s.jpg",
            		Imgcodecs.CV_LOAD_IMAGE_GRAYSCALE);
            
            List<MatOfPoint> src_contours = new ArrayList<MatOfPoint>();
            List<MatOfPoint> trg_contours = new ArrayList<MatOfPoint>();
            Mat src_hierarchy = new Mat(source.rows(),source.cols(),CvType.CV_8UC1,new Scalar(0));
            Mat trg_hierarchy = new Mat(target.rows(),target.cols(),CvType.CV_8UC1,new Scalar(0));
            
            Imgproc.findContours(source, src_contours, src_hierarchy, Imgproc.RETR_TREE,Imgproc.CHAIN_APPROX_SIMPLE);
            Imgproc.findContours(target, trg_contours, trg_hierarchy, Imgproc.RETR_TREE,Imgproc.CHAIN_APPROX_SIMPLE);
           Moments  moments=new  Moments(); 
           Mat test=trg_contours.get(0);
           System.out.println(test.dump());//¦³¸ê®Æ
           moments=Imgproc.moments(trg_contours.get(0),false);
           System.out.println("moments.get_m00()="+moments.get_m00());//0
           System.out.println("moments.get_m01()="+moments.get_m01());
           System.out.println("moments.get_m02()="+moments.get_m02());
           System.out.println("moments.get_m03()="+moments.get_m03());
            Mat Hu=new Mat();
           Imgproc.HuMoments(moments, Hu);
            //double result=Imgproc.matchShapes(source, target, 1,0);
            System.out.println("result= " + Hu.dump());//0
            System.out.println("CV_CONTOURS_MATCH_I1= " + Imgproc.CV_CONTOURS_MATCH_I1);
            System.out.println("CV_CONTOURS_MATCH_I2= " + Imgproc.CV_CONTOURS_MATCH_I2);
            System.out.println("CV_CONTOURS_MATCH_I3= " + Imgproc.CV_CONTOURS_MATCH_I3);
           }catch (Exception e) {
              System.out.println("error: " + e.getMessage());
           }
   }
}