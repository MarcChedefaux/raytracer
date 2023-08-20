#ifndef INTERVAL
#define INTERVAL

#include "common.hpp"

class interval
{
public:
    double min, max;

    interval();
    interval(double mi, double ma);

    bool contains(double x) const;
    bool surrounds(double x) const;
    double clamp(double x) const;

    static const interval empty, universe;
};

#endif