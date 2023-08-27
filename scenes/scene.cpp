#include "scene.hpp"

scene::scene()
{
    objects = std::vector<shared_ptr<hitObject>>();
}

scene::scene(camera c)
{
    cam = c;
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

bool scene::hit(const ray &r, interval ray_t, hit_record &rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_t.max;

    for (const shared_ptr<hitObject> &object : objects)
    {
        if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec))
        {
            hit_anything = true;
            closest_so_far = temp_rec.t;
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
    cam.lookFrom = vector3(camPos["lookFrom"]["x"], camPos["lookFrom"]["y"], camPos["lookFrom"]["z"]);
    cam.lookAt = vector3(camPos["lookAt"]["x"], camPos["lookAt"]["y"], camPos["lookAt"]["z"]);
    cam.vfov = camPos["vfov"];
    cam.defocus_angle = camPos["defocus_angle"];
    if (camPos.contains("focus_dist"))
    {
        cam.focus_dist = camPos["focus_dist"];
    }
    else
    {
        cam.focus_dist = (cam.lookFrom - cam.lookAt).length();
    }

    double theta = degrees_to_radians(cam.vfov);
    double h = tan(theta / 2);
    cam.viewport_height = 2 * h * cam.focus_dist;
    cam.viewport_width = cam.viewport_height * (static_cast<double>(cam.image_width) / cam.image_height);

    json objects = data["objects"];
    for (json::iterator it = objects.begin(); it != objects.end(); it++)
    {
        json obj = *it;
        shared_ptr<material> mat;
        json materialInfo = obj["material"];
        if (materialInfo["type"] == "lambertian")
        {
            color3 albedo(materialInfo["albedo"]["r"], materialInfo["albedo"]["g"], materialInfo["albedo"]["b"]);
            mat = make_shared<lambertian>(albedo);
        }
        if (materialInfo["type"] == "metal")
        {
            color3 albedo(materialInfo["albedo"]["r"], materialInfo["albedo"]["g"], materialInfo["albedo"]["b"]);
            double fuzz = materialInfo["fuzz"];
            mat = make_shared<metal>(albedo, fuzz);
        }
        if (materialInfo["type"] == "dielectric")
        {
            mat = make_shared<dielectric>(materialInfo["refraction"]);
        }
        if (materialInfo["type"] == "light")
        {
            color3 albedo(materialInfo["albedo"]["r"], materialInfo["albedo"]["g"], materialInfo["albedo"]["b"]);
            double intensity = materialInfo["intensity"];
            mat = make_shared<light>(albedo, intensity);
        }

        if (obj["type"] == "sphere")
        {
            json objPos = obj["center"];
            point3 sphCenter(objPos["x"], objPos["y"], objPos["z"]);
            double sphRadius = obj["radius"];

            add(make_shared<sphere>(sphCenter, sphRadius, mat));
        }

        if (obj["type"] == "plane")
        {
            json objPos = obj["bottomLeft"];
            point3 planeBottomLeft(objPos["x"], objPos["y"], objPos["z"]);

            objPos = obj["upperRight"];
            point3 planeUpperRight(objPos["x"], objPos["y"], objPos["z"]);

            add(make_shared<plane>(planeBottomLeft, planeUpperRight, mat));
        }
    }
}
