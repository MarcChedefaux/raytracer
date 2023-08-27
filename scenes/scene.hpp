#ifndef SCENE
#define SCENE

#include "../utils/common.hpp"
#include "../hitObject/hitObject.hpp"
#include "../hitObject/sphere.hpp"
#include "../hitObject/plane.hpp"
#include "../hitObject/triangle.hpp"
#include "../material/material.hpp"
#include "../material/lambertian.hpp"
#include "../material/metal.hpp"
#include "../material/dielectric.hpp"
#include "../material/light.hpp"
#include "camera.hpp"

#include <json.hpp>
#include <memory>
#include <vector>
#include <fstream>

using json = nlohmann::json;

using std::make_shared;
using std::shared_ptr;

class scene
{
public:
    camera cam;
    std::vector<shared_ptr<hitObject>> objects;

    scene();
    scene(camera c);

    void clear();
    void add(shared_ptr<hitObject> object);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const;

    void readJson(std::string filePath);
};

#endif