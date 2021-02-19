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
    //load gray pictures
    image = imread( argv[1],0);
    
    if(!image.data)
    {
       printf("No image data \n");
       return -1;
    }
    GaussianBlur(image, image, Size(5,5),0);
    Canny(image, image, 50, 150);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    
    waitKey(0);
    
    return 0;
}

