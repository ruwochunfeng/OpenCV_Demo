#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{

   Mat src = imread("11.png");

   if(!src.data)
   {
       std::cout << "No image Data" << std::endl;
       return -1;
   }

   imshow("ceshi", src);

   HOGDescriptor hog = HOGDescriptor();

   hog.setSVMDetector(hog.getDefaultPeopleDetector());

   Mat result = src.clone();

   std::vector<Rect> foundlocations;

   hog.detectMultiScale(src, foundlocations, 0, Size(3,3), Size(32,32), 1.05, 2);

   for(size_t i = 0; i < foundlocations.size(); i++)
   {
      rectangle(result, foundlocations[i], Scalar(0,0,255), 2, 8, 0);

   }

   imshow("HOG SVM Demo", result);
   waitKey(0);
   return 0;
}

