#pragma once
#include <vector>
#include <iostream>
#include <string>

/*
Design and implement a Name_pairs class holding (name, age) pairs where name is a string and age is a double.
Represent that as a vector<string> (called name) and a vector<double> (called age) member.
Provide an input operation read_names() that reads a series of names (you can choose how to stop the input series).
Provide a read_ages() operation that prompts the user for an age for each name,
Provide a print() operation that prints out the (name[i], age[i]) pairs (one per line) in the order determined by the name vector.
*/
class namepairs
{
public:
	void read_names();
	void read_ages();
	std::vector<std::string> get_names();
	std::vector<double> get_ages();
	void print(std::ostream& os) const;
	void sort();
	bool operator==(namepairs& const second);
	bool operator!=(namepairs& const second);
private:
	void selectionSort();
	std::vector<std::string> names;
	std::vector<double> ages;
};

