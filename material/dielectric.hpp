#ifndef DIELECTRIC
#define DIELECTRIC

#include "material.hpp"

class dielectric : public material
{
private:
    double ior;

    static double reflectance(double cosine, double ref_idx);

public:
    dielectric(double index_of_refraction);
    bool scatter(const ray &r_in, const hit_record &rec, color3 &attenuation, ray &scattered) const;
};

#endif