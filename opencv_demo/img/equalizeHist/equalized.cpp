#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
    if(argc != 2)
    {
       printf("Opencv first Demo");
       return -1;

    }
    
    int kernel_size = 7;
    int scale = 1;
    int delta = 0;
    int depth = CV_16S;
    
    Mat image, image_fray, grad;
    image = imread( argv[1],1);
    
    if(!image.data)
    {
       printf("No image data \n");
       return -1;
    }
    
    cvtColor(image, image_fray, COLOR_RGB2GRAY);
    
    equalizeHist(image,image);
    
    imshow("equalizeHist show image", image);
    
    waitKey(0);
    
    return 0;
}

