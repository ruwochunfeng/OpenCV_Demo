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
    int scale = 2;
    int delta = 0;
    int depth = CV_16S;
    
    Mat image, image_fray;
    image = imread( argv[1]);
    
    if(!image.data)
    {
       printf("No image data \n");
       return -1;
    }

    GaussianBlur(image, image, Size(3,3), 0, 0, BORDER_DEFAULT);
    
    cvtColor(image, image_fray, COLOR_RGB2GRAY);
    
    Laplacian(image_fray, image_fray, depth, kernel_size, scale, delta,BORDER_DEFAULT);
    
    convertScaleAbs(image_fray,image_fray);
    imshow("Laplacian show image", image_fray);
    
    waitKey(0);
    
    return 0;
}

