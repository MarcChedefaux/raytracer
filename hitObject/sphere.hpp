#ifndef SPHERE
#define SPHERE

#include "hitObject.hpp"
#include "../utils/vector3.hpp"

class sphere : public hitObject
{
private:
    point3 center;
    double radius;

public:
    sphere(point3 c, double r);

    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const;
};

#endif