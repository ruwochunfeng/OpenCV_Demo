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
    image = imread( argv[1]);
    
    if(!image.data)
    {
       printf("No image data \n");
       return -1;
    }

    GaussianBlur(image, image, Size(3,3), 0, 0, BORDER_DEFAULT);
    
    cvtColor(image, image_fray, COLOR_RGB2GRAY);
    
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;
    Sobel(image_fray, grad_x, depth,1,0,3,scale,delta,BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);
    
    Sobel(image_fray, grad_y, depth,1,0,3,scale,delta,BORDER_DEFAULT);
    convertScaleAbs(grad_y, abs_grad_y);
    
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5,0,grad);
    imshow("Sobel show image", grad);
    
    waitKey(0);
    
    return 0;
}

