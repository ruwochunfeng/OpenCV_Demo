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
    
    Mat image;
    Mat gray;
    image = imread( argv[1],1);
    
    if(!image.data)
    {
       printf("No image data \n");
       return -1;
    }
    
    cvtColor(image,gray, COLOR_RGB2GRAY);
    GaussianBlur(gray, gray, Size(9,9),2,2);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    
    waitKey(0);
    
    return 0;
}

