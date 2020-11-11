#pragma once
#include <ostream>
#include <iostream>
using namespace std;

//OPPGAVE 1

void fillInFibonacciNumbers(int result[], int lenght);
void printArray(int arr[], int lenght);
void createFibonacci();

//OPPGAVE 2



class Matrix {
private:
	int nRows;
	int nColumns;
	typedef double* doublePtr;
	doublePtr* matrix;
	doublePtr* allokmatrix() {
		matrix = new doublePtr[nRows];
		for (int i = 0; i < nRows; i++) {
			matrix[i] = new double[nColumns];
		}
		return matrix;
	}

public:
	Matrix();
	Matrix(int nRows, int nColumns);
	explicit Matrix(int nRows) : Matrix(nRows, nRows) {
		for (int i = 0; i < nRows; i++) {
			matrix[i][i] = 1;
		}
	};
	~Matrix();

	void set(int row, int col, double value);
	double get(int row, int col) const;
	int getHeight()const;
	int getWidth()const;
	bool isValid() const;

	Matrix(const Matrix &other);

	Matrix& operator=(Matrix rhs) { // copy-and-swap
		swap(nRows, rhs.nRows);
		swap(nColumns, rhs.nColumns);
		swap(matrix, rhs.matrix);
		return *this;
	}

	Matrix &operator+=(const Matrix &other) {

		if (nRows != other.getWidth() || nColumns != other.getHeight())
		{
			for (int i = 0; i<nRows; i++)
				for (int j = 0; j<nColumns; j++)
					matrix[i][j] = matrix[i][j];

		}
		else
		{
			for (int i = 0; i < nRows; i++)
				for (int j = 0; j < nColumns; j++)
					matrix[i][j] += other.matrix[i][j];
		}
		return *this;
	}

	Matrix operator+(const Matrix &other) {

		if (nRows != other.getWidth() || nColumns != other.getHeight())
		{
			for (int i = 0; i<nRows; i++)
				for (int j = 0; j<nColumns; j++)
					matrix[i][j] = matrix[i][j];
		}
		else
		{
			for (int i = 0; i<nRows; i++)
				for (int j = 0; j<nColumns; j++)
					matrix[i][j] = (other.matrix[i][j] + matrix[i][j]);
		}
		return *this;
	}


};

std::ostream& operator<<(std::ostream& os, Matrix& matrix);
