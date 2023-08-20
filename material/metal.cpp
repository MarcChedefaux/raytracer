#include "metal.hpp"

metal::metal(const color3 &a, double f) : albedo(a), fuzz(f) {}

bool metal::scatter(const ray &r_in, const hit_record &rec, color3 &attenuation, ray &scattered) const
{
    vector3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected + fuzz * vector3::random_unit_vector());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0);
}
