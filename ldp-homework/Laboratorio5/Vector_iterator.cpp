#include "Vector_iterator.h"
using namespace std;

double* Vector_iterator::next()
{
	if (cursor < vectorToIterate.size())
	{
		return &vectorToIterate[cursor++];
	}

	return 0;
}

Vector_iterator::Vector_iterator(std::vector<double> v) : vectorToIterate{ v }, cursor{ 0 } {}
