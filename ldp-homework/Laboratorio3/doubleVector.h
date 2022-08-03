#pragma once

class doubleVector
{
public:
    doubleVector();
    doubleVector(int constnewSize);
    virtual ~doubleVector();
    int length() const{ return size; }
    void set(double _val, int const _index); //Unsafe and safe functions to set a value in the vector, safe_get checks for out of bounds
    void safe_set(double _val, int const _index);
    double get(int const _index) const; //Unsafe and safe functions to get a value in the vector, safe_get checks for out of bounds
    double safe_get(int const _index) const;
    double& operator[](int const _index) const;
private:
    int size;
    double* array_ptr; //Holds vector
    bool isIndexValid(int const _index) const{ return (_index > -1 && _index < size); };
};

