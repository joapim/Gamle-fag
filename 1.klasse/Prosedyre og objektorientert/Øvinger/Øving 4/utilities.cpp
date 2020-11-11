#include <iostream>
#include "utilities.h"
#include <cctype>
using namespace std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

void incrementByValueNumTimes2(int* startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
}

void swapNumbers(int* num1, int* num2) {
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	cout << "Etter bytting: " 
	<< "num1 = " << *num1
	<< ", num2 = " << *num2 << endl;
}

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		cout << array[i] << "\t";
	}
}

int randomWithLimits(int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;
}

void randomizeArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		array[i] = randomWithLimits(0, 100);
		cout << array[i] << "\t";
	}
}

void sortArray(int tabell[], int lenght) {
	int j,temp;
	for (int i = 0; i < lenght; i++) {
		j = i;
		while (j > 0 && tabell[j] < tabell[j - 1]) {
			temp = tabell[j];
			tabell[j] = tabell[j - 1];
			tabell[j - 1] = temp;
			j--;
		}
	}

}



int medianOfArray(int array[],int size) { 
	if (size % 2 == 0) {
		return  array[size / 2];
	}
	else {
		return (array[size / 2] + array[(size / 2) - 1]) / 2;
	}
}

void randomizeCString(char Carray[], int size, int min, int max) { //Med Cstring trenger man ikke pekere 
	for (int i = 0; i < size; i++) {
		Carray[i] = randomWithLimits(min, max);
	}
}

void readInputToStirng(char tabell[], int lenght, char lower, char upper) {
	char in;
	int ar = 0;
	for (int i = 0; i < lenght; i++) {
		cout << "Skriv inn en bokstav: ";
		cin >> in;
		int in_t = int(toupper(in));
		while ((in_t > int(upper)) | (in_t < int(lower))) {
			cout << "Skriv inn en bokstav innnenfor grensen " << lower << " og " << upper << endl;
			cin >> in;
			in_t = int(toupper(in));
		}
		ar += 1;

	}
}
	

int countOccurencesOfCharacter(char tabell[], int size, char letter) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (letter == tabell[i]) {
			counter += 1;
		}
	}
	return counter;
}

void readInputToStirng2(char tabell[], int lenght, char lower, char upper) {
	char in;
	for (int i = 0; i < lenght; i++) {
		cout << "Skriv inn en bokstav: ";
		cin >> in;
		int in_t = int(toupper(in));
		while ((in_t > int(upper)) | (in_t < int(lower))) {
			cout << "Skriv inn en bokstav innnenfor grensen " << lower << " og " << upper << endl;
			cin >> in;
			in_t = int(toupper(in));
		}
		tabell[i] = char(in_t);
	}

}