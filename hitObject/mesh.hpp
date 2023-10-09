#ifndef MESH
#define MESH

#include "hitObject.hpp"
#include "triangle.hpp"
#include "../material/material.hpp"

class mesh : public hitObject
{
private:
    std::vector<shared_ptr<hitObject>> triangles;

public:
    mesh(std::string filepath, float multiplicator, point3 pos, shared_ptr<material> m);

    bool hit(const ray &r, interval ray_t, hit_record &rec) const;
};

#endif