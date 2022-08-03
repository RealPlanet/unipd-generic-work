// Compito3Programmazione.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>

using namespace std;

void print_array10(ostream& os, int* a);

int main()
{
    //1.Allocate an array of ten ints on the free store using new
    int* freeStoreInts = new int[10]{ 0 };
    //5.Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to avariable p1.
    int arrayInts[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int* p1 = &arrayInts[0];

    //6.Allocate an array of ten ints, and assign its address to a variable p2
    int arrayInts2[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int* p2 = &arrayInts2[0];

    //4.Write   a   function   print_array10(ostream&   os,   int*   a)   that   prints   out   the   values   of   a(assumed to have ten elements) to os. + 2.Print the values of the ten ints to cout.
    print_array10(cout, freeStoreInts);
    //3.Deallocate the array (using delete[]).
    delete[] freeStoreInts;

    //7.Copy the values from the array pointed to by p1 into the array pointed to by p2.
    cout << "Ora con due pointer che puntano ad array diversi scambio i valori dei due array" << endl;
    for (int i = 0; i < 10; i++)
    {
        int* element_array_1 = p1 + i; //Get first element of array1
        int* element_array_2 = p2 + i ; //Get first element of array2

        *element_array_2 = *element_array_1; //From array 2 to array1
    }

    print_array10(cout, p1);
    print_array10(cout, p2);
    //8.Repeat 5-7 using a vector rather than an array
    cout << "Ora faccio la stessa cosa con due vector" << endl;
    vector<int> vectorInt0 = vector<int>{ 0,1,2,3,4,5,6,7,8,9 };
    vector<int> vectorInt1 = vector<int>{ 9,8,7,6,5,4,3,2,1,0 };
    for (int i = 0; i < vectorInt0.size(); i++)
    {
        vectorInt1[i] = vectorInt0[i];
    }
    for (int i = 0; i < vectorInt0.size(); i++)
    {
        cout << vectorInt0[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < vectorInt1.size(); i++)
    {
        cout << vectorInt1[i] << " ";
    }
}

//4.Write   a   function   print_array10(ostream&   os,   int*   a)   that   prints   out   the   values   of   a
//(assumed to have ten elements) to os.
void print_array10(ostream& os, int* a)
{
    for (int i = 0; i < 10; i++)
    {
        int* element_at_i = a + i;
        os << *element_at_i << " ";
    }
    os << endl;
}
