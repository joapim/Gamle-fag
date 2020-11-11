#include "tests.h"
#include "utilities.h"
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <algorithm> 
#include <iterator>
using namespace std;


int checkCharactersAndPosition(char kode[], char gjett[], int lenght) {
	int ant = 0;
	for (int d = 0; d < lenght; d++) {
		if (gjett[d] == kode[d]) {
			ant += 1;
		}
	}
	return ant;
}

int checkCharacters(char kode[], char gjett[], int lenght) {
	int x = 0;
	for (int i = 0; i < lenght; i++) {
		for (int j = 0; j < lenght; j++) {
			if (kode[i] == gjett[j]) {
				x += 1;
				break;
			}
		}
	}
	return x;
}



void playMastermind() {
	const int SIZE = 4;
	const int LETTERS = 6;

	char code[SIZE + 1] = {};
	char guess[SIZE + 1] = {};

	randomizeCString(code, *"F", *"A", SIZE);
	cout << code << endl;

	int tipp = 0;
	cout << "Hvor mange ganger vil du tippe? ";
	cin >> tipp;

	for (int i = 0; i < tipp; i++) {
		readInputToStirng2(guess, SIZE, *"A", *"F");
		cout << endl;
		int rettpos = checkCharactersAndPosition(code, guess, SIZE);
		cout << rettpos << " av posisjonene er rett" << endl;
		int rettboks = checkCharacters(code, guess, SIZE);
		cout << "Du har tippet " << rettboks << " av bokstavene rett" << endl;
		cout << endl;
		if (rettpos == SIZE) {
			cout << "Gratulerer du vant! Koden var: " << code << endl;
			break;
		}

	}
	int rettpos = checkCharactersAndPosition(code, guess, SIZE);
	if (rettpos != SIZE) {
		cout << "Du tapte... Koden var: " << code << endl;
	}

}