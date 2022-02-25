#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main() {
    Mat image;

    namedWindow("Display window");

    VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cout << "cannot open camera";
    }

    while (true) {
        cap >> image;
        imshow("Display window", image);
        waitKey(25);
    }
    return 0;

}