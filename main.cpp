#include <iostream>
#include "raytracing_engine/engine.hpp"
#include "scenes/camera.hpp"
#include "scenes/scene.hpp"

int main()
{
    camera cam;
    cam.readJson("../scenes/configurations/camera.json");

    scene sce(cam);
    sce.readJson("../scenes/configurations/scene3.json");

    engine eng(sce);
    eng.init();
    eng.render();
}