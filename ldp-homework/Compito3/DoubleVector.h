#pragma once
#include <initializer_list>

class DoubleVector
{
public:
    DoubleVector();
    DoubleVector(int const newSize);
    DoubleVector( std::initializer_list<double> list );
    DoubleVector(  DoubleVector&& vector  );
    DoubleVector(const DoubleVector& vector);
    virtual ~DoubleVector();
    int length() const{ return size; }
    void set(double _val, int const _index); //Unsafe and safe functions to set a value in the vector, safe_get checks for out of bounds
    void safe_set(double _val, int const _index);
    double get(int const _index) const; //Unsafe and safe functions to get a value in the vector, safe_get checks for out of bounds
    double safe_get(int const _index) const;
    double& operator[](int const _index) const;
    DoubleVector& operator=(const DoubleVector& vector);
    DoubleVector& operator=(DoubleVector&& vector);
private:
    int size;
    double* array_ptr; //Holds vector
    bool isIndexValid(int const _index) const{ return (_index > -1 && _index < size); };
};

