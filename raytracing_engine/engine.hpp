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

    point3 pixel00_loc;
    vector3 pixel_delta_u;
    vector3 pixel_delta_v;

    color3 ray_color(const ray &r);

public:
    engine(camera c, scene s);

    void init();
    void render();
};

#endif