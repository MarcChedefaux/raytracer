#ifndef CAMERA
#define CAMERA

#include <json.hpp>
#include <iostream>
#include <fstream>
#include "../utils/common.hpp"

using json = nlohmann::json;

class camera
{
public:
    int image_width;
    int image_height;
    double aspect_ratio;
    double viewport_height;
    double viewport_width;
    double viewport_ratio;
    int samples_per_pixel;
    int max_depth;
    int nbThread;
    double vfov;
    double focus_dist;
    double defocus_angle;

    vector3 lookFrom;
    vector3 lookAt;

    camera();

    void readJson(std::string filePath);

    friend std::ostream &operator<<(std::ostream &out, const camera &c);
};

#endif