#include "DoubleVector.h"
#include <stdexcept>

using namespace std;

DoubleVector::DoubleVector() : size{0}, array_ptr{new double[0]} {}
DoubleVector::DoubleVector(int const newSize) : size{newSize}, array_ptr{new double[size]{0}} {}
DoubleVector::DoubleVector(std::initializer_list<double> list) : size{(int)list.size()}, array_ptr{new double[size]}
{
    copy(list.begin(), list.end(), array_ptr);
}
DoubleVector::DoubleVector(const DoubleVector& vector) : size{vector.length()}, array_ptr{new double[size]}
{
    copy(vector.array_ptr, vector.array_ptr + size, array_ptr);
}
DoubleVector::DoubleVector(  DoubleVector&& vector  ) : size{vector.length()}, array_ptr{vector.array_ptr}
{
    vector.size = 0;
    vector.array_ptr = nullptr;
}

DoubleVector::~DoubleVector()
{
    delete[] array_ptr;
}

void DoubleVector::set(double _val, int const _index)
{
    array_ptr[_index] = _val;
}

double DoubleVector::get(int const _index) const
{
    return array_ptr[_index];
}

void DoubleVector::safe_set(double _val, int const _index)
{
    if(!isIndexValid(_index))
    {
        throw std::out_of_range("");
    }
    
    set(_val, _index);
}

double DoubleVector::safe_get(int const _index) const
{
    if(!isIndexValid(_index))
    {
        throw std::out_of_range("");
    }
    
    return get(_index);
}

double& DoubleVector::operator[](int const _index)const
{
    return (array_ptr[_index]);
}

DoubleVector& DoubleVector::operator=(const DoubleVector& vector)
{
    double* arrNew = new double[vector.length()]{0};
    copy(vector.array_ptr, vector.array_ptr + vector.length(), arrNew);
    
    delete[] array_ptr;
    array_ptr = arrNew;
    size = vector.length();
    return *this;
}

DoubleVector& DoubleVector::operator=(DoubleVector&& vector)
{
    delete[] array_ptr;
    array_ptr = vector.array_ptr;
    size = vector.length();
    
    vector.array_ptr = nullptr;
    vector.size = 0;
    return *this;
}