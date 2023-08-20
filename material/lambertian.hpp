#ifndef LAMBERTIAN
#define LAMBERTIAN

#include "material.hpp"

class lambertian : public material
{
private:
    color3 albedo;

public:
    lambertian(const color3 &a);

    bool scatter(const ray &r_in, const hit_record &rec, color3 &attenuation, ray &scattered) const;
};

#endif