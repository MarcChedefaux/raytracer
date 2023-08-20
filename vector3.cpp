#include "vector3.hpp"

vector3::vector3() : e{0,0,0} {}
vector3::vector3(double e1, double e2, double e3) : e{e1,e2,e3} {}

double vector3::x() {
    return e[0];
}
double vector3::y() {
    return e[1];
};
double vector3::z() {
    return e[2];
}

vector3 vector3::operator-() {
    return vector3(-e[0], -e[1], -e[2]);
}
double vector3::operator[](int i) {
    return e[i];
}

vector3& vector3::operator+=(const vector3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vector3& vector3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vector3& vector3::operator/=(double t) {
    return *this *= 1/t;
}

double vector3::length() {
    return sqrt(lengthSquarred());
}

double vector3::lengthSquarred() {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

//-----------------------------------------------------------------

std::ostream& operator<<(std::ostream &out, const vector3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

vector3 operator+(const vector3 &u, const vector3 &v) {
    return vector3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vector3 operator-(const vector3 &u, const vector3 &v) {
    return vector3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vector3 operator*(const vector3 &u, const vector3 &v) {
    return vector3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vector3 operator*(double t, const vector3 &v) {
    return vector3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

vector3 operator*(const vector3 &v, double t) {
    return t * v;
}

vector3 operator/(vector3 v, double t) {
    return (1/t) * v;
}

double dot(const vector3 &u, const vector3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

vector3 cross(const vector3 &u, const vector3 &v) {
    return vector3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vector3 unit_vector(vector3 v) {
    return v / v.length();
}