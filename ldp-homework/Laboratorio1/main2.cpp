// esercizio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "namepairs.h"

using namespace std;

//Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for "labeling" the output and a vector.
void printVector(string label, vector<int>& vector) //Es 1
{
    cout << label << "\n";
    for (unsigned int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << "\n";
    }
}

/*Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a function,
fibonacci(x, y, v, n), where integers x and y are ints, v is an empty vector<int>, and n is the number of elements to put into v;
v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where each element is the sum of two previous ones.
For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, .... Your fibonacci() function should make such a sequence starting with
its x and y arguments.
*/
void fibonacci(int first, int second, vector<int>& vector, int n) //Es 2
{
    vector.resize(n);
    vector[0] = first; //First two numbers to use are passed through func. call and asigned here.
    vector[1] = second;

    for (int i = 2; i < n; i++)
    {
        vector[i] = vector[i - 1] + vector[i - 2];
    }
}

//An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().
void findMaxIntegerForFibonacci()
{
    int lastFib = 0;
    int temp = 0;
    int n = 3;

    vector<int> vector{1,2};
 
    do
    {
        fibonacci(vector[vector.size() - 2], vector[vector.size() - 1], vector, n++);
        temp = vector[vector.size() - 1];
        if (temp > 0)
        {
            lastFib = temp;
        }
    }while (temp > 0);
    cout << "\n Largest Fibonacci with Int was: " << lastFib << "\n";
}

/*Write two functions that reverse the order of elements in a vector<int>.
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function should produce a new vector with the reversed sequence,
leaving its original vector unchanged. The other reverse function should reverse the elements of its vector without using any other vectors.
*/
vector<int> reverseVectorOrderWithNewVector(vector<int>& vector)
{
    std::vector<int> newVector(vector.size());

    for (unsigned int i = 0; i < vector.size(); i++)
    {
        int reversedIndex = vector.size() - i - 1;
        newVector[i] = vector[reversedIndex];
    }
    return newVector;
}
void reverseVectorOrderWithOriginal(vector<int>& vector)
{
    int temp = 0;
    int reversedIndex = vector.size() - 1;

    for (unsigned int i = 0; i < vector.size(); i++)
    {
        temp = vector[reversedIndex - i];
        vector[reversedIndex - i] = vector[i];
        vector[i] = temp;
    }
}

std::ostream& operator<<(std::ostream& os, const namepairs& pairs)
{
    pairs.print(os);
    return os;
}

//Main
int main()
{
    namepairs namepairs1;
    namepairs1.read_names();
    namepairs1.read_ages();
    cout << endl << endl;
    cout << namepairs1 << endl;

    namepairs1.sort();
    cout << namepairs1 << endl;
}


