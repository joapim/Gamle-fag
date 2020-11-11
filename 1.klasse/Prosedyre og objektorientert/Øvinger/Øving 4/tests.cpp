#include <iostream>
#include "utilities.h"
#include "tests.h"
using namespace std;


void testCallbyValue() { //resultat er 25, v0 er 5?
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0:" << v0
		<< ", increment:" << increment
		<< ", iterations:" << iterations
		<< ", result:" << result << endl;
}

void testCallByPointer() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimes2(&v0, increment, iterations);
	cout << "v0:" << v0
		<< ", increment:" << increment
		<< ", iterations:" << iterations << endl;
}

void testTableSorting() {
	int percentages[20] = {};
	cout << "Tabell 1:" << endl;
	randomizeArray(percentages, 20);
	cout << endl;
	cout << "Tabell 2:" << endl;
	swapNumbers(&percentages[0], &percentages[19]);
	printArray(percentages,20);
	cout << endl;
	cout << "Sortert: " << endl;
	sortArray(percentages, 20);  
	printArray(percentages, 20);
	cout << endl;
	cout << "Medianen:" << endl;
	cout << medianOfArray(percentages, 20)<< endl;
	
}

int testCStrings() {
	char grades[41] = {};
	randomizeCString(grades, *"F", *"A", 40);
	cout << grades << endl;
	readInputToStirng(grades, 40, *"A", *"F");
	cout << grades << endl;

	int gradecount[5];
	gradecount[0] = countOccurencesOfCharacter(grades, 40, *"A");
	gradecount[1] = countOccurencesOfCharacter(grades, 40, *"B");
	gradecount[2] = countOccurencesOfCharacter(grades, 40, *"C");
	gradecount[3] = countOccurencesOfCharacter(grades, 40, *"D");
	gradecount[4] = countOccurencesOfCharacter(grades, 40, *"E");


	printArray(gradecount, 5);
	double sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += (gradecount[i] * i + 1);
	}
	double snitt = sum / 5;
	cout << snitt << endl;
	return 0;

}