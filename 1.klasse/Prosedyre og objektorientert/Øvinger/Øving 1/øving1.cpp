#include <iostream>
#include <algorithm>
using namespace std;

//oppgave A
int max(int a, int b) {
	if (a > b) {
		cout << a <<" is greater than " << b << endl;
		return a; //returner ikke a?
	}
	else {
		cout<<b << " is greater than or equal "<< a << endl;
		return b;
	}		
}



//Oppgave B
/*int main() {
	std::cout << "Oppgave a)" << std::endl;
	std::cout << max(5, 6) << std::endl;
}
*/



//Oppgave C
int fibonacci(int n) {
	int a = 0;
	int b = 0;
	cout << "Fibonacci numbers" << endl;
	for (int x = 1; x < n + 1; x++) {
		cout << x << b << endl;
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----" << endl;
	return b;
}




//Oppgave D
int squareNumbers(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += i * i;
		cout << (i*i) << endl;
	}
	cout << "----" << endl;
	cout << "Summen er: "<< totalSum << endl;
	return totalSum;
}


//Oppgave E
 void triagleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	cout << "Trangle numbers below " << n << ":" << " " << endl;
	while (acc < n) {
		cout << acc << endl;
		acc += num;
		num += 1;
	}
	cout << endl;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	while (number > 0) {
		number -= acc;
		acc += 1;
	}
	return number == 0; //Problem med å returnere 
}


//Oppgave F
bool isPrime(int n) {
	bool primeness = true;
	for (int i = 2; i < n; i++) {
		if ((n % i) == 0) {
			primeness = false;
			break;
		}
	}
	return primeness; //Problem med å returnere 
}


// Oppgave G
void naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n + 1; number++) {
		if (isPrime(number)) {
			cout << number << "is a prime" << endl;
		}
	}
}


// Oppgave H
int findGreatestDivisior(int n){
	for (int divisior = n-1; divisior > 0; divisior--) {
		if ((n % divisior) == 0) {
			return divisior;
		}
	}
}





int main() {
	cout << max(5, 6) << endl;
	cout << "Oppgave a)" << endl;
	cout << fibonacci(9) << endl;
	cout << squareNumbers(5) << endl;
	triagleNumbersBelow(10);
	cout << isTriangleNumber(5) << endl;
	cout << isPrime(7) << endl;
	cout << findGreatestDivisior(9) << endl;
	return 0;
}