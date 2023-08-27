#ifndef VECTOR3
#define VECTOR3

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

class vector3
{
public:
    double e[3];

    vector3();
    vector3(double e1, double e2, double e3);

    double x() const;
    double y() const;
    double z() const;

    vector3 operator-() const;
    double operator[](int i);

    vector3 &operator+=(const vector3 &v);

    vector3 &operator*=(double t);

    vector3 &operator/=(double t);

    double length() const;
    double lengthSquarred() const;

    bool near_zero() const;

    static vector3 random();
    static vector3 random(double min, double max);
    static vector3 random_in_unit_sphere();
    static vector3 random_unit_vector();
    static vector3 random_on_hemisphere(const vector3 &normal);
    static vector3 random_in_unit_disk();
};

extern std::ostream &operator<<(std::ostream &out, const vector3 &v);
extern vector3 operator+(const vector3 &u, const vector3 &v);
extern vector3 operator-(const vector3 &u, const vector3 &v);
extern vector3 operator*(const vector3 &u, const vector3 &v);
extern vector3 operator*(double t, const vector3 &v);
extern vector3 operator*(const vector3 &v, double t);
extern vector3 operator/(vector3 v, double t);
extern double dot(const vector3 &u, const vector3 &v);
extern vector3 cross(const vector3 &u, const vector3 &v);
extern vector3 unit_vector(vector3 v);
extern vector3 reflect(const vector3 &v, const vector3 &n);
extern vector3 refract(const vector3 &uv, const vector3 &n, double etai_over_etat);

using point3 = vector3;

#endif