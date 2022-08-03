#pragma once
#include "Shape.h"
class Rect : public Shape
{
protected:
	double b_side;
	double h_side;
public:
	Rect(double b, double h) : b_side{ b }, h_side{h} {};
	std::string what_shape() const override;
	double perimeter() const override;
	double area() const override;
};

