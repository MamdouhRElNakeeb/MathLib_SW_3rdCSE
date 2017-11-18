//
// Created by Mamdouh El Nakeeb on 10/22/17.
//

#include "Matrix.h"


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