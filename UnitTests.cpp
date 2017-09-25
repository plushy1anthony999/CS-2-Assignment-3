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
		Fraction fraction2(-1, -2); // 1/3
		assert(fraction1.getTop() == 1);
		assert(fraction1.getBottom() == 2);

		assert(fraction2.getTop() == 1 && fraction2.getBottom() == 2);
		Fraction fraction3(270, 192);
		assert(fraction3.isValid() == true);
		assert(fraction3.getTop() == 45 && fraction3.getBottom() == 32);
		Fraction fraction4(6, 2);
		assert(fraction4.getTop() == 3, fraction4.getBottom() == 1);
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
	}
}