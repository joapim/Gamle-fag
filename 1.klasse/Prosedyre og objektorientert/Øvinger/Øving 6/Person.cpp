#include<iostream>
#include<string>
#include "Person.h"
using namespace std;

Person::Person(string name, string email, Car* car):name(name), email(email), car(car) {
}

Person::Person(string name, string email):Person(name, email, nullptr) {

}

bool Person::hasAvailableSeats() {
	return (*car).hasFreeSeats;
}

/* Den bør ta const argument slik at den ikke endre på objektene
Man bør ikke bruke const når man har som hensikt å endre objektet, feks
ved bruk av ++ operator eller liknende*/
std::ostream& operator <<(std::ostream& streamP, const Person& per) {
	streamP << per.getName();
	return streamP;
}

bool operator ==(const Person& a, const Person& b) {
	return a.getName() == b.getName();
}

bool operator <(const Person& a, const Person& b) {
	char aLetter = '0';
	char bLetter = '0';
	int maxAmount = 0;

	if (a.getName().length() < b.getName().length()) //Finner ut hvilken streng som er lengst
		maxAmount = b.getName().length();
	else
		maxAmount = a.getName().length();

	for (int i = 0; i < maxAmount; i++) { 	//Sjekker alle bokstavane for å finne ut hvem som er først i alfabetet
		char aLetter = a.getName().at(i);
		char bLetter = b.getName().at(i);


		if (aLetter == bLetter)
			continue;
		else if (aLetter < bLetter)
			return true;
		else
			return false;
	}
	return false;
}