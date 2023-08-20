#include <iostream>
#include "raytracing_engine/engine.hpp"
#include "scenes/camera.hpp"

int main()
{
    camera cam;
    cam.readJson("../scenes/configurations/camera.json");
    std::cout << cam << std::endl;

    engine eng(cam);
    eng.render();
}