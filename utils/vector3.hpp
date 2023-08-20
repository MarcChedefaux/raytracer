#ifndef VECTOR3
#define VECTOR3

#include <iostream>
#include <cmath>

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

    double length();
    double lengthSquarred();
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

using point3 = vector3;

#endif