#ifndef RAY
#define RAY

#include "vector3.hpp"

class ray
{
private:
    point3 orig;
    vector3 dir;

public:
    ray();
    ray(const point3 &origin, const vector3 &direction);

    point3 origin();
    vector3 direction();

    point3 at(double t);

    friend std::ostream &operator<<(std::ostream &out, const ray &r);
};

#endif