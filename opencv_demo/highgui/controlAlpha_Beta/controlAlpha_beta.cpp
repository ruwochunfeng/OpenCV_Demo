#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
double alpha;
int beta;


int main(int argc, char** argv)
{
    if(argc != 2)
    {
       printf("Opencv first Demo");
       return -1;

    }
    
    Mat src1 = imread( argv[1]);
    Mat image = Mat::zeros(src1.size(), src1.type());
    
    if(!src1.data)
    {
       printf("No image data \n");
       return -1;
    }
    
    cout << "Enter the alpha vale: 1.0-3.0" << endl;
    cin >> alpha;
    cout << "Enter the beta vale: 0 - 100" << endl;
    cin >> beta;   
    
    
    for(int y = 0; y < src1.rows; y++)
    {
    
      for(int x = 0; x< src1.cols; x++)
      {
          for(int c = 0; c< 3; c++)
          {
             image.at<Vec3b>(y,x)[c] =  saturate_cast<uchar>(alpha *(src1.at<Vec3b>(y,x)[c]) + beta);
          }
          
      }
    
    }
    
    imshow("orignal image", src1);
    imshow("New image", image);
    waitKey(0);
    
    return 0;
}

