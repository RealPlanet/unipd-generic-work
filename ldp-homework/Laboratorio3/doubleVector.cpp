#include "doubleVector.h"
#include <stdexcept>

doubleVector::doubleVector()
{
    array_ptr = new double[0];
    size = 0;
}

doubleVector::doubleVector(int newSize)
{
    array_ptr = new double[newSize]{0};
    size = newSize;
}

doubleVector::~doubleVector()
{
    delete[] array_ptr;
}

void doubleVector::set(double _val, int const _index)
{
    double* address = array_ptr + _index;
    *address = _val;
}

double doubleVector::get(int const _index) const
{
    double* address = array_ptr + _index;
    double value = *address;
    return value;
}

void doubleVector::safe_set(double _val, int const _index)
{
    if(!isIndexValid(_index))
    {
        throw std::out_of_range("");
    }
    
    set(_val, _index);
}

double doubleVector::safe_get(int const _index) const
{
    if(!isIndexValid(_index))
    {
        throw std::out_of_range("");
    }
    
    return get(_index);
}

double& doubleVector::operator[](int const _index)const
{
    double* value = (array_ptr + _index);
    return *value;
}