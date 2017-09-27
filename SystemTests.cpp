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
		cout << "Provide num: 10, den: 1" << endl;
		Fraction::getInstance(cin, fraction1);
		assert(fraction1.getTop() == 10 && fraction1.getBottom() == 1);
		
		// Fraction Operator >> for cin
		cout << "Provide num: 3, den: 2" << endl;
		cout << "Provide num: 3, den: 5" << endl;
		cout << "Provide num: 3, den: 1" << endl;
		Fraction fraction2;
		Fraction fraction3;
		Fraction fraction4;
		cin >> fraction2 >> fraction3 >> fraction4;
		assert(fraction2.getTop() == 3 && fraction2.getBottom() == 2);
		assert(fraction3.getTop() == 3 && fraction3.getBottom() == 5);
		assert(fraction4.getTop() == 3 && fraction4.getBottom() == 1);
		
		// Fraction Operator << for output-file
		cout << "Provide path to \"FractionTest-ouptut-1.txt\"" << endl;
		cout << "Enter full path to file to which to output the fraction: ";
		cin.ignore(10000, '\n');
		string outFile;
		getline(cin, outFile);
		ofstream out(outFile);
		if (!out.is_open()) {
			cout << "Failed to create output file" << endl;
		}
		else {
			cout << "Writing to file the fraction " << fraction4 << endl;
			out << fraction4;
			out.close();
		}
	}
}
