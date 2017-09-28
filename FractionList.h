#pragma once
#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <sstream>


class FractionList {
private:
	const static int MAX = 30;
	Fraction List[MAX];
	size_t num_elements;
	bool isSorted; // Tracks if List[] is in ascending order

public:
	FractionList();

	void addFraction(const Fraction & F);

	size_t getNumberOfElements() const;
	bool getSortState() const;
	bool isEmpty() const;
	bool isFull() const;

	const std::string toString() const;

	static void getInstance(FractionList & FL); // Reads in fractions from keyboard
	friend std::ostream & operator << (std::ostream & out, const FractionList & FL);
	friend std::istream & operator >> (std::istream & in, FractionList & FL);
};

