#ifndef ENGINE
#define ENGINE

#include <opencv2/opencv.hpp>
#include <tqdm.hpp>
#include "camera.hpp"
#include "vector3.hpp"
#include "color3.hpp"
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