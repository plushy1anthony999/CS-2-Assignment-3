#include "Fraction.h"
#include "UnitTests.h"
#include "SystemTests.h"

const bool UNIT_TESTING = true;
const bool SYSTEM_TESTING = true;

int main() {
	if (UNIT_TESTING) UNIT_TESTS::doUnitTesting();
	if (SYSTEM_TESTING) SYSTEM_TESTS::doSystemTesting();
}

