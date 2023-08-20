#ifndef SPHERE
#define SPHERE

#include "hitObject.hpp"

class sphere : public hitObject
{
private:
    point3 center;
    double radius;

public:
    sphere(point3 c, double r);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const;
};

#endif