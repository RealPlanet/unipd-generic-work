#pragma once
#include "Iterator.h"
#include <vector>
class Vector_iterator : public Iterator
{
public:
	double* next() override;
	Vector_iterator(std::vector<double> v);
private:
	int cursor;
	std::vector<double> vectorToIterate;
};

