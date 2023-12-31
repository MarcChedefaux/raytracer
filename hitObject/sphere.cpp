#include "sphere.hpp"

sphere::sphere(point3 c, double r, shared_ptr<material> m) : center(c), radius(r), mat(m) {}

bool sphere::hit(const ray &r, interval ray_t, hit_record &rec) const
{
    vector3 oc = r.origin() - center;
    auto a = r.direction().lengthSquarred();
    auto half_b = dot(oc, r.direction());
    auto c = oc.lengthSquarred() - radius * radius;

    auto discriminant = half_b * half_b - a * c;
    if (discriminant < 0)
        return false;
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (!ray_t.surrounds(root))
    {
        root = (-half_b + sqrtd) / a;
        if (!ray_t.surrounds(root))
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vector3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat = mat;
    rec.isLighting = false;

    return true;
}