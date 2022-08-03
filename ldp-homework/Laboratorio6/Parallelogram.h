#pragma once
#include "Rect.h"
class Parallelogram : public Rect
{
protected:
	double l_side; // Lato obliquo della forma

public:
	Parallelogram(double b, double h, double l) : Rect(b, h), l_side{ l } {};
	std::string what_shape() const override;
	double perimeter() const override;
};

