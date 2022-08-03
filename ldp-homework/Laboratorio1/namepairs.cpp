#include "namepairs.h"
#include <iostream>
using namespace std;

void namepairs::read_names()
{
	string inputName = "";
	cout << "Input a sequence of names ( input 'q' to exit ): \n";
	while (cin >> inputName && inputName != "q")
	{
		int index = names.size();
		this->names.resize(names.size() + 1);
		names[index] = inputName;
	}
}
void namepairs::read_ages()
{
	if (names.size() < 1) return;
	double inputAge = 0;
	unsigned int index = ages.size();
	cout << "Input age for each name: \n";

	while (index < names.size())
	{
		cout << "Insert the age for: " << this->names[index] << "\n";
		do
		{
			cin >> inputAge;
		} while (inputAge < 0);
		
		
		this->ages.resize(ages.size() + 1);
		ages[index] = inputAge;
		index = ages.size();
	}
}
vector<string> namepairs::get_names()
{
	return names;
}
vector<double> namepairs::get_ages()
{
	return ages;
}
void namepairs::print(std::ostream& os = cout) const
{
	if (names.size() != ages.size())
	{
		os << "Name and age vectors arent of the same size\n";
		return;
	}

	for (int i = 0; i < names.size(); i++)
	{
		os << "Name: " << names[i] << " | Age: " << ages[i] << endl;
	}
}
void namepairs::sort()
{
	this->selectionSort();
}

bool namepairs::operator==(namepairs& const second)
{
	std::vector<std::string> first_names = get_names();
	std::vector<std::string> second_names = second.get_names();
	std::vector<double> first_ages = get_ages();
	std::vector<double> second_ages = second.get_ages();
	if (first_names.size() != second_names.size())
	{
		return false;
	}

	for (int i = 0; i < first_names.size(); i++) // O(n), needs to check all names
	{
		if (first_names[i] != second_names[i])
		{
			return false;
		}
	}

	for (int i = 0; i < first_ages.size(); i++) // O(n), needs to check all ages
	{
		if (first_ages[i] != second_ages[i])
		{
			return false;
		}
	}

	return true;
}

bool namepairs::operator!=(namepairs& const second)
{
	return !(*this == second);
}

void namepairs::selectionSort()
{
	int names_size = names.size();
	for (int i = 0; i < names_size; i++)
	{
		int min = i;
		for (int j = i + 1; j < names_size; j++)
		{
			if (names[j].compare(names[min]) < 0)
			{
				min = j;
			}
		}

		string tempString = names[min];
		double tempDouble = ages[min];

		names[min] = names[i];
		ages[min] = ages[i];

		names[i] = tempString;
		ages[i] = tempDouble;
	}
}
