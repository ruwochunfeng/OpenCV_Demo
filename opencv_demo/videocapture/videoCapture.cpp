#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv)
{
   const std::string lujin= "/media/zhou/disk/ceshi.mp4";
   VideoCapture cap = VideoCapture(lujin);
   Mat frame;
   Mat gray;
   if(!cap.isOpened())
   {
       std::cout << "no video open"  << std::endl;
       return -1;
   }

   while(true)
   {
      cap.read(frame);

      if(frame.empty())
      {
         std::cout << "no frame open"  << std::endl;
         return -1;
      }

      cvtColor(frame,gray,COLOR_BGR2GRAY);
      
      imshow("gray", gray);

      if((waitKey(1) & 0xFF) == 27)
          break;
   }

   cap.release();
   destroyAllWindows();
   waitKey(0);
   return 0;
}

