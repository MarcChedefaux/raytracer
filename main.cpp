#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl;
    

    int image_width = 500, image_height = 500;
    short *image = (short*)malloc(image_width*image_height*3*sizeof(short));
    cv::Mat img(image_width, image_height,CV_8UC3);

    for (int i = 0; i < image_width; i++) {
        for (int j = 0; j<image_height; j++) {
            
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            short ir = static_cast<short>(255.999 * r);
            short ig = static_cast<short>(255.999 * g);
            short ib = static_cast<short>(255.999 * b);

            cv::Vec3b &color = img.at<cv::Vec3b>(cv::Point(i,j));
            color[1] = ig;
            color[2] = ir;

            
        }
    }
    
    cv::imshow("test", img);
    cv::waitKey();
    std::cout << "END" << std::endl;
}