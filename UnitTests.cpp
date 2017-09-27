#include "UnitTests.h"
#include "FractionList.h"

using namespace std;

namespace UNIT_TESTS {
	void doUnitTesting() {
		cout << "Starting Unit Tests..." << endl << endl;
		testFractionClass();
		testFractionListClass();

		cout << "All tests passed" << endl << endl;
	}

	void testFractionClass() {	
		// Test Fraction::gcd()
		Fraction fraction1(1, 2);
		assert(fraction1.gcd(4, 8) == 4);
		assert(fraction1.gcd(-4, -8) == 4);
		assert(fraction1.gcd(4, -8) == 4);
		assert(fraction1.gcd(-4, 8) == 4);
		assert(fraction1.gcd(0, 8) == 8);
		assert(fraction1.gcd(0, -8) == 8);
		assert(fraction1.gcd(0, 0) == 0);
		assert(fraction1.gcd(0, 0) == 0);
		assert(fraction1.gcd(3, 11) == 1);
		assert(fraction1.gcd(270, 192) == 6);
		assert(fraction1.gcd(6, 6) == 6);
		assert(fraction1.gcd(6, 2) == 2);
		assert(fraction1.gcd(-6, -2) == 2);
		assert(fraction1.gcd(-6, 2) == 2);
		assert(fraction1.gcd(0, 2) == 2);
		assert(fraction1.gcd(2, 0) == 2);
		assert(fraction1.gcd(192, 270) == 6);
		assert(fraction1.gcd(-11, 7) == 1);
		assert(fraction1.gcd(-0, 2) == 2);
		assert(fraction1.gcd(-2, 0) == 2);
		assert(fraction1.gcd(-192, 270) == 6);
		assert(fraction1.gcd(-0, 0) == 0);
		assert(fraction1.gcd(-11, 7) == 1);

		// Test Fraction Constructor and normalize() and gcd()
		Fraction fraction2(-1, -2); // 1/2
		assert(fraction1.getTop() == 1);
		assert(fraction1.getBottom() == 2);

		assert(fraction2.getTop() == 1 && fraction2.getBottom() == 2);
		Fraction fraction3(270, 192);
		assert(fraction3.getTop() == 45 && fraction3.getBottom() == 32);
		Fraction fraction4(6, 2);
		assert(fraction4.getTop() == 3 && fraction4.getBottom() == 1);
		
		// Test if Fraction handle divide by zero
		unsigned int errorCount = 0;
		Fraction fraction5;
		try {
			fraction5 = Fraction(-1, 0);
		}
		catch (const char * error) {
			errorCount++;
			cout << error << endl;
		}
		Fraction fraction6;
		try {
			fraction6 = Fraction(0, 0);
		}
		catch (const char * error) {
			errorCount++;
			cout << error << endl;
		}
		Fraction fraction7;
		try {
			fraction7 = Fraction(0, 1);
		}
		catch (const char * error) {
			errorCount++;
			cout << error << endl;
		}
		assert(fraction7.getTop() == 0 && fraction7.getBottom() == 1);
		assert(errorCount == 2);

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

		// Fraction Operator *
		Fraction fraction21 = fraction1 * fraction2;
		assert(fraction21.getTop() == 1 && fraction21.getBottom() == 4);
		Fraction fraction22 = fraction9 * fraction10;
		assert(fraction22.getTop() == -5 && fraction22.getBottom() == 3);
		Fraction fraction23 = fraction9 * fraction1;
		assert(fraction23.getTop() == 5 && fraction23.getBottom() == 2);
		Fraction fraction24 = fraction10 * fraction1;
		assert(fraction24.getTop() == -1 && fraction24.getBottom() == 6);

		// Fraction Operator /
		Fraction fraction25 = fraction1 / fraction2;
		assert(fraction25.getTop() == 1 && fraction25.getBottom() == 1);
		Fraction fraction26 = fraction1 / fraction10;
		assert(fraction26.getTop() == -3 && fraction26.getBottom() == 2);
		Fraction fraction27 = fraction9 / fraction10;
		assert(fraction27.getTop() == -15 && fraction27.getBottom() == 1);
		Fraction fraction28 = fraction10 / fraction9;
		assert(fraction28.getTop() == -1 && fraction28.getBottom() == 15);

		// Fraction Operator ++
		assert(++fraction1 == Fraction(3, 2));
		assert(++fraction2 == Fraction(3, 2));
		assert(++fraction4 == Fraction(4, 1));
		assert(++fraction7 == Fraction(1, 1));
		assert(++fraction8 == Fraction(4, 1));
		assert(++fraction9 == Fraction(6, 1));

		// Fraction Operator --
		assert(--fraction1 == Fraction(-1, 2));
		assert(--fraction2 == Fraction(-1, 2));
		assert(--fraction4 == Fraction(2, 1));
		assert(--fraction7 == Fraction(-1, 1));
		assert(--fraction8 == Fraction(2, 1));
		assert(--fraction9 == Fraction(4, 1));

		// Fraction Operator ==
		assert(fraction1 == fraction2);
		Fraction fraction29(3, 1);
		assert(fraction29 == fraction8);
		Fraction fraction30(-1, 3);
		assert(fraction10 == fraction30);
		Fraction fraction31(0, 21);
		assert(fraction7 == fraction31);

		// Fraction Operator !=
		assert((fraction1 != fraction2) == false);
		assert((fraction29 != fraction8) == false);
		assert((fraction10 != fraction30) == false);
		assert((fraction7 != fraction31) == false);

		// Fraction Operator <<
		cout << fraction1.toDouble() << endl
			 << fraction2.toDouble() << endl
			 << fraction3.toDouble() << endl
			 << fraction4.toDouble() << endl
			 << fraction7.toDouble() << endl
			 << fraction8.toDouble() << endl
			 << fraction9.toDouble() << endl;

		// Fraction Operator >>
		array<Fraction, 6> fractions;
		ifstream infile("FractionTest-1.txt");
		if (infile.is_open()) {
			for (size_t i = 0; !infile.eof() && i < 6; i++) {
				Fraction fraction;
				infile >> fractions[i];
			}
		}
		assert(fractions[0].getTop() == 2 && fractions[0].getBottom() == 3);
		assert(fractions[1].getTop() == 4 && fractions[1].getBottom() == 5);
		assert(fractions[2].getTop() == 11 && fractions[2].getBottom() == 1);
		assert(fractions[3].getTop() == 3 && fractions[3].getBottom() == 1);
		assert(fractions[4].getTop() == 4 && fractions[4].getBottom() == 67);
		assert(fractions[5].getTop() == 1 && fractions[5].getBottom() == 1);

		// Test toString()		
		assert(fraction1.toString() == "1/2");
		assert(fraction2.toString() == "1/2");
		assert(fraction3.toString() == "45/32");
		assert(fraction4.toString() == "3/1");
		assert(fraction7.toString() == "0/1");
		assert(fraction10.toString() == "-1/3");
		Fraction fraction32(2, -14);
		assert(fraction32.toString() == "-1/7");
		Fraction fraction33(0, -12);		
		assert(fraction33.toString() == "0/1");
		Fraction fraction34(-2, -6);
		assert(fraction34.toString() == "1/3");
		Fraction fraction35(-5);
		assert(fraction35.toString() == "-5/1");
		assert((Fraction(1, 3) + Fraction(2, 3)).toString() == "1/1");
		assert((Fraction(2, 4) + Fraction(1, -2)).toString() == "0/1");

		// Test toDouble()		
		assert(fraction1.toDouble() == 0.5);
		assert(fraction2.toDouble() == 0.5);
		assert(fraction3.toDouble() == 1.40625);
		assert(fraction4.toDouble() == 3);
		assert(fraction7.toDouble() == 0);
		assert(fraction33.toDouble() == 0);
		assert(fraction8.toDouble() == 3);
		assert(fraction9.toDouble() == 5);
		assert((Fraction(1, 4) + Fraction(4, -16)).toDouble() == 0);
		assert((Fraction(1, 2) / Fraction(1, 3)).toDouble() == 1.5);
		Fraction F2(6, -12);	
		Fraction F3(-9, 12);
		assert((2 + F2).toDouble() == 1.5);
		assert((2 - F2).toDouble() == 2.5);

		// Fraction Operator ++ Post-increment
		Fraction fraction36(2, 4);
		assert((fraction36++) == Fraction(1, 2));
		assert(fraction36 == Fraction(3, 2));
		Fraction fraction37(-3, 9);
		assert((fraction37++) == Fraction(-1, 3));
		assert(fraction37 == Fraction(2, 3));
		assert(fraction37++ == Fraction(2, 3));
		assert(fraction37 == Fraction(5, 3));
		Fraction fraction38(0, -9);
		assert(fraction38++ == Fraction(0, 1));
		assert(fraction38 == Fraction(1, 1));

		// Fraction Operator -- Post-decrement
		Fraction fraction39(0, -1);
		assert(fraction39-- == Fraction(0, 1));
		assert(fraction39 == Fraction(-1, 1));
		Fraction fraction40(3, -9);
		assert(fraction40-- == Fraction(-1, 3));
		assert(fraction40 == Fraction(-4, 3));
		Fraction fraction41(-2, -7);
		assert(fraction41-- == Fraction(2, 7));
		assert(fraction41 == Fraction(-5, 7));

		// Fraction Operator - negate
		assert((-Fraction(1, 2)) == Fraction(-1, 2));
		assert((-Fraction(3, -9)) == Fraction(1, 3));
		assert((-Fraction(12, 24)) == Fraction(-1, 2));
		assert((-Fraction(0, -1)) == Fraction(0, 1));
		assert((-Fraction(-3, -12)) == Fraction(-1, 4));
	}
	void testFractionListClass() {
		// FractionList Constructor, getSortState(), isEmpty(), isFull(), getNumberOfElements()
		assert(FractionList().getSortState() == false);
		assert(FractionList().isEmpty() == true);
		assert(FractionList().isFull() == false);
		assert(FractionList().getNumberOfElements() == 0);
	}
}