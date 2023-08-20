#ifndef MATERIAL
#define MATERIAL

#include "../utils/common.hpp"
#include "../hitObject/hitObject.hpp"

class material
{
public:
    virtual ~material() = default;

    virtual bool scatter(const ray &r_in, const hit_record &rec, color3 &attenuation, ray &scattered) const = 0;
};

#endif