#include "Book.h"
#include <iostream>

Book::Book(std::string newAuthor, std::vector<int> date, int n1, int n2, int n3, char lastDigit)
{
	this->setISBN(n1, n2, n3, lastDigit);
	this->setAuthor(newAuthor);
	this->setCopyrightDate(date);
}

Book::Book() {}

void Book::setISBN(int n1, int n2, int n3, char lastDigit)
{
	std::string first5digits = std::to_string(n1);
	std::string second5digits = std::to_string(n2);
	std::string third5digits = std::to_string(n3);

	//Using ISBN-10
	if (first5digits.size() > 5 || second5digits.size() > 5 || third5digits.size() > 5)
	{
		throw new InvalidData();
	}

	this->ISBN = first5digits + "-" + second5digits + "-" + third5digits + "-" + lastDigit;
}

void Book::setAuthor(std::string newAuthor)
{
	this->bookAuthor = newAuthor;
}

void Book::setCopyrightDate(std::vector<int> newDate)
{
	if (newDate.size() < 3)
	{
		throw new InvalidData();
	}

	int newDay = newDate[0];
	int newMonth = newDate[1];
	int newYear = newDate[2];

	std::string d = std::to_string(newDate[0]);
	std::string m = std::to_string(newDate[1]);
	std::string y = std::to_string(newDate[2]);

	if (newDay > 31 || newMonth > 12)
	{
		throw new InvalidData();
	}

	this->copyrightDate = d +"-"+ m +"-"+ y;
}

bool Book::operator==(Book& second)
{
	return (getISBN() == second.getISBN());
}

bool Book::operator!=(Book& second)
{
	return !(*this == second);
}

std::ostream& operator<<(std::ostream& os, Book& const book)
{
	std::string author = book.getAuthor();
	std::string copyrightDate = book.getCopyrightDate();
	std::string ISBN = book.getISBN();

	os << author << std::endl << copyrightDate << std::endl << ISBN;
	return os;
}