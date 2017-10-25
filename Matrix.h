//
// Created by Mamdouh El Nakeeb on 10/20/17.
//

#ifndef MATH_LIBRARY_MATRIX_H
#define MATH_LIBRARY_MATRIX_H
#include <iostream>
#include <vector>
#include <math.h>


class Matrix {
private:
	// matrix with rows and columns
	int rows, cols;
	// values, organized as an outer vector of rows
	// and an inner vector of columns
	std::vector<std::vector<float> > values;

public:
	// Empty Constructor
	Matrix()
	{
		rows = 0;
		cols = 0;
		this->values.resize(0);
		this->values[0].resize(0);
	}

	// initialize matrix by its size
	Matrix(const unsigned int rows, const unsigned int cols) {

		// initialize the matrix size
		this->values.resize(rows);
		for (int i = 0; i < rows; ++i) {
			this->values[i].resize(cols);
		}

		this->rows = rows;
		this->cols = cols;
	}

	// initialize matrix by vector
	Matrix(const std::vector<std::vector<float> > values) {

		this->rows = int(values.size());
		this->cols = int(values[0].size());
		this->values.resize(values.size());
		for (int i = 0; i < values.size(); ++i)
		{
			this->values[i].resize(values[i].size());
		}
		for (int i = 0; i < values.size(); ++i)
		{
			for (int j = 0; j < values[i].size(); ++j)
			{
				this->values[i][j] = values[i][j];
			}
		}
	}


	// Copy a matrix
	Matrix(const Matrix& matrix) {
		rows = matrix.rows;
		cols = matrix.cols;
		values.resize(matrix.values.size());
		for (int i = 0; i < values.size(); ++i)
		{
			values[i].resize(matrix.values[i].size());
		}
		for (int i = 0; i < values.size(); ++i)
		{
			for (int j = 0; j < values[i].size(); ++j)
			{
				values[i][j] = matrix.values[i][j];
			}
		}
	}

	// Matrix Destructor
	~Matrix() {
		//vector<vector<float> >().swap(values);
		values.shrink_to_fit();
	}

	// get matrix values
	std::vector<std::vector<float> > getValues() {

		return values;
	}

	// get value at specific index
	float getValue(int row, int col) {
		return values[row][col];
	}

	// set matrix values
	void setValues(std::vector<std::vector<float> > values) {
		this->values = values;
		this->rows = int(values.size());
		this->cols = int(values[0].size());
	}

	// get rows count
	int getRows() {
		return int(values.size());
	}

	// get columns count
	int getCols() {
		return int(values[0].size());
	}

	// Matrix Operations
	Matrix operator+(Matrix& matrix) {

	}

	Matrix operator-(Matrix& matrix) {

	}

	Matrix Multiplication(Matrix& MatrixA, Matrix& MatrixB)
	{
		//Used for Testing
		/* 
		int x = 0;
		std::cout << "Please Enter the Matrix A Values row by row\n";
		for (int i = 0; i < MatrixA.rows; i++)
		{
			for (int j = 0; j < MatrixA.cols; j++)
			{
				std::cin >> x;
				MatrixA.values[i][j] = x;

			}
		}
		std::cout << "Please Enter the Matrix B Values row by row\n";
		for (int i = 0; i < MatrixB.rows; i++)
		{
			for (int j = 0; j < MatrixB.cols; j++)
			{
				std::cin >> x;
				MatrixB.values[i][j] = x;
			}
		}
		*/
		Matrix MatrixResult = Matrix(MatrixA.rows, MatrixB.cols);

		if (MatrixA.cols != MatrixB.rows)
		{
			std::cout << "These two matrices can not be multiplied\n";
			return Matrix();
		}
		else
		{
			float sum = 0;
			int indexrows = 0, indexcols = 0;
			for (int i = 0; i < MatrixResult.rows * MatrixResult.cols; i++)
			{
				for (int j = 0; j < MatrixB.rows; j++)
				{
					 sum += MatrixA.values[indexrows][j] * MatrixB.values[j][indexcols];
				}
				MatrixResult.values[indexrows][indexcols] = floor(sum);
				sum = 0;
				indexcols++;
				if (i > 0 && MatrixB.cols % i == 0 && indexrows < MatrixA.rows - 1)
				{
					indexcols = 0;
					indexrows++;
				}
			}
		}
		return MatrixResult;
	}

	Matrix operator~() {

	}

	Matrix Division(Matrix& MatrixA, Matrix& MatrixB)
	{

		//Used for Testing
		/*
		int x = 0;
		std::cout << "Please Enter the Matrix A Values row by row\n";
		for (int i = 0; i < MatrixA.rows; i++)
		{
		for (int j = 0; j < MatrixA.cols; j++)
		{
		std::cin >> x;
		MatrixA.values[i][j] = x;

		}
		}
		std::cout << "Please Enter the Matrix B Values row by row\n";
		for (int i = 0; i < MatrixB.rows; i++)
		{
		for (int j = 0; j < MatrixB.cols; j++)
		{
		std::cin >> x;
		MatrixB.values[i][j] = x;
		}
		}
		*/

		// If the matrix is not a square (rows = columns) , you can't get a inverse, so you can't divide.
		if (MatrixB.rows != MatrixB.cols)
		{
			std::cout << "There is no unique solution\n";
			return Matrix();
		}
		Matrix MatrixBInverse = Matrix(MatrixB);

		if (MatrixB.rows == 2)
		{
			int Determinant = ((MatrixB.values[0][0] * MatrixB.values[1][1]) - (MatrixB.values[1][0] * MatrixB.values[0][1]));
			float Reciprocal = 1.0 / Determinant;

			int temp = MatrixB.values[0][0];
			MatrixBInverse.values[0][0] = MatrixBInverse.values[1][1];
			MatrixBInverse.values[1][1] = temp;

			MatrixBInverse.values[1][0] = -MatrixBInverse.values[1][0];
			MatrixBInverse.values[0][1] = -MatrixBInverse.values[0][1];

			for (int i = 0; i < MatrixB.rows; i++)
			{
				for (int j = 0; j < MatrixB.cols; j++)
				{
					MatrixBInverse.values[i][j] = Reciprocal * MatrixBInverse.values[i][j];
				}
			}

		}
		else
		{

		}

		Matrix Result = Multiplication(MatrixA, MatrixBInverse);
		return Result;

	}
};

#endif //MATH_LIBRARY_MATRIX_H


