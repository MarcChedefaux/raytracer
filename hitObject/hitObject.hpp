#ifndef HITOBJECT
#define HITOBJECT

#include "ray.hpp"

class hit_record
{
public:
    point3 p;
    vector3 normal;
    double t;
};

class hitObject
{
public:
    virtual ~hitObject() = default;
    virtual bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const = 0;
};

#endif