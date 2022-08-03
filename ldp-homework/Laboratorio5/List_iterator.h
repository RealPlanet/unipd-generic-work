#pragma once
#include "Iterator.h"
#include <list>

class List_iterator : public Iterator
{
public:
	double* next() override;
	List_iterator(std::list<double> l);
private:
	std::list<double>::iterator cursor;
	std::list<double> listToIterate;
};

