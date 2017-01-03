cmake_minimum_required(VERSION 3.6)
project(MTCNN)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV)
#message(FATAL_ERROR ${OpenCV_INCLUDE_DIRS})

find_package(Caffe)
#set(Caffe_INCLUDE_DIRS /Users/lixile/caffe/include/)
include_directories(${Caffe_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp MTCNN.cpp MTCNN.h)
add_executable(MTCNN ${SOURCE_FILES})


#set(Caffe_LIBRARIES /Users/lixile/caffe/.build_release/lib/)
target_link_libraries(MTCNN ${OpenCV_LIBS} )
target_link_libraries(MTCNN ${Caffe_LIBRARIES})
#message(FATAL_ERROR ${Caffe_LIBRARIES})