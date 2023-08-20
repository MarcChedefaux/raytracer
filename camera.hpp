#ifndef CAMERA
#define CAMERA

#include <json.hpp>
#include <iostream>
#include <fstream>

using json = nlohmann::json;

class camera
{
public:
    int image_width;
    int image_height;
    double aspect_ratio;
    double focal_length;
    double viewport_height;
    double viewport_width;
    double viewport_ratio;

    camera();

    void readJson(std::string filePath);
};

#endif