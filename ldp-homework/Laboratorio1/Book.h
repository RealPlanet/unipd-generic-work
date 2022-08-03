#pragma once
#include <string>
#include <vector>
#include <iostream>

class Book
{
private:
	class InvalidData {};
	std::string ISBN{ "" };
	std::string bookAuthor{ "" };
	std::string copyrightDate{ "" };
	bool checked_out = false;
public:
	//ISBN is set by passing each 5 digit sequence as it's own variable
	//Date is set by passing each part of it as it's own variable (day, month, year)
	Book(std::string newAuthor, std::vector<int> date, int n1, int n2, int n3, char lastDigit);
	Book();
	bool isBookCheckedOut() const { return checked_out; }
	std::string getISBN() const { return ISBN; }
	std::string getAuthor() const { return bookAuthor; }
	std::string getCopyrightDate() const { return copyrightDate; }
	bool isCheckedOut() const { return checked_out; }
	void setCheckedOut(bool newStatus) { checked_out = newStatus; }
	void setISBN(int n1, int n2, int n3, char lastDigit);
	void setAuthor(std::string newAuthor);
	void setCopyrightDate(std::vector<int> newDate);
	bool operator==(Book& second);
	bool operator!=(Book& second);
};

std::ostream& operator<<(std::ostream& os, Book& const book);

