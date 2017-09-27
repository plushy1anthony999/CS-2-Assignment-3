#include "FractionList.h"

using namespace std;

FractionList::FractionList() : isSorted(false), num_elements(0) {

}

void FractionList::addFraction(const Fraction & F) {
	if (num_elements != MAX) {
		List[num_elements] = F;
		num_elements++;
	}
	
	isSorted = false;
}

size_t FractionList::getNumberOfElements() {
	return num_elements;
}
bool FractionList::getSortState() {
	return isSorted;
}
bool FractionList::isEmpty() {
	return (num_elements == 0);
}
bool FractionList::isFull() {
	return (num_elements == MAX);
}

const string FractionList::toString() {
	stringstream sstream;
	
	for (size_t i = 0; i < num_elements; i++) {
		sstream << List[i].toString() << endl;
	}
	return sstream.str();
}

//ostream & operator << (ostream & out, const FractionList & FL) {
//
//}
//istream & operator >> (istream & in, FractionList & FL) {
//
//}