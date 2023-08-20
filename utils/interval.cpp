#include "interval.hpp"

interval::interval() : min(+infinity), max(-infinity) {}

interval::interval(double mi, double ma) : min(mi), max(ma) {}

bool interval::contains(double x) const
{
    return min <= x && x <= max;
}

bool interval::surrounds(double x) const
{
    return min < x && x < max;
}

const interval interval::empty(+infinity, -infinity);
const interval interval::universe(-infinity, +infinity);