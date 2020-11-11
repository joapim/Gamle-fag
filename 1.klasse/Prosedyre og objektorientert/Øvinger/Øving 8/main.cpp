#include <iostream>
#include <fstream>
#include <string>
#include "to_from_file.h"
#include "tegnstatistikk.h"
#include "Emnekatalog.h"
using namespace std;

void main() {
	setlocale(LC_ALL, "norwegian");
	/*OPPGAVE 1 */
	cout << "OPPGAVE 1" << endl; 
	writeToFile();
	cout << endl;
	readFromFile();
	cout << endl;

	//OPPGAVE 2
	stats_letter();
	cout << endl;

	//OPPGAVE 3
	CourseCatalog semester_to = CourseCatalog();
	semester_to.addCourse("Informasjonsteknologi grunnkurs,", "TDT4110");
	semester_to.addCourse("Prosedyre- og objektorientert programmering", "TDT4102");
	semester_to.addCourse("Matematikk 1", "TMA4100");
	semester_to.addCourse("C++", "TDT4102");
	cout << semester_to << endl;
	cout << endl;
	
	//OPPGAVE 4
	statsToFile();

}