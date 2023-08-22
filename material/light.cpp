#include "light.hpp"

light::light(const color3 &a, double i) : albedo(a), intensity(i) {}

bool light::scatter(const ray &r_in, hit_record &rec, color3 &attenuation, ray &scattered) const
{
    rec.isLighting = true;
    attenuation = intensity * albedo;
    return false;
}