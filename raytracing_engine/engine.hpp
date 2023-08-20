#ifndef ENGINE
#define ENGINE

#include <opencv2/opencv.hpp>
#include <tqdm.hpp>
#include "../scenes/camera.hpp"
#include "../scenes/scene.hpp"
#include "../utils/color3.hpp"
#include "../utils/common.hpp"
#include "ray.hpp"

class engine
{
private:
    camera cam;
    scene sce;

public:
    engine(camera c, scene s);

    void render();
    color3 ray_color(const ray &r);
};

#endif