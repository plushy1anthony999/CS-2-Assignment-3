#include "SystemTests.h"

using namespace std;

namespace SYSTEM_TESTS {
	void doSystemTesting() {
		cout << "Starting System Tests..." << endl << endl;
		testFractionClass();

		cout << "All tests passed" << endl;

	}

	void testFractionClass() {
		// Test Fraction::getInstance()
		Fraction fraction1;
		Fraction::getInstance(cin, fraction1);
		assert(fraction1.getTop() == 10 && fraction1.getBottom() == 1);
		
		// Fraction Operator >> for cout
		Fraction fraction2;
		Fraction fraction3;
		Fraction fraction4;
		cin >> fraction2 >> fraction3 >> fraction4;
		assert(fraction2.getTop() == 3 && fraction2.getBottom() == 2);
		assert(fraction3.getTop() == 3 && fraction3.getBottom() == 5);
		assert(fraction4.getTop() == 3 && fraction4.getBottom() == 1);
		
		// Fraction Operator >> for output-file
		cout << "Enter full path to file to which to output the fraction: ";
		cin.sync();
		string outFile;
		getline(cin, outFile);
		ofstream out(outFile);
		if (!out.is_open()) {
			cout << "Failed to create output file" << endl;
		}
		else {
			cout << "The fraction read from file is: " << fraction4 << endl;	
			cout << "Writing to file..." << endl;
			out << fraction4;
			out.close();
		}
	}
}
