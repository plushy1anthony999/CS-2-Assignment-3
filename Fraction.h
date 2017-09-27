#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

class Fraction {
private:
	long Top;
	long Bottom;

public:
	Fraction(long Top = 0, long	Bottom = 1);
	friend const Fraction operator + (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator - (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator * (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator / (const Fraction & num1, const Fraction & num2);
	const Fraction operator ++ (); // Pre-increments the fraction
	const Fraction operator -- (); // Pre-decrements the fraction
	const Fraction operator ++ (int marker); // Post-increments the fraction
	const Fraction operator -- (int marker); // Post-decrements the fraction
	const Fraction operator - (); 
	friend bool operator == (const Fraction & num1, const Fraction & num2); // Will return false if either fraction is invalid
	friend bool operator != (const Fraction & num1, const Fraction & num2);
	friend std::ostream & operator << (std::ostream & output, const Fraction & num); // Prints to stdout or file
	friend std::istream & operator >> (std::istream & input, Fraction & num); // Reads from stdin or file



	long getTop() const;
	long getBottom() const;

	static void getInstance(std::istream & in, Fraction & emptyFraction); // Reads in from keyboard or file to construct a Fraction
	// Simplifies a fraction by reducing the top and bottom and handles neg sign
	void normalize();
	const std::string toString() const;
	double toDouble() const;
	// Finds the greatest common divisor of two longs(treats both longs as positive)
	// Returns -1 if given 0 and 0
	long gcd(long a, long b);
	// Finds the least common multiple
	// Returns -1 if either value is 0
	static long lcm(long a, long b);
};

