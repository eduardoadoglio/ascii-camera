#include <string> 
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iomanip>

class AsciiCamera {
    cv::Mat currentFrame;
    std::string densityMapping = "Ñ@#W$9876543210?!abc;:+=-,._               ";
    double slope = double(this->densityMapping.length() - 1) / 255;

    private:
        int getDensityIndexFromBrightness(double brightness) {
            return std::floor(this->slope * brightness);
        }

    public:
        cv::Mat getCurrentFrame() {
            return this->currentFrame;
        }
        void setFrameBackground(int width, int height) {
            this->currentFrame = cv::Mat::zeros(width,height,CV_8U);
        }
        void writeAsciiToFrame(std::string asciiValue, cv::Point point) {
            cv::putText(this->currentFrame, asciiValue, point, cv::FONT_HERSHEY_COMPLEX_SMALL, 0.3, cv::Scalar(255),1,8,false); 
        }
        std::string getAsciiValueForBrightness(double brightness) {
            int index = this->getDensityIndexFromBrightness(brightness);
            char asciiChar = this->densityMapping.at(index);
            std::string str(1, asciiChar);
            return str;
        }


};