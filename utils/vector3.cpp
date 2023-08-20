#include "vector3.hpp"

vector3::vector3() : e{0, 0, 0} {}
vector3::vector3(double e1, double e2, double e3) : e{e1, e2, e3} {}

double vector3::x() const
{
    return e[0];
}
double vector3::y() const
{
    return e[1];
};
double vector3::z() const
{
    return e[2];
}

vector3 vector3::operator-() const
{
    return vector3(-e[0], -e[1], -e[2]);
}
double vector3::operator[](int i)
{
    return e[i];
}

vector3 &vector3::operator+=(const vector3 &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vector3 &vector3::operator*=(double t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vector3 &vector3::operator/=(double t)
{
    return *this *= 1 / t;
}

double vector3::length()
{
    return sqrt(lengthSquarred());
}

double vector3::lengthSquarred()
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

bool vector3::near_zero() const
{
    // Return true if the vector is close to zero in all dimensions.
    auto s = 1e-8;
    return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
}

double random_double()
{
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

double random_double(double min, double max)
{
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

vector3 vector3::random()
{
    return vector3(random_double(), random_double(), random_double());
}

vector3 vector3::random(double min, double max)
{
    return vector3(random_double(min, max), random_double(min, max), random_double(min, max));
}

vector3 vector3::random_in_unit_sphere()
{
    while (true)
    {
        auto p = vector3::random(-1, 1);
        if (p.lengthSquarred() < 1)
            return p;
    }
}

vector3 vector3::random_unit_vector()
{
    return unit_vector(random_in_unit_sphere());
}

vector3 vector3::random_on_hemisphere(const vector3 &normal)
{
    vector3 on_unit = random_unit_vector();
    if (dot(on_unit, normal) > 0.0)
    {
        return on_unit;
    }
    else
    {
        return -on_unit;
    }
}

//-----------------------------------------------------------------

std::ostream &
operator<<(std::ostream &out, const vector3 &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

vector3 operator+(const vector3 &u, const vector3 &v)
{
    return vector3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vector3 operator-(const vector3 &u, const vector3 &v)
{
    return vector3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vector3 operator*(const vector3 &u, const vector3 &v)
{
    return vector3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vector3 operator*(double t, const vector3 &v)
{
    return vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

vector3 operator*(const vector3 &v, double t)
{
    return t * v;
}

vector3 operator/(vector3 v, double t)
{
    return (1 / t) * v;
}

double dot(const vector3 &u, const vector3 &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

vector3 cross(const vector3 &u, const vector3 &v)
{
    return vector3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                   u.e[2] * v.e[0] - u.e[0] * v.e[2],
                   u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vector3 unit_vector(vector3 v)
{
    return v / v.length();
}

vector3 reflect(const vector3 &v, const vector3 &n)
{
    return v - 2 * dot(v, n) * n;
}