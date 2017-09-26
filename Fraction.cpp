#include "Fraction.h"

using namespace std;

Fraction::Fraction(long Top, long Bottom) : Top(Top), Bottom(Bottom) {
	if (Bottom == 0)
		throw "Denominator cannot be zero";
	else 
		normalize();
}

// Operator Overload Friend Functions for Fraction Class
const Fraction operator + (const Fraction & num1, const Fraction & num2) {
	long lcm = Fraction::lcm(num1.Bottom, num2.Bottom);
	long num1Multiplier = lcm / num1.Bottom;
	long num2Multiplier = lcm / num2.Bottom;

	long newNum1Bottom = num1Multiplier * num1.Bottom;
	long newNum1Top = num1Multiplier * num1.Top;
	long newNum2Top = num2Multiplier * num2.Top;

	return Fraction(
		newNum1Top + newNum2Top,
		newNum1Bottom
	);
}
const Fraction operator - (const Fraction & num1, const Fraction & num2) {
	long lcm = Fraction::lcm(num1.Bottom, num2.Bottom);
	long num1Multiplier = lcm / num1.Bottom;
	long num2Multiplier = lcm / num2.Bottom;

	long newNum1Bottom = num1Multiplier * num1.Bottom;
	long newNum1Top = num1Multiplier * num1.Top;
	long newNum2Top = num2Multiplier * num2.Top;

	return Fraction(
		newNum1Top - newNum2Top,
		newNum1Bottom
	);
}
const Fraction operator * (const Fraction & num1, const Fraction & num2) {
	return Fraction(
		num1.getTop() * num2.getTop(),
		num1.getBottom() * num2.getBottom()
	);
}
const Fraction operator / (const Fraction & num1, const Fraction & num2) {
	return Fraction(
		num1.getTop() * num2.getBottom(),
		num1.getBottom() * num2.getTop()
	);
}
Fraction Fraction::operator ++ () {
	return (*this + 1);
}
Fraction Fraction::operator -- () {
	return (*this - 1);
}
bool operator == (const Fraction & num1, const Fraction & num2) {
	if (
		num1.getTop() == num2.getTop() &&
		num1.getBottom() == num2.getBottom()
	)
		return true;
	else
		return false;
}
bool operator != (const Fraction & num1, const Fraction & num2) {
	if (
		num1.getTop() == num2.getTop() &&
		num1.getBottom() == num2.getBottom()
		)
		return false;
	else
		return true;
}
std::ostream & operator << (std::ostream & output, const Fraction & num) {
	output << num.toString();
	return output;
}
std::istream & operator >> (std::istream & input, Fraction & num) {
	Fraction::getInstance(input, num);
	return input;
}

long Fraction::getTop() const {
	return Top;
}
long Fraction::getBottom() const {
	return Bottom;
}

void Fraction::getInstance(istream & in, Fraction & newFraction) {
	if (&in == &cin) {
		while (true) {
			try {
				long numerator;
				long denominator;
				cout << "Enter the fraction's numerator: ";
				in >> numerator;
				cout << endl;
				cout << "Enter the fraction's denominator: ";
				in >> denominator;
				cout << endl;

				newFraction = Fraction(numerator, denominator);
			}
			catch (const char * error) {
				cout << error << endl;			
			}
		}
	}
	else {
		long numerator;
		long denominator;
		in >> numerator >> denominator;
		newFraction = Fraction(numerator, denominator);
	}
}

void Fraction::normalize() {

	if (Top >= 0 && Bottom < 0) { // Moves neg from Bottom to Top
		Top = -Top;
		Bottom = abs(Bottom);
	}
	if (Top < 0 && Bottom < 0) { // If both Top and Bottom are negative, makes both positive
		Top = abs(Top);
		Bottom = abs(Bottom);
	}

	long divisor = gcd(Top, Bottom);
	Top /= divisor;
	Bottom /= divisor;
}

const string Fraction::toString() const {
	stringstream sstream;
	sstream << getTop() << '/' << getBottom();
	return sstream.str();
}
double Fraction::toDouble() const {
	return ((double)Top / (double)Bottom);
}

long Fraction::gcd(long a, long b) {
	if (a < 0) // Both numbers must be positive
		a = abs(a);
	if (b < 0)
		b = abs(b);

	if (a == 0 && b == 0) // At least one non-zero value is needed
		return -1;

	if (a == b) {
		return a; // return b is also valid
	}

	long tempA = -1;
	long tempB = -1;

	// Makes sure the denominator in tempA/tempB is smaller than numerator
	if (a > b) {
		tempA = a;
		tempB = b;
	}
	if (a < b) {
		tempA = b;
		tempB = a;
	}

	while (true) {	
		if (tempB == 0) // tempA should never be 0
			return tempA;

		long remainder = tempA % tempB;
		tempA = tempB;
		tempB = remainder;
	}
}
long Fraction::lcm(long a, long b) {
	if (a < 0 && b > 0) // If one num is pos and the other is neg, there's no lcm
		return -1;
	if (a > 0 && b < 0)
		return -1;

	bool negativeResult = false;
	if (a < 0) { // Both numbers must be positive
		a = abs(a);
		negativeResult = true;
	}
	if (b < 0) {
		b = abs(b);
		negativeResult = true;
	}

	if (a == b) {
		if (negativeResult) {
			return -a;
		}
		else
			return a; // return b is also valid
	}

	if (a == 0 || b == 0) 
		return -1;

	long originalA = a;
	long originalB = b;
	long incrementer = originalB;
	while (a != b) {
		if (a < b) { // Swap a and b to make sure a is the bigger num
			long temp = a;
			a = b;
			b = temp;

			if (incrementer == originalB)
				incrementer = originalA;
			else if (incrementer == originalA)
				incrementer = originalB;
		}	


		b += incrementer;
	}
	if (negativeResult) {
		return -a;
	}
	else 
		return a; // return b is also valid
}