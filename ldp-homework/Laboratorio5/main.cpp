// Laboratorio5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Iterator.h"
#include "List_iterator.h"
#include "Vector_iterator.h"
#include "PrintController.h"
#include "Shape.h"
#include "LevelController.h"

using namespace std;

void print(Iterator& it)
{
    double* nextIterator = it.next();
    while (nextIterator)
    {
        cout << *nextIterator << endl;
        nextIterator = it.next();
    }
}
/*
Write a template function f() that adds the elements of one vector<T> to the elements ofanother;
for example, f(v1, v2) should do v1[i] += v2[i] for each element of v1.
*/
template<typename T>
void f(vector<T>& v1, vector<T>& v2)
{
    for (int i = 0; i < v1.size() && i < v2.size(); i++)
    {
        v1[i] += v2[i];
    }
}

int main()
{
    vector<double> v1( 5, 10 );
    vector<double> v2( 4, 90 );
    list<double> l1( 5, 10 );

    f(v1, v2);

    List_iterator lIterator{ l1 };
    Vector_iterator vIterator{ v1 };

    print(lIterator);
    cout << endl;
    print(vIterator);

    PrintController controller1;
    controller1.show();

    
    Shape shapeTest;
    LevelController controller2(shapeTest);

    controller2.set_level(10);
}