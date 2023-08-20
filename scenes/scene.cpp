#include "scene.hpp"

scene::scene()
{
    objects = std::vector<shared_ptr<hitObject>>();
}

void scene::clear()
{
    objects.clear();
}

void scene::add(shared_ptr<hitObject> object)
{
    objects.push_back(object);
}

bool scene::hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_tmax;

    for (const shared_ptr<hitObject> &object : objects)
    {
        if (object->hit(r, ray_tmin, closest_so_far, temp_rec))
        {
            hit_anything = true;
            closest_so_far = rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

void scene::readJson(std::string filePath)
{
    std::ifstream fileCam(filePath);
    json data = json::parse(fileCam);

    json camPos = data["cameraPosition"];
    cameraPosition = point3(camPos["x"], camPos["y"], camPos["z"]);

    json objects = data["objects"];
    for (json::iterator it = objects.begin(); it != objects.end(); it++)
    {
        json obj = *it;
        if (obj["type"] == "sphere")
        {
            json objPos = obj["center"];
            point3 sphCenter(objPos["x"], objPos["y"], objPos["z"]);
            double sphRadius = obj["radius"];

            add(make_shared<sphere>(sphCenter, sphRadius));
        }
    }
}
