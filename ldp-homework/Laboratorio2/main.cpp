// Laboratorio2Programmazione.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

#include "Rational.h"
using namespace std;

int main()
{

    //ES-1
    Rational first{ 5, 2 };

    //FINE ES-1

    //ES-2
    ifstream f_numbers;
    f_numbers.open("sum_these_numbers.txt");
    if (f_numbers.is_open())
    {
        int sum_of_numbers = 0;
        string nextWord = "";
        int nextInt = 0;
        while (f_numbers >> nextInt)
        {
           
            sum_of_numbers += nextInt;
        }
        cout << "Sum of all ints in file of only ints is: " << sum_of_numbers << endl;
        f_numbers.close();
    }
    else
    {
        cout << "Couldn't open \" sum_these_numbers.txt \" " << endl;
    }
    //FINE ES-2
    
    //ES-3 (using same file as es-2)
    f_numbers.open("sum_these_numbers_from_text.txt");
    ofstream f_outputSum;
    f_outputSum.open("output_of_sum.txt");
    if (f_numbers.is_open() && f_outputSum.is_open())
    {  
        int sum_of_numbers = 0;
        string nextWord = "";
        int nextInt = 0;
        while (f_numbers >> nextWord)
        {
            try
            {
                nextInt = stoi(nextWord);
            }
            catch (invalid_argument)
            {
                continue;
            }

            sum_of_numbers += nextInt;
        }
        cout << "Sum of all ints in text file is: " << sum_of_numbers << endl;
        f_outputSum << "Sum of all ints in file is: " << sum_of_numbers << endl;
        f_numbers.close();
        f_outputSum.close();
    }
    else
    {
        cout << "Couldn't open \"sum_these_numbers_from_text.txt\"" << endl;
    }
    //FINE ES-3
}