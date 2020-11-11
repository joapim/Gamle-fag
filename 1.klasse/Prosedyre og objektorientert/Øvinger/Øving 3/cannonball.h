#pragma once
#include <iostream>
using namespace std;


double acclY(); // Akselerasjonen i Y-retning

double velY(double initVelocityY, double time); // Farten i  Y-retning

double posX(double initPosition, double initVelocity, double time); //Posisjon x-retning

double posY(double initPosition, double initVelocity, double time); //Posisjon y-retning

void printTime(double time); //Tar inn tid i sekunder

double flightTime(double initVelocityY);//Tar inn startfart i Y-retning og retunerer flytiden

void getUserInput(double& theta, double& absVelocity); //Vinkel og fart fra bruker

double degToRad(double deg); //Fra grader til radianer

double getVelocityX(double theta, double absVelocity);// Farten i x-retning 

double getVelocityY(double theta, double absVelocity);// Farten i y-retning 

void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY); //Dekomponerer farten 

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double velocityX, double velocityY);

void playTargetPractice();