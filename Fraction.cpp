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