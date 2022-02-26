#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string> 
#include "asciicamera.cpp"

using namespace cv;


int main() {

    Mat image;
    namedWindow("Display window");
    VideoCapture capture(0);
    
    AsciiCamera asciiCamera = AsciiCamera();
    
    while(capture.isOpened()) {
        capture >> image;
        int r, g, b;
        asciiCamera.setFrameBackground(image.rows, image.cols);
        for (int i = 0; i < image.rows; ++i)
        {
            Vec3b* pixel = image.ptr<Vec3b>(i);
            for (int j = 0; j < image.cols; ++j)
            {
                r = pixel[j][2];
                g = pixel[j][1];
                b = pixel[j][0];
                double brightness = (r+g+b)/3;
                if (i % 7 == 0 && j % 7 == 0) {
                    std::string asciiValue = asciiCamera.getAsciiValueForBrightness(brightness);
                    asciiCamera.writeAsciiToFrame(asciiValue, Point(j, i));
                }
            }
        }
        imshow("Display window", asciiCamera.getCurrentFrame());
        
        int c = waitKey(10);

        // Key 27 is esc
        if(c == 27) {
            break;
        }
    }
    
    return 0;
}
