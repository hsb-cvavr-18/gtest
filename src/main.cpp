// std lib
#include <iostream>
#include <sstream>

#include "ImgDebugPrinter/ImgDebugPrinter.h"
#include "PipsDetector/PipsDetector.h"

// OpenCV
#include <opencv2/core.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>


int main(int argc, char** argv) {

    cout <<  "Running main" << std::endl ;

    PipsDetector* pipsdetector = PipsDetectorFactory().createDefaultPipsDetector();

    // open window frame
    cv::namedWindow("frame", true);

    cv::Mat img = cv::imread("../img/Domino_black.jpg");

    if(! img.data ) {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    cv::Mat backgroundFrame = cv::Mat(cv::Size(img.cols, img.rows), CV_8UC3, cv::Scalar(255, 255, 255));

    cvtColor(backgroundFrame, backgroundFrame, CV_BGR2GRAY);

    // remove background
    cv::absdiff(img, backgroundFrame, img);

    pipsdetector->detect(img);

    std::cout << "Press any key to exit.";
    std::cin.ignore();
    std::cin.get();
}
