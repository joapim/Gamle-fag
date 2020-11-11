#include <iostream>
#include <iomanip>
using namespace std;

//Oppgave A
void inputAndPrintInteger(){
	int x = 0;
	cout << "Skriv inn et tall: " << endl;
	cin >> x;
	cout << "Du skrev" << x << endl;
}

//Oppgave B
int inputInteger() {
	int x = 1;
	cout << "Skriv inn et tall" << endl;
	cin >> x;
	return x;
}

//Oppgave C
void inputIntegersAndPrintSum() {
	int x = inputInteger(); // Brukte inputInteger fordi jeg skal bruke verdien og da må den returneres
	int y = inputInteger();
	int sum = x + y;
	cout << "Du skrev" << x << endl;
	cout << "Du skrev" << y << endl;
	cout << "Summen av tallene er: " << sum << endl;
}

//Oppgave E
bool isOdd(int x) {
	return x % 2;
}

//Oppgave F
void printHumanReableTime(int seconds) {
	int hours = seconds / (60 * 60);
	int minutes = seconds / 60 % 60;
	seconds = seconds - (60 * minutes + 60 * 60 * hours);

	std::cout << hours << " time";
	if (hours != 1) std::cout << "r";
	std::cout << ", " << minutes << " minutt";
	if (minutes != 1) std::cout << "er";
	std::cout << ", " << seconds << " sekund";
	if (seconds != 1) std::cout << "er";
	std::cout << std::endl;
}

//Oppgave 2
//Oppgave AB
//While-løkker er best egnet for et ukjent antall iterasjoner (summer inntil brukeren skriver 0).
//For-løkker er best egnet for et kjent antall iterasjoner (summer x antall ganger).
void inputIntegersUsingLoopAndPrintSum() {
	int input = 1;
	int sum = 0;
	std::cout << "Summerer følgende tall. Avslutt med 0." << std::endl;
	while (input != 0) {
		input = inputInteger();
		sum += input;
	}
	std::cout << "Sum: " << sum << std::endl;
}

//Oppgave C
	double inputDouble() {
		double a;
		std::cout << "Et tall, takk: ";
		std::cin >> a;
		return a;
	}

//Oppgave D
	void NOKtoEuro() {
		double NOK = -1;
		double rate = 9.64;
		bool negative = false;
		while (NOK < 0) {
			if (negative) std::cout << "Du må oppgi et positivt antall norske kroner." << std::endl;
			std::cout << "Antall norske kroner som skal veksles til Euro: ";
			std::cin >> NOK;
			negative = true;
		}
		double euro = NOK / rate;
		std::cout << NOK << " norske kroner konverteres til " << std::fixed << std::setprecision(2) << euro << " euro." << std::endl;
	}//inputDouble() bør brukes istedenfor inputInteger fordi vi skal ta inn et desimaltall og ikke et heltall.




//Oppgave 3B
	void gangetabell() {
		int width;
		int height;
		std::cout << "Hvor bred vil du at gangetabellen skal være? ";
		std::cin >> width;
		std::cout << "Høyde på gangetabellen? ";
		std::cin >> height;
		std::cout << "Din gangetabell er: " << width << "x" << height << "-gangetabell!" << std::endl;
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				std::cout << std::setw(6) << i * j << " ";
			}
			std::cout << std::endl;
		}
	}

//Oppgave 4
//Oppgave A
double discriminant(double a, double b, double c) {
		return pow(b, 2) - 4 * a * c;
}

//Oppgave B
void printRealRoots(double a, double b, double c) {
	double disc = discriminant(a, b, c);
	if (disc < 0) {
		std::cout << "Ligningen har ingen reelle røtter." << std::endl;
	}
	else if (disc == 0) {
		double x = (-b + sqrt(disc)) / (2 * a);
		std::cout << "Ligningen har roten " << x << std::endl;
	}
	else {
		double x_1 = (-b + sqrt(disc)) / (2 * a);
		double x_2 = (-b - sqrt(disc)) / (2 * a);
		std::cout << "Ligningen har røttene " << x_1 << " og " << x_2 << std::endl;
	}
}

//Oppgave C
void solveQuadraticEquation() {
	int a, b, c;
	std::cout << "Uttrykk på formen ax^2 + bx + c = 0, så kan jeg finne en løsning." << std::endl;
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	std::cout << "c: ";
	std::cin >> c;
	std::cout << "Ligningen er da: " << a << "x^2 + " << b << "x + " << c << " = 0." << std::endl;
	printRealRoots(a, b, c);
}


//Oppgave 5
void calculateLoanPayments() {
	double totalLoan;	//Samlet lån for hele låneperioden
	double loan;		//Gjenstående lånebeløp
	double rate;		//Rentesats
	double installments = 10;	//Antall avdrag
	double payment;		//Terminbeløp

	std::cout << "Lånebeløp: ";
	std::cin >> totalLoan;
	std::cout << "Rente: ";
	std::cin >> rate;
	loan = totalLoan;

	std::cout << "Termin\tTerminbeløp\tGjenstående Lån" << std::endl;
	for (int i = 1; i <= 10; i++) {
		payment = totalLoan / installments + (rate / 100)*loan;
		loan = loan - totalLoan / installments;
		std::cout << i << "\t" << payment << "\t\t" << loan << std::endl;
	}
}











int main() {
	setlocale(LC_ALL, "Norwegian");
	int func = 1;
	while (func != 0) {
		std::cout << "Velg funksjon:" << std::endl
			<< "0) Avslutt" << std::endl
			<< "1) Summer to tall" << std::endl
			<< "2) Summer flere tall" << std::endl
			<< "3) Konverter NOK til Euro" << std::endl
			<< "4) Gangetabell" << std::endl
			<< "5) 2.gradsligninger" << std::endl
			<< "6) Lånekalkulator" << std::endl;
		std::cout << "Velg funksjon 0-6: ";
		std::cin >> func;
		switch (func) {
		case 1: inputIntegersAndPrintSum(); break;
		case 2: inputIntegersUsingLoopAndPrintSum(); break;
		case 3: NOKtoEuro(); break;
		case 4: gangetabell(); break;
		case 5: solveQuadraticEquation(); break;
		case 6: calculateLoanPayments(); break;
		}

		//inputAndPrintInteger();
		//inputInteger();
		//inputIntegersAndPrintSum();
		//cout << isOdd(10) << endl;
		//printHumanReableTime(60);
		//inputIntegersUsingLoopAndPrintSum();
	}

}
	
