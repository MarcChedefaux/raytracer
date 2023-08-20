#include "color3.hpp"

color3::color3() : vector3() {}
color3::color3(const vector3 &v) : vector3(v) {}
color3::color3(double c1, double c2, double c3) : vector3(c1, c2, c3) {}

double linear_to_gamma(double linear_component)
{
    return sqrt(linear_component);
}

cv::Vec3b color3::to_cvColor(int numberOfSamples)
{
    double r = e[0];
    double g = e[1];
    double b = e[2];

    double scale = 1.0 / numberOfSamples;
    r *= scale;
    g *= scale;
    b *= scale;

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    short ir = static_cast<short>(255.999 * r);
    short ig = static_cast<short>(255.999 * g);
    short ib = static_cast<short>(255.999 * b);

    return cv::Vec3b(ib, ig, ir);
}