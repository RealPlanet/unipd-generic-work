#pragma once
#include "Shape.h"
class Square : public Shape
{
private:
	double l_side; //length of one side
public:
	Square(double sidelength) : l_side{ sidelength } {};
	std::string what_shape() const override;
	double perimeter() const override;
	double area() const override;
};

