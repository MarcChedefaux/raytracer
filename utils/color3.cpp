#include "color3.hpp"

color3::color3() : vector3() {}
color3::color3(const vector3 &v) : vector3(v) {}
color3::color3(double c1, double c2, double c3) : vector3(c1, c2, c3) {}

cv::Vec3b color3::to_cvColor(int numberOfSamples)
{
    double scale = 1.0 / numberOfSamples;
    e[0] *= scale;
    e[1] *= scale;
    e[2] *= scale;

    short ir = static_cast<short>(255.999 * e[0]);
    short ig = static_cast<short>(255.999 * e[1]);
    short ib = static_cast<short>(255.999 * e[2]);

    return cv::Vec3b(ib, ig, ir);
}