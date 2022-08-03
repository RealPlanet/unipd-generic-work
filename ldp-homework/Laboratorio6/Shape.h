#pragma once
#include <string>
class Shape
{
/* Tutte le classi che ereditano Shape, se hanno variabili private, vengono impostate come protected cosi
	altre classi che ereditano possono accedere ad esse
*/
public:
	virtual std::string what_shape() const= 0;
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
};

