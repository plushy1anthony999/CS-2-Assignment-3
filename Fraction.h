#pragma once
#include <iostream>
#include <cmath>

class Fraction {
private:
	long Top;
	long Bottom;
	bool valid;

public:
	Fraction(long Top = 0, long	Bottom = 1);
	friend const Fraction operator + (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator - (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator * (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator / (const Fraction & num1, const Fraction & num2);
	friend bool operator == (const Fraction & num1, const Fraction & num2);
	friend bool operator != (const Fraction & num1, const Fraction & num2);
	friend std::ostream & operator << (std::ostream & output, const Fraction & num);
	friend std::istream & operator >> (std::istream & input, Fraction & num);

	Fraction operator ++ (); // Pre-increments the fraction
	Fraction operator -- (); // Pre-decrements the fraction

	long getTop() const;
	long getBottom() const;
	bool isValid() const;

	// Simplifies a fraction by reducing the top and bottom and handles neg sign
	void normalize();
	// Finds the greatest common divisor of two longs(treats both longs as positive)
	// Returns -1 if given 0 and 0
	long gcd(long a, long b);
};

