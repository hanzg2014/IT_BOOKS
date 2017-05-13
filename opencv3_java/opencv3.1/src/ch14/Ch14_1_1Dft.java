package ch14;

import java.util.ArrayList;
import java.util.List;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Rect;
import org.opencv.core.Scalar;
import org.opencv.imgcodecs.Imgcodecs;

   public class Ch14_1_1Dft {
		static{ System.loadLibrary(Core.NATIVE_LIBRARY_NAME); }
      public static void main( String[] args )
      {
         try{
            Mat source = Imgcodecs.imread("C://opencv3.1//samples//lena.jpg",Imgcodecs.CV_LOAD_IMAGE_GRAYSCALE);
            
            /////////////part1 optimizeImageDim
            // optimize the dimension of the loaded image
            // init
            Mat padded=new Mat();
            // get the optimal rows size for dft
            int addPixelRows = Core.getOptimalDFTSize(source.rows());
            // get the optimal cols size for dft
            int addPixelCols = Core.getOptimalDFTSize(source.cols());
            // apply the optimal cols and rows size to the image
            
             //��v�����ؤo�O2�A 3�A5����ƭ��ɡA�p��t�׳̧֡C���F�F��ֳt�p��A            
            //�N��J�Ϲ��[���X�i��̨Ϊ��ؤo , �K�[��������l�Ƭ�0 
            Core.copyMakeBorder(source, padded, 0, addPixelRows - source.rows(), 0, addPixelCols - source.cols(),1, Scalar.all(0));
            // return padded;
            //end part1 optimizeImageDim
            //System.out.println(padded.dump());
            
            //main
            //���t�ť߸��ܴ����곡�M�곡�s�x�Ŷ���ӹϹ���. �ť߸��ܴ������G�O�ƼơA �]���ܤ֭n�N�W���x�s�b float �榡�A�æh�[�@���B�~�q�D���x�s�ƼƳ����G
            padded.convertTo(padded, CvType.CV_32F);
            List<Mat> planes = new ArrayList<Mat>();
            Mat complexImage=new Mat();
         // prepare the image planes to obtain the complex image
            planes.add(padded);
            planes.add(Mat.zeros(padded.size(), CvType.CV_32F));
            
         // prepare a complex image for performing the dft
         ////���X�i�᪺�Ϲ��W�K�@�Ӫ�l�Ƭ�0���q�D   
            Core.merge(planes, complexImage);
            // dft
            //�i�������ť߸��ܴ�, �ܴ����G�s�b��lMat�x�}��
            Core.dft(complexImage, complexImage);
            //Mat magnitude = new Mat();
            
         // optimize the image resulting from the dft operation
            /// part2 createOptimizedMagnitude
         // init
            
            List<Mat> newPlanes = new ArrayList<Mat>();
            Mat mag = new Mat();
            // split the comples image in two planes
          //�N�Ƽ��ഫ������.
            Core.split(complexImage, newPlanes);
            // compute the magnitude
            Core.magnitude(newPlanes.get(0), newPlanes.get(1), mag);
         // move to a logarithmic scale
          //�ഫ���ƪ��ث�
            Core.add(mag, Scalar.all(1), mag); 
            Core.log(mag, mag);
            // optionally reorder the 4 quadrants of the magnitude image
            ////////////////part3 shiftDFT
          //���ũ_�Ʀ�P�C
            mag = mag.submat(new Rect(0, 0, mag.cols() & -2, mag.rows() & -2));
            
          //�����G�ť߸��T��4�ӶH����
            int cx = mag.cols() / 2;
            int cy = mag.rows() / 2;

          //���W�� - ���C�@�ӶH���Ы�ROI
            Mat q0 = new Mat(mag, new Rect(0, 0, cx, cy));
          //�k�W��
            Mat q1 = new Mat(mag, new Rect(cx, 0, cx, cy));
         // ���U��
            Mat q2 = new Mat(mag, new Rect(0, cy, cx, cy));
          //�k�U��
            Mat q3 = new Mat(mag, new Rect(cx, cy, cx, cy));

            Mat tmp = new Mat();
            q0.copyTo(tmp);
            q3.copyTo(q0);
            //�洫�H��:���W�P�k�U���
            tmp.copyTo(q3);

            q1.copyTo(tmp);
            q2.copyTo(q1);
          //�洫�H��:�k�W�P���U���
            tmp.copyTo(q2);
            //end part3 shiftDFT
         
            // normalize the magnitude image for the visualization since both JavaFX
            // and OpenCV need images with value between 0 and 255
          //���W�Ʀ�[0,255]�d��
            Core.normalize(mag, mag, 0,255, Core.NORM_MINMAX);
            //end part2 createOptimizedMagnitude
            
            
            //Imgproc.GaussianBlur(source1, processBlur,new Size(GaussianKernelSize,GaussianKernelSize),0,0);
            //Mat lastoutput = ConvertDFTToImage(Dft,gaussianFilter,output);
            //source.convertTo(destination, -1, alpha, beta);
            Imgcodecs.imwrite("C://opencv3.1//samples//lena-dft.jpg", mag);
            //main end
           }catch (Exception e) {
              System.out.println("error: " + e.getMessage());
           }
   }
}