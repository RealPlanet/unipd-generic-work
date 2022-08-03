#include "Rect.h"

std::string Rect::what_shape() const
{
    return "Rect";
}

double Rect::perimeter() const
{
    return 2 * ( b_side + h_side );
}

double Rect::area() const
{
    return b_side * h_side;
}