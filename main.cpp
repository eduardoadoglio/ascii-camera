#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string> 

using namespace cv;


Mat createBlackImage(int width, int height) {
    return Mat::zeros(width,height,CV_8U);
}

int main() {

    Mat image;

    namedWindow("Display window");

    VideoCapture capture(0);
    
    while(capture.isOpened()) {
        capture >> image;
        int r, g, b;
        Mat blackImage = createBlackImage(image.rows, image.cols);
        for (int i = 0; i < image.rows; ++i)
        {
            Vec3b* pixel = image.ptr<Vec3b>(i);
            for (int j = 0; j < image.cols; ++j)
            {
                r = pixel[j][2];
                g = pixel[j][1];
                b = pixel[j][0];
                std::string rv = std::to_string(r);
                if (i % 20 == 0 && j % 20 == 0) {
                    putText(blackImage, rv ,Point(j, i), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(255),1,8,false); 
                }
            }
        }
        imshow("Display window", blackImage);
        
        int c = waitKey(10);

        // Key 27 is esc
        if(c == 27) {
            break;
        }
    }
    
    return 0;
}
