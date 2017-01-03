#include <iostream>
#include "MTCNN.h"

using namespace std;
using namespace cv;

int main() {

    vector<string> model_file = {
            "../model/det1.prototxt",
            "../model/det2.prototxt",
            "../model/det3.prototxt"
//            "../model/det4.prototxt"
    };

    vector<string> trained_file = {
            "../model/det1.caffemodel",
            "../model/det2.caffemodel",
            "../model/det3.caffemodel"
//            "../model/det4.caffemodel"
    };



    MTCNN mtcnn(model_file, trained_file);

   VideoCapture cap(0);
    //VideoCapture cap("/Users/lixile/Desktop/ross1.mp4");
    //VideoCapture cap("/Users/lixile/Desktop/test3.mp4");

    vector<Rect> rect_lastframe;

    while(cap.isOpened())
    {
        vector<Rect> rectangles;
        Mat img;
        cap >> img;
        mtcnn.detection(img, rectangles, rect_lastframe);
        //mtcnn.detection(img, rectangles);
        rect_lastframe = rectangles;

        for(int i = 0; i < rectangles.size(); i++)
        {
            rectangle(img, cv::Rect(rectangles[i].y, rectangles[i].x, rectangles[i].height, rectangles[i].width), cv::Scalar(0, 0, 255), 3);
        }

        imshow("test", img);
        waitKey(1);
    }


    ///////

    /*
     * vector<Rect> rectangles;
    string img_path = "../result/9_Press_Conference_Press_Conference_9_26.jpg";
    //string img_path = "../result/trump.jpg";
    //string img_path = "../result/0_Parade_marchingband_1_12.jpg";
    //string img_path = "../result/0_Parade_marchingband_1_17.jpg";
    //string img_path = "../result/7_Cheering_Cheering_7_40.jpg";
    //string img_path = "../result/8_Election_Campain_Election_Campaign_8_71.jpg";

    Mat img = imread(img_path);

    mtcnn.detection(img, rectangles);


    for(int i = 0; i < rectangles.size(); i++)
    {
        rectangle(img, cv::Rect(rectangles[i].y, rectangles[i].x, rectangles[i].height, rectangles[i].width), cv::Scalar(0, 0, 255), 3);
    }

    imshow("test", img);
    waitKey(0);
     */


    return 0;
}

