#include <opencv2/opencv.hpp>
#include <iostream>
#include <tqdm.hpp>
#include "color3.hpp"
#include "vector3.hpp"

int main() {
    std::cout << "Hello World" << std::endl;
    

    int image_width = 500, image_height = 500;

    cv::Mat img(image_width, image_height,CV_8UC3);

    for (int i : tq::trange(image_width)) {
        for (int j = 0; j<image_height; j++) {
            
            color3 col(double(i) / (image_width-1),double(j) / (image_height-1),0);

            img.at<cv::Vec3b>(cv::Point(i,j)) = col.to_cvColor();            
        }
    }
    
    cv::imshow("test", img);
    cv::waitKey();
    std::cout << "END" << std::endl;
}