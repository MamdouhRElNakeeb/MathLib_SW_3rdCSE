//
// Created by Mamdouh El Nakeeb on 10/20/17.
//

#include "Matrix.h"

#ifndef MATH_LIBRARY_OPERATIONS_H
#define MATH_LIBRARY_OPERATIONS_H

class Operations{

public:
    Matrix addition(const Matrix&, const Matrix&);
    Matrix subtraction(const Matrix&, const Matrix&);
    Matrix multiplication(const Matrix&, const Matrix&);
    Matrix transpose(const Matrix&);
    Matrix division(const Matrix&, const Matrix&);
};

#endif //MATH_LIBRARY_OPERATIONS_H
