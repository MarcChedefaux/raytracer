#ifndef SPHERE
#define SPHERE

#include "hitObject.hpp"
#include "../material/material.hpp"

class sphere : public hitObject
{
private:
    point3 center;
    double radius;
    shared_ptr<material> mat;

public:
    sphere(point3 c, double r, shared_ptr<material> m);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const;
};

#endif