#include <iostream>
#include "utilities.h"
using namespace std;

int randomWithLimits(int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;
}
