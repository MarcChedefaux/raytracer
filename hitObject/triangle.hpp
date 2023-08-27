#ifndef TRIANGLE
#define TRIANGLE

#include "hitObject.hpp"
#include "../material/material.hpp"

class triangle : public hitObject
{
private:
    point3 p0;
    vector3 u;
    vector3 v;
    vector3 normal;
    shared_ptr<material> mat;

public:
    triangle(point3 p0, point3 p1, point3 p2, shared_ptr<material> m);
    triangle(point3 p0, point3 p1, point3 p2, vector3 normal, shared_ptr<material> m);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const;
};

#endif