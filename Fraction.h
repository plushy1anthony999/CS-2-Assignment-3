#pragma once
#include <iostream>

class Fraction {
public:
	Fraction();
	friend const Fraction operator + (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator - (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator * (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator / (const Fraction & num1, const Fraction & num2);
	friend bool operator == (const Fraction & num1, const Fraction & num2);
	friend bool operator != (const Fraction & num1, const Fraction & num2);
	friend std::ostream & operator << (std::ostream & output, const Fraction & num);
	friend std::istream & operator >> (std::istream & input, Fraction & num);
};

