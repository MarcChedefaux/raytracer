#include "triangle.hpp"

triangle::triangle(point3 p0, point3 p1, point3 p2, shared_ptr<material> m) : p0(p0), mat(m)
{
    u = p1 - p0;
    v = p2 - p0;
    n1 = unit_vector(cross(u, v));
    n2 = n1;
    n3 = n1;
    normal = n1;
}

triangle::triangle(point3 p0, point3 p1, point3 p2, vector3 normal, shared_ptr<material> m) : p0(p0), mat(m), normal(normal), n1(normal), n2(normal), n3(normal)
{
    u = p1 - p0;
    v = p2 - p0;
}

triangle::triangle(point3 p0, point3 p1, point3 p2, vector3 n1, vector3 n2, vector3 n3, shared_ptr<material> m) : p0(p0), mat(m), n1(n1), n2(n2), n3(n3)
{
    u = p1 - p0;
    v = p2 - p0;
    normal = unit_vector(cross(u, v));
}

bool triangle::hit(const ray &r, interval ray_t, hit_record &rec) const
{
    double a = dot((p0 - r.origin()), normal) / dot(r.direction(), normal);
    if (ray_t.surrounds(a))
    {
        point3 pos = r.at(a);
        vector3 C; // vector perpendicular to triangle's plane

        // edge 0
        vector3 edge0 = u;
        vector3 vp0 = pos - p0;
        C = cross(edge0, vp0);
        if (dot(normal, C) < 0)
            return false; // P is on the right side

        // edge 1
        vector3 edge1 = v - u;
        vector3 vp1 = pos - (p0 + u);
        C = cross(edge1, vp1);
        if (dot(normal, C) < 0)
            return false; // P is on the right side

        // edge 2
        vector3 edge2 = -v;
        vector3 vp2 = pos - (p0 + v);
        C = cross(edge2, vp2);
        if (dot(normal, C) < 0)
            return false; // P is on the right side;

        vector3 intersection = pos - p0;
        int factorX = dot(intersection, u);
        int factorY = dot(intersection, v);

        vector3 noInterpolated = (1 - factorX - factorY) * n1 + factorX * n2 + factorY * n3;
        noInterpolated = unit_vector(noInterpolated);

        rec.t = a;
        rec.p = pos;
        rec.set_face_normal(r, noInterpolated);
        rec.mat = mat;
        rec.isLighting = false;
        return true; // this ray hits the triangle
    }
    else
    {
        return false;
    }
}
