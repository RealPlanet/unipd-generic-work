#include "namepairs.h"
#include <iostream>

void namepairs::read_names()
{
	std::string inputName = "";
	std::cout << "Input a sequence of names ( input 'q' to exit ): \n";
	while (std::cin >> inputName && inputName != "q")
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
	int index = ages.size();
	std::cout << "Input age for each name: \n";

	while (index < names.size())
	{
		std::cout << "Insert the age for: " << this->names[index] << "\n";
		do
		{
			std::cin >> inputAge;
		} while (inputAge < 0);
		
		
		this->ages.resize(ages.size() + 1);
		ages[index] = inputAge;
		index = ages.size();
	}
}

void namepairs::print()
{
	std::cout << " ( name , age)\n";
	if (names.size() != ages.size())
	{
		std::cout << "Name and age vectors arent of the same size\n";
		return;
	}

	for (int i = 0; i < names.size(); i++)
	{
		std::cout << " ( " << names[i] << " , " << ages[i] << " )\n";
	}
}
