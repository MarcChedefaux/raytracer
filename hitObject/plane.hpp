#ifndef PLANE
#define PLANE

#include "hitObject.hpp"
#include "../material/material.hpp"

class plane : public hitObject
{
private:
    point3 bottomLeft;
    vector3 u;
    vector3 v;
    vector3 normal;
    shared_ptr<material> mat;

public:
    plane(point3 bl, point3 ur, shared_ptr<material> m);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const;
};

#endif