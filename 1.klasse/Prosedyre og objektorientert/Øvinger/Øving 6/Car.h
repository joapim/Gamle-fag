#pragma once
#include<iostream>
using namespace std;

class Car {
private:
	int freeSeats;
public:
	Car(int freeSeats); //Skal den st� �verst?
	bool hasFreeSeats();
	void reserveFreeSeat();
	
	void setFreeSeats(int freeSeats) {
		this->freeSeats = freeSeats;
	}

	int getFreeSeats() const{
		return freeSeats;
	}
};