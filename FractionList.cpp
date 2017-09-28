#include "FractionList.h"

using namespace std;

FractionList::FractionList() : isSorted(false), num_elements(0) {

}

void FractionList::addFraction(const Fraction & F) {
	if (num_elements != MAX) {
		List[num_elements] = F;
		num_elements++;

		isSorted = false;
	}
	else
		cout << "Fraction can't be added since the list has reached its max size of " << MAX << endl;
}

size_t FractionList::getNumberOfElements() const {
	return num_elements;
}
bool FractionList::getSortState() const {
	return isSorted;
}
bool FractionList::isEmpty() const {
	return (num_elements == 0);
}
bool FractionList::isFull() const {
	return (num_elements == MAX);
}

const string FractionList::toString() const {
	stringstream sstream;
	
	for (size_t i = 0; i < num_elements; i++) {
		sstream << List[i].toString() << endl;
	}
	return sstream.str();
}

void FractionList::getInstance(FractionList & FL) {
	if (!FL.isFull()) {
		cout << "Adding to FractionList..." << endl;

		while (!FL.isFull()) {
			Fraction fraction;
			Fraction::getInstance(cin, fraction);
			FL.addFraction(fraction);

			bool addMore = false;
			cout << "Add another fraction? (0 for no, 1 for yes): ";
			cin >> addMore;

			if (!addMore)
				return;
		}
	}
}

ostream & operator << (ostream & out, const FractionList & FL) {
	out << FL.toString();
	return out;
}
istream & operator >> (istream & in, FractionList & FL) {
	if (&in == &cin) {
		FractionList::getInstance(FL);
		return in;
	}
	else {
		if (((ifstream &)in).is_open()) {
			while (!in.eof()) {
				if (in.peek() != ifstream::traits_type::eof()) { // Make sure file isn't empty
					Fraction fraction;
					in >> fraction;
					FL.addFraction(fraction);				
				}
			}
			return in;
		}
		else {
			cout << "File could not be opened" << endl;
			return in;
		}
	}
}