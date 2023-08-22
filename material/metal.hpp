#ifndef METAL
#define METAL

#include "material.hpp"

class metal : public material
{
private:
    color3 albedo;
    double fuzz;

public:
    metal(const color3 &a, double f);

    bool scatter(const ray &r_in, hit_record &rec, color3 &attenuation, ray &scattered) const;
};

#endif