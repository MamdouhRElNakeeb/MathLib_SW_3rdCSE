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

void Matrix::setName(char name)
{
    this->name=name;
}

char Matrix::getName(){
    return name;
}

Matrix::~Matrix() {
    //vector<vector<float> >().swap(values);
    //values.shrink_to_fit();
}

std::vector<std::vector<double> > Matrix::getValues() {

    return values;
}

float Matrix::getValue(int row, int col) {
    return values[row][col];
}

void Matrix::setValues(std::vector<std::vector<double> > values){
    this->values = values;
    this->rows = int(values.size());
    this->cols = int(values[0].size());
}

int Matrix::getRows(){
    return int(values.size());
}

int Matrix::getCols(){
    return int(values[0].size());
}

Matrix Matrix::operator+(Matrix& matrix){

    if (rows != matrix.rows && cols != matrix.cols){
        throw "Invalid Matrices Dimensions. \n";
    }

    Matrix temp(matrix.rows,matrix.cols);
    for(int i=0 ; i<matrix.values.size() ; i++)
    {
        for (int t=0 ; t<matrix.values[0].size() ; t++)
        {
            temp.values[i][t]=values[i][t]+matrix.values[i][t];
        }
    }
    return temp;

}
Matrix Matrix::operator-(Matrix& matrix){

    if (rows != matrix.rows && cols != matrix.cols){
        throw "Invalid Matrices Dimensions \n";
    }

    Matrix temp(matrix.rows,matrix.cols);
    for(int i=0 ; i<matrix.values.size() ; i++)
    {
        for (int t=0 ; t<matrix.values[0].size() ; t++)
        {
            temp.values[i][t]=values[i][t]-matrix.values[i][t];
        }
    }
    return temp;

}

Matrix Matrix::operator*(Matrix& matrix){


    /*if (values[0].size() != matrix.values.size() )
    {

    cout<<"error";

    }

    else */

    double sum =0  ;
    Matrix temp( rows ,matrix.cols);
    for(int i=0 ; i<values.size() ; i++)
    {
        for (int j=0 ; j <matrix.values[0].size() ; j++)
        {

            for (int m=0 ; m<values[0].size() ; m++)
            {
                double  z;
                z= values[i][m]*matrix.values[m][j ];
                sum= sum + z;

            }

            temp.values[i][j]=sum;
            sum=0;
        }

    }
    return temp;
}

Matrix Matrix::operator~(){

    Matrix temp(cols,rows);
    for(int i=0 ; i<values.size() ; i++)
    {
        for (int j=0 ; j<values[0].size() ; j++)
        {
            temp.values[j][i]=values[i][j];
            temp.values[i][j] = values[j][i];
        }
    }
    return temp;
}

double Matrix::getDeterminant(Matrix& matrix, int n) {

    double Determinant = 0, indexcols, minorrows, minorcols, i, j;
    Matrix minorMatrix(n - 1, n - 1);

    if (n == 2)
    {
        Determinant = ((matrix.values[0][0] * matrix.values[1][1]) - (matrix.values[1][0] * matrix.values[0][1]));
        return Determinant;
    }

    else
    {
        // index for the larger matrix
        for (indexcols = 0; indexcols < n; indexcols++)
        {
            // indexs for the minor matrix
            minorrows = 0;
            minorcols = 0;

            for (i = 1; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (j == indexcols)
                    {
                        continue;
                    }
                    minorMatrix.values[minorrows][minorcols] = matrix.values[i][j];
                    minorcols++;
                    if (minorcols == n - 1)
                    {
                        minorrows++;
                        minorcols = 0;
                    }
                }
            }
            Determinant += matrix.values[0][indexcols] * pow(-1, indexcols)*getDeterminant(minorMatrix, n - 1);
            if (Determinant == 0)
            {
                return 0;
            }
        }
        return Determinant;
    }
}

Matrix Matrix::inverse() {

    Matrix MatrixBInverse(values);

    double Determinant = getDeterminant(MatrixBInverse, rows);
    if (Determinant == 0.0)
    {
        throw "Invalid Matrices Division. \n";
    }
    double Reciprocal = 1.0 / Determinant;

    // Used to get the n - 1 x n -1 matrices for to get inverse
    Matrix Cofactors(rows - 1, cols - 1);

    int indexcols, indexrows, minorrows, minorcols, i, j, n = cols;
    // z is indexrows for inverse matrix , y for indexcols for inverse matrix , powerindexes to adjust signs
    int z = 0, y = 0, powerindex1 = 0, powerindex2 = 0;

    if (rows == 2)
    {
        double temp = this->values[0][0];
        MatrixBInverse.values[0][0] = MatrixBInverse.values[1][1];
        MatrixBInverse.values[1][1] = temp;

        MatrixBInverse.values[1][0] = -MatrixBInverse.values[1][0];
        MatrixBInverse.values[0][1] = -MatrixBInverse.values[0][1];

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                MatrixBInverse.values[i][j] = Reciprocal * MatrixBInverse.values[i][j];
            }
        }

    }
    else
    {
        for (indexcols = 0, indexrows = 0; indexrows < n; indexcols++)
        {
            minorrows = 0;
            minorcols = 0;
            if (indexrows == 0)
            {
                i = 1;
            }
            else
            {
                i = 0;
            }
            for (i; i < n; i++)
            {
                if (i == indexrows)
                {
                    continue;
                }
                for (j = 0; j < n; j++)
                {
                    if (j == indexcols)
                    {
                        continue;
                    }
                    Cofactors.values[minorrows][minorcols] = this->values[i][j];
                    minorcols++;
                    if (minorcols == n - 1)
                    {
                        minorrows++;
                        minorcols = 0;
                    }
                }
            }
            MatrixBInverse.values[z][y] = getDeterminant(Cofactors, n - 1) * pow(-1, powerindex1);
            powerindex2++;
            if (powerindex2 == n)
            {
                powerindex2 = 0;
                powerindex1++;
            }
            powerindex1++;
            y++;
            if (y == n)
            {
                z++;
                if (z == n)
                {
                    z = n - 1;
                }
                y = 0;
            }

            if (indexcols == n - 1)
            {
                indexcols = -1;
                indexrows++;
            }
        }

    }
    MatrixBInverse = ~MatrixBInverse;
    for (int x = 0; x < MatrixBInverse.rows; x++)
    {
        for (int y = 0; y < MatrixBInverse.cols; y++)
        {
            MatrixBInverse.values[x][y] = Reciprocal * MatrixBInverse.values[x][y];
        }
    }

    //
    return MatrixBInverse;
}


Matrix Matrix::operator/(Matrix& matrix) {

    //Used for Testing
    /*
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
    */

    // If the matrix is not a square (rows = columns) , you can't get a inverse, so you can't divide.
    if (rows != matrix.cols)
    {
        throw "Invalid Matrices Division. \n";
    }

    Matrix MatrixBInverse = matrix.inverse();

    Matrix matA(values);

    Matrix Result = matA * MatrixBInverse;
    return Result;

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