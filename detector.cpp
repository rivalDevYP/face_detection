// detector.cpp

#include <iostream>
#include <stdlib.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    cv::CascadeClassifier faceDetection;
    if (!faceDetection.load("/home/yathavan/Documents/faceDetection/haarcascade_frontalface_default.xml"))
    {
        std::cout << "\n File is not loaded properly";
        exit(0);
    }

    std::string path = "/home/yathavan/Documents/faceDetection/testIndian.jpg";

    cv::Mat img = cv::imread(path, cv::IMREAD_UNCHANGED);

    if (img.empty())
    {
        std::cout << "\n Image is not loaded properly";
    }
    else
    {
        std::cout << "\n Image is found!";
        std::cout << "\n Processing...";

        std::vector<cv::Rect> faces;
        faceDetection.detectMultiScale(img, faces);

        for (int index = 0; index < faces.size(); index++)
        {
            cv::Point pt1(faces[index].x, faces[index].y);
            cv::Point pt2((faces[index].x + faces[index].height), (faces[index].y + faces[index].width));
            cv::rectangle(img, pt1, pt2, cv::Scalar(0, 255, 0), 4, 8, 0);
        }

        cv::imwrite("/home/yathavan/Documents/faceDetection/outputIndian.jpg", img);
        
        std::cout << "\n Face detected success!";
    }
}
