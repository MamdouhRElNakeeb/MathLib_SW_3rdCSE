//
// Created by Mamdouh El Nakeeb on 10/20/17.
//

#ifndef MATH_LIBRARY_MATRIX_H
#define MATH_LIBRARY_MATRIX_H


#include <vector>


#include <vector>


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
    void setValues(std::vector<std::vector<float> > values){
        this->values = values;
        this->rows = int(values.size());
        this->cols = int(values[0].size());
    }

    // get rows count
    int getRows(){
        return int(values.size());
    }

    // get columns count
    int getCols(){
        return int(values[0].size());
    }

    // Matrix Operations
    Matrix operator+(Matrix& matrix){

    }

    Matrix operator-(Matrix& matrix){

    }

    Matrix operator*(Matrix& matrix){


		/*if (values[0].size() != matrix.values.size() )
		{
			
		cout<<"error";
		
		}

		else */

		int sum =0  ;
		Matrix temp( rows ,matrix.cols);
		for(int i=0 ; i<values.size() ; i++)
		{
			for (int j=0 ; j <matrix.values[0].size() ; j++)
			{

			for (int m=0 ; m<values[0].size() ; m++)
			{
				int  z;
				z= values[i][m]*matrix.values[m][j ];
				sum= sum + z;
				
			}

			temp.values[i][j]=sum;
			sum=0;
			}

		}
		return temp;
		
	
	
    }

    Matrix operator~(){
	
			Matrix temp(cols,rows);
		for(int i=0 ; i<values.size() ; i++)
		{
			for (int j=0 ; j<values[0].size() ; j++)
			{
				temp.values[j][i]=values[i][j];
			}
		}
		return temp;
    
    }

    Matrix operator/(Matrix& matrix){

    }
};

#endif //MATH_LIBRARY_MATRIX_H




