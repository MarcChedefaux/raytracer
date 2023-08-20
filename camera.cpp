#include "camera.hpp"

camera::camera() {}

void camera::readJson(std::string filePath)
{
    std::ifstream fileCam(filePath);
    json data = json::parse(fileCam);

    if (data.contains("aspect_ratio_h"))
    {
        aspect_ratio = (double)data["aspect_ratio_w"] / (double)data["aspect_ratio_h"];
        if (data.contains("image_width"))
        {
            image_width = data["image_width"];
            image_height = static_cast<int>(image_width / aspect_ratio);
            image_height = std::max(image_height, 1);
        }
        else
        {
            image_height = data["image_height"];
            image_width = static_cast<int>(image_height * aspect_ratio);
            image_width = std::max(image_width, 1);
        }
    }
    else
    {
        image_width = data["image_width"];
        image_height = data["image_height"];
    }

    focal_length = data["focal_length"];

    if (data.contains("viewport_width"))
    {
        viewport_width = data["viewport_width"];
        viewport_height = viewport_width / (static_cast<double>(image_width) / image_height);
    }
    else
    {
        viewport_height = data["viewport_height"];
        viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    }

    viewport_ratio = viewport_width / viewport_height;
}