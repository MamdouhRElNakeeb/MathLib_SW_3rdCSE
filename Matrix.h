//
// Created by Mamdouh El Nakeeb on 10/20/17.
//

#ifndef MATH_LIBRARY_MATRIX_H
#define MATH_LIBRARY_MATRIX_H

class Matrix {
private:
    // matrix with rows and columns
    int rows, cols;
    // values, organized as an outer vector of rows
    // and an inner vector of columns
    std::vector<std::vector<int>> values;

public:
    // initialize matrix by its size
    matrix(int rows, int cols) : rows(rows), cols(cols) {

        // initialize the matrix size
        values.resize(rows);
        for (int i = 0; i < rows; ++i)
        {
            values[i].resize(cols);
        }
    }

    // Empty Constructor
    Matrix();

    // Copy a matrix
    Matrix(Matrix const& copy);

    // set matrix values
    void setValues(std::vector<std::vector<int>> values){
        this->values = values;
    }

    // get matrix
    std::vector getValues() const {

        return values;
    };

    // get value at specific index
    int getValue(int row, int col)const {
        return values[row][col];
    };

    // get rows count
    int getRows()const {
        return (values.size());
    };

    // get columns count
    int getCols()const {
        return (values[0].size());
    };

    // Matrix Operations
    Matrix addition(const Matrix&);
    Matrix subtraction(const Matrix&);
    Matrix multiplication(const Matrix&);
    Matrix transpose();
    Matrix division(const Matrix&);
};

#endif //MATH_LIBRARY_MATRIX_H
