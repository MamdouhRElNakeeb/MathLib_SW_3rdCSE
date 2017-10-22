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
};

#endif //MATH_LIBRARY_MATRIX_H
