#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

const int  alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat src1;
Mat src2;
Mat dst;
void  trackbar(int, void*)
{
   alpha = (double)alpha_slider/alpha_slider_max;
   
   beta = (1.0 - alpha);
   addWeighted(src1, alpha, src2, beta, 0.0, dst);
   imshow("Linear Blend",dst);
}
int main(int argc, char** argv)
{
    if(argc != 3)
    {
       printf("Opencv first Demo");
       return -1;

    }
    
    src1 = imread( argv[1],1);
    src2 = imread( argv[2],1);
    
    if(!src1.data || !src2.data)
    {
       printf("No image data \n");
       return -1;
    }
    
    alpha_slider = 0;
    
    namedWindow("Linear Blend", 1);
    
    char TrackbarName[50];
    sprintf(TrackbarName, "Alpha x %d", alpha_slider_max);
    
    
    createTrackbar(TrackbarName, "Linear Blend",&alpha_slider,alpha_slider_max, trackbar);

    trackbar(alpha_slider, 0);
    waitKey(0);
    
    return 0;
}

