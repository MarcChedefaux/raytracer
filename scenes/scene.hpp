#ifndef SCENE
#define SCENE

#include "../hitObject/hitObject.hpp"
#include "../utils/vector3.hpp"
#include "../hitObject/sphere.hpp"

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
    point3 cameraPosition;
    std::vector<shared_ptr<hitObject>> objects;

    scene();

    void clear();
    void add(shared_ptr<hitObject> object);

    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const;

    void readJson(std::string filePath);
};

#endif