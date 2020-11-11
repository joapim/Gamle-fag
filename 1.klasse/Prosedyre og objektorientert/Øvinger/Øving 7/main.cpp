#include <iostream>
#include <ostream>
#include "oppgaver.h"
#include "dummy.h"
using namespace std;



int main() {

	//OPPGAVE 1
	cout << "OPPGAVE 1" << endl;
	cout << endl;

	createFibonacci();

	cout << endl;

	//OPPGAVE 2 
	cout << "OPPGAVE 2" << endl;
	cout << endl;

	Matrix m1 = Matrix::Matrix();

	Matrix m2 = Matrix::Matrix(5);

	Matrix m3 = Matrix::Matrix(5, 7);

	Matrix m4 = Matrix::Matrix(5, 7);

	Matrix m5(m4);

	m3.set(3, 3, 45);

	m4 = m3;

	cout << m1 << endl;

	cout << m2 << endl;

	cout << m4 << endl;

	cout << endl;

	//OPPGAVE 3 
	cout << "OPPGAVE 3" << endl;
	cout << endl;
	//3a
	/*
	a,b,c = 4
	a = 5, b = 5, c = 5
	*/
	dummyTest();

	//Resultatene stemte, a,b og c blir 5 i siste test fordi at de ikke blir slettet etter første test, og alle har derfor samme adresse. 


	//Oppgave 5
	cout << endl;
	cout << "OPPGAVE 5" << endl;
	cout << endl;
	Matrix A = Matrix::Matrix(2, 2);
	Matrix B = Matrix::Matrix(2, 2);
	Matrix C = Matrix::Matrix(2, 2);

	A.set(0, 0, 1.0);
	A.set(0, 1, 2.0);
	A.set(1, 0, 3.0);
	A.set(1, 1, 4.0);

	B.set(0, 0, 4.0);
	B.set(0, 1, 3.0);
	B.set(1, 0, 2.0);
	B.set(1, 1, 1.0);

	C.set(0, 0, 1.0);
	C.set(0, 1, 3.0);
	C.set(1, 0, 1.5);
	C.set(1, 1, 2.0);

	A += B + C;

	cout << A << endl;


}
