#include <iostream>
#include "Car.h"
using namespace std;

bool Car::hasFreeSeats() {
	return getFreeSeats();
}

void Car::reserveFreeSeat() {
	setFreeSeats(getFreeSeats() - 1);
}

Car::Car(int freeSeats) :freeSeats(freeSeats) {}
