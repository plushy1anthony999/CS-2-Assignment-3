#pragma once
#include "Fraction.h"
#include <iostream>
#include <sstream>


class FractionList {
private:
	const static int MAX = 30;
	Fraction List[MAX];
	size_t num_elements;
	bool isSorted;

public:
	FractionList();

	void addFraction(const Fraction & F);

	size_t getNumberOfElements();
	bool getSortState();
	bool isEmpty();
	bool isFull();

	const std::string toString();

	friend std::ostream & operator << (std::ostream & out, const FractionList & FL);
	friend std::istream & operator >> (std::istream & in, FractionList & FL);
};

