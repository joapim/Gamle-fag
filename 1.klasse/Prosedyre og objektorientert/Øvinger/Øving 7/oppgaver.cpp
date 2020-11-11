#include <iostream>
#include "oppgaver.h"
#include <string>
#include <ostream>
#include <cassert>
using namespace std;


//OPPGAVE 1


void fillInFibonacciNumbers(int result[], int lenght) {
	result[0] = 0;
	result[1] = 1;
	for (int i = 2; i < lenght; i++) {
		result[i] = result[i - 1] + result[i - 2];
	}

}

void printArray(int arr[], int lenght) {
	for (int i = 0; i < lenght; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void createFibonacci() {
	int size;
	cout << "Size of fibonacci list: ";
	cin >> size;
	int *fib = new int[size];
	fillInFibonacciNumbers(fib, size);
	printArray(fib, size);
	delete[] fib;
	fib = nullptr;

}

//OPPGAVE 2

Matrix::Matrix(int nRows, int nColumns) {
	this->nRows = nRows;
	this->nColumns = nColumns;
	allokmatrix();
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nColumns; j++) {
			matrix[i][j] = 0;
		}
	}
};

Matrix::Matrix() {
	matrix = nullptr;
}

Matrix::~Matrix() {
	for (int i = 0; i < nRows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::set(int row, int col, double value) {
	this->matrix[row][col] = value;
}

double Matrix::get(int row, int col) const {
	return matrix[row][col];
}

int Matrix::getHeight() const {
	return nColumns;
}

int Matrix::getWidth() const {
	return nRows;
}

bool Matrix::isValid() const {
	bool valid;
	if (matrix == nullptr) {
		valid = false;
	}
	else {
		valid = true;
	}
	return valid;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix) {

	if (matrix.isValid() == true) {
		for (int i = 0; i < matrix.getWidth(); i++) {
			for (int j = 0; j < matrix.getHeight(); j++) {
				os << " " << matrix.get(i, j);
			}
			os << endl;
		}
	}
	return os;
}

//Oppgave 4 

Matrix::Matrix(const Matrix &other) {
	nRows = other.nRows;
	nColumns = other.nColumns;
	matrix = allokmatrix();
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nColumns; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}

}

