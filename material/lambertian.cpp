#include "lambertian.hpp"

lambertian::lambertian(const color3 &a) : albedo(a) {}

bool lambertian::scatter(const ray &r_in, const hit_record &rec, color3 &attenuation, ray &scattered) const
{
    vector3 scatter_direction = rec.normal + vector3::random_unit_vector();
    if (scatter_direction.near_zero())
    {
        scatter_direction = rec.normal;
    }
    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}