#ifndef ENGINE
#define ENGINE

#include <opencv2/opencv.hpp>
#include <tqdm.hpp>
#include "../scenes/camera.hpp"
#include "../utils/vector3.hpp"
#include "../utils/color3.hpp"
#include "ray.hpp"

class engine
{
private:
    camera cam;

public:
    engine(camera c);

    void render();
};

#endif