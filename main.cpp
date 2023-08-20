#include <iostream>
#include "engine.hpp"
#include "camera.hpp"

int main()
{
    camera cam;
    cam.readJson("../scenes/camera.json");
    std::cout << cam << std::endl;

    engine eng(cam);
    eng.render();
}