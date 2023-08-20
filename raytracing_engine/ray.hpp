#ifndef RAY
#define RAY

#include "../utils/vector3.hpp"

class ray
{
private:
    point3 orig;
    vector3 dir;

public:
    ray();
    ray(const point3 &origin, const vector3 &direction);

    point3 origin() const;
    vector3 direction() const;

    point3 at(double t) const;

    friend std::ostream &operator<<(std::ostream &out, const ray &r);
};

#endif