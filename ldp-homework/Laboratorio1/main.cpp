// Laboratiorio1Programmazione.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Book.h"
using namespace std;

int main()
{
    Book book1 = Book();
    vector<int> book2Date {24, 9, 1999};
    Book book2 = Book("Fabio", book2Date, 51235, 12345, 98513, 'f');
    cout << book2;
}