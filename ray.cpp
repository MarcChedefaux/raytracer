#include "ray.hpp"

ray::ray() {}
ray::ray(const point3 &origin, const vector3 &direction) : orig(origin), dir(direction) {}

point3 ray::origin()
{
    return orig;
}

vector3 ray::direction()
{
    return dir;
}

point3 ray::at(double t)
{
    return orig + t * dir;
}