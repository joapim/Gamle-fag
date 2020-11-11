#include <iostream>
#include "utilities.h"
#include "tests.h"
#include "mastermind.h"
#include <ctime>
using namespace std;
// & - Er som en postkasse(addresse)
// * - Det som er inne i postkassen

int main() {
	setlocale(LC_ALL, "Norwegian");
	srand(time(nullptr));
	int func = 1;
	while (func != 0) {
		cout << "Velg funksjon:" << endl;
		cout << "0) Avslutt" << endl;
		cout << "1) testCallByValue " << endl;
		cout << "2) testCallByPointer" << endl;
		cout << "3) swapNumbers" << endl;
		cout << "4) testTableSorting" << endl;
		cout << "5) printArray" << endl;
		cout << "6) randomizeArray" << endl;
		cout << "7) sortArray" << endl;
		cout << "8) medianOfArray" << endl;
		cout << "9) testCStrings" << endl;
		cout << "10) Mastermind" << endl;
		cin >> func;
		cout << endl;
		int percentages[20] = {};
		int num1 = 10;
		int num2 = 20;
		
		
		switch (func) {
		case 1: testCallbyValue(); break;
		case 2: testCallByPointer(); break;
		case 3: swapNumbers(&num1,&num2); break;
		case 4: testTableSorting(); break;
		case 5: printArray(percentages, 20); break;
		case 6: randomizeArray(percentages, 10); break;
		case 7: sortArray(percentages, 20); break;
		case 8: medianOfArray(percentages, 20);
		case 9: testCStrings(); break;
		case 10: playMastermind(); break;
		}cout << endl;
		cout << endl;
		cout << endl;
		}
}