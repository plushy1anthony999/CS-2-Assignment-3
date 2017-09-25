#include "UnitTests.h"

using namespace std;

namespace UNIT_TESTS {
	void doUnitTesting() {
		cout << "Starting Unit Tests..." << endl << endl;
		testFractionClass();

		cout << "All tests passed" << endl;
	}

	void testFractionClass() {	
		// Test Fraction::gcd()
		Fraction fraction1(1, 2); // 1/2
		assert(fraction1.gcd(270, 192) == 6);
		assert(fraction1.gcd(6, 6) == 6);
		assert(fraction1.gcd(6, 2) == 2);
		assert(fraction1.gcd(-6, -2) == 2);
		assert(fraction1.gcd(-6, 2) == 2);
		assert(fraction1.gcd(0, 2) == 2);
		assert(fraction1.gcd(2, 0) == 2);
		assert(fraction1.gcd(192, 270) == 6);
		assert(fraction1.gcd(0, 0) == -1);
		assert(fraction1.gcd(-11, 7) == 1);
		assert(fraction1.gcd(-0, 2) == 2);
		assert(fraction1.gcd(-2, 0) == 2);
		assert(fraction1.gcd(-192, 270) == 6);
		assert(fraction1.gcd(-0, 0) == -1);
		assert(fraction1.gcd(-11, 7) == 1);

		// Test Fraction Constructor and normalize() and gcd()
		Fraction fraction2(-1, -2); // 1/2
		assert(fraction1.getTop() == 1);
		assert(fraction1.getBottom() == 2);

		assert(fraction2.getTop() == 1 && fraction2.getBottom() == 2);
		Fraction fraction3(270, 192);
		assert(fraction3.isValid() == true);
		assert(fraction3.getTop() == 45 && fraction3.getBottom() == 32);
		Fraction fraction4(6, 2);
		assert(fraction4.getTop() == 3 && fraction4.getBottom() == 1);
		assert(fraction4.isValid() == true);
		
		// Test Fraction::isValid()
		Fraction fraction5(-1, 0);
		assert(fraction5.isValid() == false);
		Fraction fraction6(0, 0);
		assert(fraction6.isValid() == false);
		Fraction fraction7(0, 1);
		assert(fraction7.isValid() == true);
		assert(fraction7.getTop() == 0 && fraction7.getBottom() == 1);

		Fraction fraction8(9, 3);
		assert(fraction8.getTop() == 3 && fraction8.getBottom() == 1);
		Fraction fraction9(10, 2);
		assert(fraction9.getTop() == 5 && fraction9.getBottom() == 1);
		Fraction fraction10(3, -9);
		assert(fraction10.getTop() == -1 && fraction10.getBottom() == 3);

		// Test Fraction::lcm()
		assert(Fraction::lcm(10, 10) == 10);
		assert(Fraction::lcm(0, 10) == -1);
		assert(Fraction::lcm(0, 0) == 0);
		assert(Fraction::lcm(10, 3) == 30);
		assert(Fraction::lcm(-10, 3) == -1);
		assert(Fraction::lcm(10, -3) == -1);
		assert(Fraction::lcm(-10, -3) == -30);
		assert(Fraction::lcm(3, 10) == 30);
		assert(Fraction::lcm(2, 3) == 6);
		assert(Fraction::lcm(99, -3) == -1);
		assert(Fraction::lcm(-15, -3) == -15);
		assert(Fraction::lcm(-1, -1) == -1);
		assert(Fraction::lcm(25, 10) == 50);

		// Fraction Operator +
		Fraction fraction11 = fraction1 + fraction2;
		assert(fraction11.getTop() == 1 && fraction11.getBottom() == 1);
		Fraction fraction12 = fraction4 + fraction7;
		assert(fraction12.getTop() == 3 && fraction12.getBottom() == 1);
		Fraction fraction13 = Fraction(-3, 9) + Fraction(1, -3);
		assert(fraction13.getTop() == -2 && fraction13.getBottom() == 3);
		Fraction fraction14 = Fraction(-3, 5) + Fraction(1, 15);
		assert(fraction14.getTop() == -8 && fraction14.getBottom() == 15);
		Fraction fraction15 = Fraction(2, -5) + Fraction(-1, 15);
		assert(fraction15.getTop() == -7 && fraction15.getBottom() == 15);

		// Fraction Operator -
		Fraction fraction16 = fraction1 - fraction2;
		assert(fraction16.getTop() == 0 && fraction16.getBottom() == 1);
		Fraction fraction17 = fraction1 - fraction8;
		assert(fraction17.getTop() == -5 && fraction17.getBottom() == 2);
		Fraction fraction18 = fraction8 - fraction9;
		assert(fraction18.getTop() == -2 && fraction18.getBottom() == 1);
		Fraction fraction19 = fraction9 - fraction10;
		assert(fraction19.getTop() == 16 && fraction19.getBottom() == 3);
		Fraction fraction20 = Fraction(-2, 9) - Fraction(3, -4);
		assert(fraction20.getTop() == 19 && fraction20.getBottom() == 36);
	}
}