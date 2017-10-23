//
// Created by Mamdouh El Nakeeb on 10/22/17.
//

#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

int main(){

    Matrix matrix(5, 10);

    cout << "Rows: " << matrix.getRows() << endl;
    cout << "Columns: " << matrix.getCols() << endl;

    return 0;
}