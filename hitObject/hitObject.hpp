#ifndef HITOBJECT
#define HITOBJECT

#include "../raytracing_engine/ray.hpp"

class hit_record
{
public:
    point3 p;
    vector3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray &r, const vector3 &outward_normal);
};

class hitObject
{
public:
    virtual ~hitObject() = default;
    virtual bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const = 0;
};

#endif