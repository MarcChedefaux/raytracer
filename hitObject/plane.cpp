#include "plane.hpp"

plane::plane(point3 bl, point3 ur, shared_ptr<material> m) : bottomLeft(bl), mat(m)
{
    vector3 diff = ur - bl;
    if (diff.x() == 0)
    {
        u = vector3(0, diff.y(), 0);
        v = vector3(0, 0, diff.z());
    }
    else if (diff.y() == 0)
    {
        u = vector3(diff.x(), 0, 0);
        v = vector3(0, 0, diff.z());
    }
    else if (diff.z() == 0)
    {
        u = vector3(diff.x(), 0, 0);
        v = vector3(0, diff.y(), 0);
    }
    else
    {
        u = point3(ur.x(), bl.y(), ur.z()) - bl;
        v = vector3(0, ur.y() - bl.y(), 0);
    }
    normal = unit_vector(cross(u, v));
}

bool plane::hit(const ray &r, interval ray_t, hit_record &rec) const
{
    double a = dot((bottomLeft - r.origin()), normal) / dot(r.direction(), normal);
    if (ray_t.surrounds(a))
    {
        point3 pos = r.at(a);
        vector3 diffFromCenter = pos - bottomLeft;
        if (dot(diffFromCenter, u) <= u.lengthSquarred() && dot(diffFromCenter, v) <= v.lengthSquarred() && dot(diffFromCenter, u) >= 0 && dot(diffFromCenter, v) >= 0)
        {
            rec.t = a;
            rec.p = pos;
            rec.set_face_normal(r, normal);
            rec.mat = mat;
            rec.isLighting = false;

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}