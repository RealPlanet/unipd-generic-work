// esercizio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "namepairs.h"

//Write a function print() that prints a vector of ints to cout. Give it two arguments: a string for "labeling" the output and a vector.
void printVector(std::string label, std::vector<int>& vector) //Es 1
{
    std::cout << label << "\n";
    for (unsigned int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\n";
    }
}

/*Create a vector of Fibonacci numbers and print them using the function from exercise 2. To create the vector, write a function,
fibonacci(x, y, v, n), where integers x and y are ints, v is an empty vector<int>, and n is the number of elements to put into v;
v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where each element is the sum of two previous ones.
For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, .... Your fibonacci() function should make such a sequence starting with
its x and y arguments.
*/
void fibonacci(int first, int second, std::vector<int>& vector, int n) //Es 2
{
    vector.resize(n);
    vector[0] = first; //First two numbers to use are passe through func. call and asigned here.
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

    std::vector<int> vector{1,2};
 
    do
    {
        fibonacci(vector[vector.size() - 2], vector[vector.size() - 1], vector, n++);
        temp = vector[vector.size() - 1] + vector[vector.size() - 2];
        if (temp > 0)
        {
            lastFib = temp;
        }
    }while (temp > 0);
    std::cout << "\n Largest Fibonacci with Int was: " << lastFib << "\n";
}

/*Write two functions that reverse the order of elements in a vector<int>.
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function should produce a new vector with the reversed sequence,
leaving its original vector unchanged. The other reverse function should reverse the elements of its vector without using any other vectors.
*/
std::vector<int> reverseVectorOrderWithNewVector(std::vector<int>& vector)
{
    std::vector<int> newVector;
    newVector.resize(vector.size());
    for (unsigned int i = 0; i < vector.size(); i++)
    {
        int reversedIndex = vector.size() - i - 1;
        newVector[i] = vector[reversedIndex];
    }
    return newVector;
}
void reverseVectorOrderWithOriginal(std::vector<int>& vector)
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

//Main
int main()
{
    
    std::vector<int> vector{0,1,2,3,4,5,6};
    std::vector<int> reversedVector = reverseVectorOrderWithNewVector(vector);

    printVector("\n Original \n", vector);
    printVector("\n Reversed with new vector\n", reversedVector);

    reverseVectorOrderWithOriginal(vector);
    printVector("\n Reversed with original vector\n", vector);
    
    findMaxIntegerForFibonacci();

    namepairs namepairs;
    namepairs.read_names();
    namepairs.read_ages();
    namepairs.print(); 
}

