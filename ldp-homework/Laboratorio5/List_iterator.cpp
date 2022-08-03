#include "List_iterator.h"
using namespace std;

double* List_iterator::next()
{
	if (cursor != listToIterate.end())
	{
		return &*cursor++;
	}
	return 0;
}

List_iterator::List_iterator(std::list<double> l)
{
	listToIterate = l;
	cursor = listToIterate.begin();
}
