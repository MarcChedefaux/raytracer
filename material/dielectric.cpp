#include "dielectric.hpp"

dielectric::dielectric(double index_of_refraction) : ior(index_of_refraction) {}

double dielectric::reflectance(double cosine, double ref_idx)
{
    double r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - cosine), 5);
}

bool dielectric::scatter(const ray &r_in, const hit_record &rec, color3 &attenuation, ray &scattered) const
{
    attenuation = color3(1, 1, 1);
    double refraction_ratio = rec.front_face ? 1.0 / ior : ior;

    vector3 unit_direction = unit_vector(r_in.direction());
    double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    bool cannot_refract = refraction_ratio * sin_theta > 1.0;
    vector3 direction;

    if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
        direction = reflect(unit_direction, rec.normal);
    else
        direction = refract(unit_direction, rec.normal, refraction_ratio);

    scattered = ray(rec.p, direction);
    return true;
}