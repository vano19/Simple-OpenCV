#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;


int main(int argv, char** argc)
{
   Mat image = imread(fname,1);

   namedWindow("Origin",CV_WINDOW_AUTOSIZE);
   imshow("Origin",image);
   Mat output1,output2,output3;
   // GET THE RED COLOR
   inRange(image,Scalar(10,10,100),Scalar(100,100,255),output1);
   //GET THE BLUE COLOR
   inRange(image,Scalar(100,10,10),Scalar(255,100,100),output2);
   //CET THE GREEN COLOR
   inRange(image,Scalar(10,100,10),Scalar(100,255,100),output3);

   int x1,x2,x3;
   x1=countNonZero(output1);
   x2=countNonZero(output2);
   x3=countNonZero(output3);

   namedWindow("output",CV_WINDOW_AUTOSIZE);
   if(x3>x2 && x3>x1){
      std:: cout<<"GREEN"<<std::endl;
       imshow("output",output1);
   }
   else if(x2>x3 && x2>x1){
      std:: cout<<"BLUE"<<std::endl;
       imshow("output",output2);
   }
   else if(x1>x3 && x1>x2) {
      std:: cout<<"RED"<<std::endl;
        imshow("output",output3);
   }

   waitKey(0);

    return 0;

}
