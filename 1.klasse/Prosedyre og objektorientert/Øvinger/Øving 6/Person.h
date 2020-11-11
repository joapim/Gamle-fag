#pragma once
#include <iostream>
#include <iostream>
#include "Car.h"
using namespace std;

class Person {
private:
	string name;
	string email;
	Car* car;
public:
	Person(string name, string email, Car* car);
	Person(string name, string email);

	bool hasAvailableSeats();
	

	string getName() const { 
		return name; 
	}
	string getEmail() const { 
		return email;
	}
	void SetEmail(string email) {
		this->email = email;
	}
};

std::ostream& operator <<(std::ostream& streamP, const Person& per);
bool operator ==(const Person& a, const Person& b);
bool operator <(const Person& a, const Person& b);