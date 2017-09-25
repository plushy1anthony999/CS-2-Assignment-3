#include "Fraction.h"


Fraction::Fraction(long Top, long Bottom) : Top(Top), Bottom(Bottom) {
	if (Bottom == 0)
		valid = false;
	else {
		valid = true;
		normalize();

	}
}

// Operator Overload Friend Functions for Fraction Class
//const Fraction operator + (const Fraction & num1, const Fraction & num2) {
//	
//}
//const Fraction operator - (const Fraction & num1, const Fraction & num2) {
//
//}
//const Fraction operator * (const Fraction & num1, const Fraction & num2) {
//
//}
//const Fraction operator / (const Fraction & num1, const Fraction & num2) {
//
//}
//bool operator == (const Fraction & num1, const Fraction & num2) {
//
//}
//bool operator != (const Fraction & num1, const Fraction & num2) {
//
//}
//std::ostream & operator << (std::ostream & output, const Fraction & num) {
//
//}
//std::istream & operator >> (std::istream & input, Fraction & num) {
//
//}
//
//Fraction Fraction::operator ++ () {
//
//}
//Fraction Fraction::operator-- () {
//
//}

long Fraction::getTop() const {
	return Top;
}
long Fraction::getBottom() const {
	return Bottom;
}
bool Fraction::isValid() const {
	return valid;
}

void Fraction::normalize() {
	if (valid) {
		if (Top > 0 && Bottom < 0) { // Moves neg from Bottom to Top
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