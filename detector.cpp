// detector.cpp

#include <iostream>
#include <stdlib.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv)
{
    cv::CascadeClassifier faceDetection;
    if (!faceDetection.load("/home/yathavan/Documents/faceDetection/haarcascade_frontalface_default.xml"))
    {
        std::cout << "\n File is not loaded properly";
        exit(0);
    }

    cv::namedWindow("Face Recognition", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;

    if (argc == 1)
    {
        cap.open(0);
    }
    else
    {
        cap.open(argv[1]);
    }

    if (!cap.isOpened())
    {
        std::cerr << "couldn't open capture!" << std::endl;
        return -1;
    }

    cv::Mat frame;

    for (;;)
    {
        cap >> frame;

        if (frame.empty())
        {
            break;
        }

        cv::imshow("FaceRec", frame);

        std::vector<cv::Rect> faces;
        faceDetection.detectMultiScale(frame, faces);

        for (int index = 0; index < faces.size(); index++)
        {
            cv::Point pt1(faces[index].x, faces[index].y);
            cv::Point pt2((faces[index].x + faces[index].height), (faces[index].y + faces[index].width));
            cv::rectangle(frame, pt1, pt2, cv::Scalar(0, 255, 0), 4, 8, 0);
        }

        cv::imshow("FaceRec", frame);
        cv::waitKey(10);
    }

    cv::imshow("Detected Face", frame);
    cv::waitKey(0);

    return 0;
}
