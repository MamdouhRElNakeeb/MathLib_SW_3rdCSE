//
// Created by Mamdouh El Nakeeb on 10/22/17.
//

#include "Matrix.h"

Matrix::Matrix() {
    rows = 0;
    cols = 0;
    name = ' ';
    this->values.resize(1);
    this->values[0].resize(0);
}

Matrix::Matrix(const unsigned int rows, const unsigned int cols) {

    // initialize the matrix size
    this->values.resize(rows);
    for (int i = 0; i < rows; ++i) {
        this->values[i].resize(cols);
    }

    this->rows = rows;
    this->cols = cols;
}

Matrix::Matrix(const std::vector<std::vector<double> > values) {

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

Matrix::Matrix(const Matrix& matrix) {
    rows = matrix.rows;
    cols = matrix.cols;
    name = matrix.name;
    values.resize(matrix.values.size());
    for (int i = 0; i < values.size(); i++)
    {
        values[i].resize(matrix.values[i].size());
    }
    for (int i = 0; i < values.size(); i++)
    {
        for (int j = 0; j < values[i].size(); j++)
        {
            values[i][j] = matrix.values[i][j];
        }
    }
}

Matrix::Matrix(std::string matStr){

    setValues(matStr);

}

void Matrix::setValues(std::string matStr) {

    rows = 0, cols = 0;

    values.resize(1);
    values[0].resize(1);

    std::string tempNo = "";
    int n = 0;
    bool newNo = false;

    for (int i = 0; i < matStr.length(); i++){

        switch(matStr[i]){

            case ' ':
                if (newNo) {
                    values[rows][cols] = atof(tempNo.c_str());
                    newNo = false;
                    tempNo = "";
                    cols++;
                    values[rows].resize(cols + 1);
                }
                break;

            case ';':
                values[rows][cols] = atof(tempNo.c_str());
                newNo = false;
                tempNo = "";
                rows++;
                values.resize(rows + 1);
                values[rows].resize(cols + 1);
                cols = 0;
                break;

            case '\r':
                break;

            case '\n':
                break;

            case ']':
                break;

            default:
                tempNo += matStr[i];
                newNo = true;
                break;
        }

    }

    values[rows][cols] = atof(tempNo.c_str());
    tempNo = "";

    cols = (int) values[0].size();
    rows = (int) values.size();
}

Matrix Matrix::divElement(double x){
    Matrix temp(rows, cols);
    for (int i = 0; i < values.size(); i++)
    {
        for (int t = 0; t < values[0].size(); t++)
        {
            temp.values[i][t] = x / values[i][t];
        }
    }
    return temp;
}

Matrix Matrix::multElement(double x) {

    Matrix temp(rows, cols);

    for (int i = 0; i < values.size(); i++)
    {
        for (int t = 0; t < values[0].size(); t++)
        {
            temp.values[i][t] = x * values[i][t];
        }
    }

    return temp;
}

void Matrix::display(){

    for (int iR=0; iR<this->rows; iR++){
        for (int iC=0; iC<this->cols; iC++){

            printf("%.4f  \t",values[iR][iC]);
        }
        printf("\n");
    }
    printf("\n");
}