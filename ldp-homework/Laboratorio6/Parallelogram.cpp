#include "Parallelogram.h"

std::string Parallelogram::what_shape() const
{
    return "Parallelogram";
}

double Parallelogram::perimeter() const
{
    return 2 * (b_side + l_side);
}
