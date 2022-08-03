#pragma once
#include "Shape.h"
class Rhombus : public Shape
{
protected:
	double diagonal_major;
	double diagonal_minor;
public:
	Rhombus(double _diag_maj, double _diag_min) : diagonal_major{ _diag_maj }, diagonal_minor{ _diag_min } {};
	std::string what_shape() const override;
	double perimeter() const override;
	double area() const override;

	double getSide() const; //Returns length of one side of the Rhombus
};

