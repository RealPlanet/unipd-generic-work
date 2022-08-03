#include "Rhombus.h"

std::string Rhombus::what_shape() const
{
    return "Rhombus";
}

double Rhombus::perimeter() const
{
    return getSide() * 4;
}

double Rhombus::area() const
{
    return (diagonal_major * diagonal_minor) / 2;
}

double Rhombus::getSide() const
{
    double part1 = diagonal_major / 2;
    double part2 = diagonal_minor / 2;

    part1 *= part1; // Power of 2
    part2 *= part2;

    return sqrt(part1 + part2);
}