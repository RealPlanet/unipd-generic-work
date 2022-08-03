#include "Rational.h"
#include <iostream>

Rational::Rational()
{
	this->rNominator = 0;
	this->rDenominator = 0;
}

Rational::Rational( int n, int d )
{
	if (d < 0)
	{
		d = 0 - d;
		n = 0 - n;
	}

	int gdc = getGreatestCommonDivisor(n, d);
	this->rNominator = n/gdc;
	this->rDenominator = d/gdc;
}


int Rational::getGreatestCommonDivisor( int n, int d)
{
	//Calculate GCD
	int tempN = n ;
	int tempD = d ;
	int gcd = n % d;

	if (tempN < 0)
	{
		tempN = 0 - tempN;
	}

	while (gcd != 0)
	{
		tempN = tempD;
		tempD = gcd;
		gcd = tempN % tempD;
	}

	gcd = tempD;
	return gcd;
}

bool operator==(const Rational& leftObj, const Rational& rightObj)
{
	return (leftObj.getDoubleNumber() == rightObj.getDoubleNumber());
}
bool operator!=(const Rational& leftObj, const Rational& rightObj)
{
	return !(leftObj == rightObj);
}
Rational operator+(const Rational& leftObj, const Rational& rightObj)
{
	int firstD = leftObj.getDenominator();
	int secondD = rightObj.getDenominator();

	int firstN = leftObj.getNominator();
	int secondN = rightObj.getNominator();

	int nominator = (secondD * firstN) + (firstD * secondN);
	int denominator = firstD * secondD;

	return Rational(nominator, denominator);
}
Rational operator+(const Rational& leftObj, const int& rightInt)
{
	Rational tempRational = Rational(rightInt, 1);

	return (leftObj + tempRational);
}
Rational operator+(const int& leftInt, const Rational& rightObj)
{
	return (rightObj + leftInt);
}

Rational operator-(const Rational& leftObj, const Rational& rightObj)
{
	int firstD = leftObj.getDenominator();
	int secondD = rightObj.getDenominator();

	int firstN = leftObj.getNominator();
	int secondN = rightObj.getNominator();

	int nominator = (secondD * firstN) - (firstD * secondN);
	int denominator = firstD * secondD;

	Rational result = Rational(nominator, denominator);
	return result;
}
Rational operator-(const Rational& leftObj, const int& rightInt)
{
	Rational tempRational = Rational(rightInt, 1);
	return (leftObj - tempRational);
}
Rational operator-(const int& leftInt, const Rational& rightObj)
{
	return (rightObj - leftInt);
}
Rational operator*(const Rational& leftObj, const Rational& rightObj)
{
	int newNominator = leftObj.getNominator() * rightObj.getNominator();
	int newDenominator = leftObj.getDenominator() * rightObj.getDenominator();

	return Rational(newNominator, newDenominator);
}
Rational operator*(const Rational& leftObj, const int& rightInt)
{
	Rational tempRational = Rational(rightInt, 1);
	return leftObj * tempRational;
}
Rational operator*(const int& leftInt, const Rational& rightObj)
{
	return (rightObj * leftInt);
}
Rational operator/(const Rational& leftObj, const Rational& rightObj)
{
	int newNominator = leftObj.getNominator() * rightObj.getDenominator();
	int newDenominator = rightObj.getNominator() * leftObj.getDenominator();

	return Rational(newNominator, newDenominator);
}
Rational operator/(const Rational& leftObj, const int& rightInt)
{
	Rational tempRational = Rational(rightInt, 1);
	return leftObj / tempRational;
}
Rational operator/(const int& leftInt, const Rational& rightObj)
{
	return (rightObj/leftInt);
}

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
	int n = rational.getNominator();
	int d = rational.getDenominator();
	if (n % d == 0)
	{
		os << rational.getDoubleNumber() << std::endl;
	}
	else
	{
		os << n << "\\" << d << std::endl;
	}
	return os;
}

