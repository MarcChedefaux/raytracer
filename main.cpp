#include <iostream>
#include "raytracing_engine/engine.hpp"
#include "scenes/camera.hpp"
#include "scenes/scene.hpp"

int main()
{
    camera cam;
    cam.readJson("../scenes/configurations/camera.json");

    scene sce;
    sce.readJson("../scenes/configurations/scene2.json");

    engine eng(cam, sce);
    eng.init();
    eng.render();
}