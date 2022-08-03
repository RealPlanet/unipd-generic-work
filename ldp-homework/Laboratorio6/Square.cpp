#include "Square.h"

std::string Square::what_shape() const
{
    return "Square";
}

double Square::perimeter() const
{
    return 4 * l_side;
}

double Square::area() const
{
    return l_side * l_side;
}
