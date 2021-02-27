#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

string facs_cascade_name = "haarcascade_frontalface_alt.xml";
string eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

string window_name = "Capture - Face detection";
RNG rng(12345);

void detectAndDisplay(Mat frame)
{

   std::vector<Rect> faces;
   
   Mat frame_gray;
   
   cvtColor(frame, frame_gray, COLOR_RGB2GRAY);
   equalizeHist(frame_gray,frame_gray);
   face_cascade.detectMultiScale(frame_gray, faces, 1.1,2,0 | CASCADE_SCALE_IMAGE,Size(30,30));

   for(int i = 0; i< faces.size(); i++)
   {
      //Point center(faces[i].x + faces[i].width*0.5, faces[i].y+ faces[i].height *0.5);
      
      Point center1(faces[i].x, faces[i].y);

      Point center2(faces[i].x + faces[i].width, faces[i].y+ faces[i].height);
      
      //ellipse(frame,center1,center2,Size(faces[i].width*0.5,faces[i].height *0.5),1.1,3.2,1,Scalar(255,0,255),4,8,0);
      
      rectangle(frame, center1,center2,Scalar(255,0,255),4,8,0);
      //Mat faceROI = frame_gray(faces[i]);

      
      //eyes_cascade.detectMultiScale(faceROI, eyes, 1.1,2,0 | CASCADE_SCALE_IMAGE,Size(30,30));
      
    /*  for(int j =0; j < eyes.size(); j++)
      {
         printf("you shuju");
         //Point center(faces[i].x+ eyes[j].x + eyes[j].width*0.5,faces[i].y+eyes[j].y+ eyes[j].height *0.5);
         Point center_eye1(faces[i].x+ eyes[j].x,faces[i].y+eyes[j].y);
         Point center_eye2(faces[i].x+ eyes[j].x + eyes[j].width,faces[i].y+eyes[j].y+ eyes[j].height );
         rectangle(frame, center_eye1,center_eye2,Scalar(0,255,255),4,8,0);
         //int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
         //circle(frame, center, radius,Scalar(255,0,0),4,8,0);
      }*/
   }
      std::vector<Rect> eyes;
      eyes_cascade.detectMultiScale(frame_gray, eyes, 1.1,2,0 | CASCADE_SCALE_IMAGE,Size(30,30));
      for(int j =0; j < eyes.size(); j++)
      {
         printf("you shuju");
         //Point center(faces[i].x+ eyes[j].x + eyes[j].width*0.5,faces[i].y+eyes[j].y+ eyes[j].height *0.5);
         Point center_eye1(eyes[j].x,eyes[j].y);
         Point center_eye2(eyes[j].x + eyes[j].width,eyes[j].y+ eyes[j].height );
         rectangle(frame, center_eye1,center_eye2,Scalar(0,255,255),4,8,0);
         //int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
         //circle(frame, center, radius,Scalar(255,0,0),4,8,0);
      }
   imshow(window_name, frame);
}
int main(int argc, char** argv)
{

   Mat frame;
   VideoCapture cap;
   //cap.open("/home/zhou/OpenCV_Demo/opencv_demo/objdetect/shipin.mp4");
   cap.open("/dev/video0");
   
   if(!cap.isOpened())
   {
      printf("Error Open Camera");
      return -1;
   }
   if(!face_cascade.load(facs_cascade_name)) {printf("Error Loading Face"); return -1;};
   if(!eyes_cascade.load(eyes_cascade_name)) {printf("Error Loading eyes"); return -1;};

   while(1)
   {
      cap.read(frame);
      
      if(frame.empty())
      {
         printf("Error Open Camera");
         return -1;      
      }
      detectAndDisplay(frame);
      waitKey(0);
   }
   
   return 0;
}

