#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

using namespace cv;

int main(int argc, const char * argv[])
{
    CvCapture* capture = cvCreateCameraCapture(CV_CAP_ANY);
    assert(capture);
    IplImage* frame=0;
    cvNamedWindow("Camera",CV_WINDOW_AUTOSIZE);
    while(1)
    {
        frame = cvQueryFrame(capture);
        cvShowImage("Camera",frame);

        cvWaitKey(33);

    }
    cvReleaseCapture( &capture );
    cvDestroyWindow("Camera");
    return 0;
}
