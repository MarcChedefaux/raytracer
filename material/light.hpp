#ifndef LIGHT
#define LIGHT

#include "material.hpp"

class light : public material
{
private:
    color3 albedo;
    double intensity;

public:
    light(const color3 &a, double i);

    bool scatter(const ray &r_in, hit_record &rec, color3 &attenuation, ray &scattered) const;
};

#endif