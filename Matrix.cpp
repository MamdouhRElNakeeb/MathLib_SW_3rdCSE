//
// Created by Mamdouh El Nakeeb on 10/22/17.
//

#include "Matrix.h"

// Empty Constructor
/*
Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}

// Initialize Matrix by its size
Matrix::Matrix(const unsigned int rows, const unsigned int cols) {

    // initialize the matrix size
    this->values.resize(rows);
    for (int i = 0; i < rows; ++i) {
        this->values[i].resize(cols);
    }

    this->rows = rows;
    this->cols = cols;
}

// Initialize Matrix by its values using vector of vectors
Matrix::Matrix(const std::vector<std::vector<float> > values) {

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
Matrix::Matrix(const Matrix& matrix) {
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
Matrix::~Matrix() {
    //vector<vector<float> >().swap(values);
    values.shrink_to_fit();
}

// get matrix values
std::vector<std::vector<float> > Matrix::getValues() {

    return values;
};

// get value at specific index
float Matrix::getValue(int row, int col) {
    return values[row][col];
};

// set matrix values
void Matrix::setValues(std::vector<std::vector<float> > values){
    this->values = values;
    this->rows = int(values.size());
    this->cols = int(values[0].size());
}

// get columns count
int Matrix::getCols(){
    return int(values[0].size());
};

// get rows count
int Matrix::getRows(){
    return int(values.size());
};


Matrix Matrix::operator+(Matrix &m) {

}

Matrix Matrix::operator-(Matrix &m) {

}

Matrix Matrix::operator*(Matrix &m) {

}

Matrix Matrix::operator~() {

}

Matrix Matrix::operator/(Matrix &m) {

}
*/