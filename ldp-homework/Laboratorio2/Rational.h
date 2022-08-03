#pragma once
#include <ostream>
#include <iostream>
class Rational
{
	public:
		Rational();
		Rational( int n, int d);
		void setDenominator( int d) { this->rDenominator = d; };
		void setNominator( int n) { this->rNominator = n; };
		int getDenominator() const { return rDenominator; };
		int getNominator() const { return rNominator; };
		double getDoubleNumber() const { 
			std::cout << std::endl << rNominator << "      " << rDenominator << std::endl;
			double ret = ((double)rNominator / (double)rDenominator);
			return ret;
		};
	private:
		 int getGreatestCommonDivisor( int n, int d);
		 int rNominator;
		 int rDenominator;
};

Rational operator+(const Rational& leftObj, const Rational& rightObj);
Rational operator+(const Rational& leftObj, const int& rightInt);
Rational operator+(const int& leftInt, const Rational& rightObj);

Rational operator-(const Rational& leftObj, const Rational& rightObj);
Rational operator-(const Rational& leftObj, const int& rightInt);
Rational operator-(const int& leftInt, const Rational& rightObj);

Rational operator*(const Rational& leftObj, const Rational& rightObj);
Rational operator*(const Rational& leftObj, const int& rightInt);
Rational operator*(const int& leftInt, const Rational& rightObj);

Rational operator/(const Rational& leftObj, const Rational& rightObj);
Rational operator/(const Rational& leftObj, const int& rightInt);
Rational operator/(const int& leftInt, const Rational& rightObj);

std::ostream& operator<<(std::ostream& os, const Rational& rational);