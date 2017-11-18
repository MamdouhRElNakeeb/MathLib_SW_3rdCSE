
#ifndef MATH_LIBRARY_MATRIX_H
#define MATH_LIBRARY_MATRIX_H

#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <stdio.h>

class Matrix {
private:
	// matrix with rows and columns
	int rows, cols;
    char name;
	// values, organized as an outer vector of rows
	// and an inner vector of columns
	std::vector<std::vector<double> > values;

public:
  // Empty Constructor
    Matrix();

    // initialize matrix by its size
    Matrix(const unsigned int rows, const unsigned int cols);

    // initialize matrix by vector
    Matrix(const std::vector<std::vector<double> > values);


    // Copy a matrix
    Matrix(const Matrix& matrix);


    Matrix(std::string matStr);

    void setValues(std::string matStr);

    void setName(char name);
    char getName();

    // Matrix Destructor
    ~Matrix();

    // get matrix values
    std::vector<std::vector<double> > getValues();

    // get value at specific index
    float getValue(int row, int col);

    // set matrix values
    void setValues(std::vector<std::vector<double> > values);

    // get rows count
    int getRows();

    // get columns count
    int getCols();

    // Matrix Operations
    Matrix operator+(Matrix& matrix);

    Matrix operator-(Matrix& matrix);

    Matrix operator*(Matrix& matrix);

    Matrix operator~();

	// Used to get determinant
	double getDeterminant(Matrix& matrix, int n);
  
    Matrix inverse();

	//Used for testing
	/*Matrix Multiplication(Matrix& MatrixA, Matrix& MatrixB)
	{
	//Used for Testing

	float x = 0;
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
	*/

	Matrix operator/(Matrix& matrix);

    Matrix divElement(double x);
    Matrix multElement(double x);

    void display();
};
#endif
