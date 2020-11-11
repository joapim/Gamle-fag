#include <iostream>
#include <math.h>
#include "cannonball.h"
#include "utilities.h"
using namespace std;
const double PI = 3.14159;

double acclY(){ //Returnerer akselrasjon i Y-retning
	return -9.81;
}

double velY(double initVelocityY, double time) { // Farten i  Y-retning
	return initVelocityY + (acclY() * time);
}

double posX(double initPosition, double initVelocity, double time) { //Posisjon x-retning
	return initPosition + (initVelocity * time);
}

double posY(double initPosition, double initVelocity, double time) { //Posisjon y-retning
	return initPosition + (initVelocity * time) + (acclY() *pow(time, 2.0)) / 2;
}
	
void printTime(int time) { //Tar inn tid i sekunder
	int hours = time / (60 * 60);
	int minutes = time / 60 % 60;
	int seconds = time - (60 * minutes + 60 * 60 * hours);
	cout << hours << ":" << minutes << ":" << seconds;
}

double flightTime(double initVelocityY) { 
	return (-2 * initVelocityY) / acclY();
}


void getUserInput(double *theta, double *absVelocity) { //Oppretter adressen i minnet
	cout << "Skriv inn vinkel(grader): " << endl;
	cin >> *theta; //Refererer til adressen
	cout << "Skriv inn farten(m/s): " << endl;
	cin >> *absVelocity;
}
	
double degToRad(double deg) { //Fra grader til radianer
	return deg * PI / 180;
}

double getVelocityX(double theta, double absVelocity) { // Farten i x-retning 
	return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity) { // Farten i y-retning 
	return absVelocity * sin(theta);
}


void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY) { //Dekomponerer farten 
	velocityX = getVelocityX(theta, absVelocity);
	velocityY = getVelocityY(theta, absVelocity);
}


double getDistanceTraveled(double velocityX, double velocityY) {
	return flightTime(velocityY) * velocityX;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}


void playTargetPractice() {
	double theta = 0.0;
	double absVelocity = 0.0;
	double velocityX = 0.0;
	double velocityY = 0.0;
	int distanceToTarget = randomWithLimits(100,1000);
	int counter = 1;
	cout << "Velkommen, du skal nå spille et skytespill" << endl;
	cout << "Du skal prøve å treffe blink med en kanonkule!" << endl;
	cout << "Det regnes som treff hvis du er innenfor en margin på fem meter" << endl;
	cout << "For å få dette til må du bergne vinkel og skuddhastighet for kulen" << endl;
	cout << "Du har 10 forsøk" << endl;
	cout << "Lykke til!" << endl;
	while (counter < 11) {
		cout << endl;
		cout << "Forsøk " << counter << ":" << endl;
		getUserInput(&theta, &absVelocity); //Endrer hva som står i minnet
		theta = degToRad(theta);
		getVelocityVector(theta, absVelocity, velocityX, velocityY);
		int deviation = targetPractice(distanceToTarget, velocityX, velocityY);
		if (deviation > 5) {
			cout << "Du skjøt " << deviation << " meter for kort" << endl;
		}else if (deviation < -5) {
			cout << "Du skjøt " << abs(deviation) << " meter for langt" << endl;
		}
		else {
			cout << "Gratulerer du traff blink!" << endl;
			break;
		}
		++counter;		
	}
	if (counter >= 11) {
		cout << "Du har brukt opp alle din forsøk desverre! Bedre lykke neste gang" << endl;
	}
	
}