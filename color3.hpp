#ifndef COLOR3
#define COLOR3

#include "vector3.hpp"
#include <opencv2/opencv.hpp>

class color3 : vector3
{
public:
    color3();
    color3(double c1, double c2, double c3);

    cv::Vec3b to_cvColor();
};

#endif