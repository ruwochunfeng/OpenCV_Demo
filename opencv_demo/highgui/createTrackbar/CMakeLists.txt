cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH /home/zhou/build/)
set(Opencv_DIR /usr/local/lib/libopencv_core.so)
project(DisplayImage)

include_directories( ${OpenCV_INCLUDE_DIRS})

include_directories( /home/zhou/opencv/include/)
include_directories( /home/zhou/build/)
include_directories( /home/zhou/opencv/modules/core/include/)
include_directories( /home/zhou/opencv/modules/calib3d/include/)
include_directories( /home/zhou/opencv/modules/features2d/include/)
include_directories( /home/zhou/opencv/modules/dnn/include/)
include_directories( /home/zhou/opencv/modules/flann/include/)
include_directories( /home/zhou/opencv/modules/highgui/include/)
include_directories( /home/zhou/opencv/modules/imgcodecs/include/)
include_directories( /home/zhou/opencv/modules/imgproc/include/)
include_directories( /home/zhou/opencv/modules/ml/include/)
include_directories( /home/zhou/opencv/modules/objdetect/include/)
include_directories( /home/zhou/opencv/modules/photo/include/)
include_directories( /home/zhou/opencv/modules/stitching/include/)
include_directories( /home/zhou/opencv/modules/video/include/)
include_directories( /home/zhou/opencv/modules/videoio/include/)

add_executable(createTrackbar createTrackbar.cpp)

target_link_libraries(createTrackbar ${OpenCV_LIBS})
target_link_libraries(createTrackbar ${Opencv_DIR} 
                      /usr/local/lib/libopencv_calib3d.so
                      /usr/local/lib/libopencv_features2d.so
                      /usr/local/lib/libopencv_dnn.so
                      /usr/local/lib/libopencv_flann.so
                      /usr/local/lib/libopencv_highgui.so
                      /usr/local/lib/libopencv_imgcodecs.so
                      /usr/local/lib/libopencv_imgproc.so
                      /usr/local/lib/libopencv_ml.so
                      /usr/local/lib/libopencv_objdetect.so
                      /usr/local/lib/libopencv_photo.so
                      /usr/local/lib/libopencv_stitching.so
                      /usr/local/lib/libopencv_video.so
                      /usr/local/lib/libopencv_videoio.so)
