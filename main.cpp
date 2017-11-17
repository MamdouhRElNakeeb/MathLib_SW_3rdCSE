//
// Created by Mamdouh El Nakeeb on 10/22/17.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Matrix.h"

using namespace std;

int findMatrix(vector<Matrix> temp_matrices, char name){

    for (int i = 0; i < temp_matrices.size(); i++) {

        if (temp_matrices[i].getName() == name)
            return i;
    }

}

bool isMatExist (vector<Matrix> &temp_matrices, char name){
    for (int i = 0; i < temp_matrices.size(); i++) {

        if (temp_matrices[i].getName() == name)
            return true;
    }
    return false;
}


int main(){

    string matArr[] = {"A = [1 2 3;4 5 6;7 8 9]",
                       "B = [3 4 9;4 8 6;8 5 3]",
                       "C = A + B"};


    vector<Matrix> temp_matrices(10);
    string matStr = "";
    char operation = 'a';
    int n = 0, matNo = 0;
    // A~Z a~z

//    cout << "hgfdghkjr";


    ifstream fileData("/Users/mamdouhelnakeeb/Desktop/ASU/CSE/3rd/Software Engineering/Project/Repo/Math_Library/example.m");


    string fileLine;

    while (getline(fileData, fileLine)){

//        cout << fileLine << endl;

        for (int i = 0; i < fileLine.length(); i++){

//            cout << i << " -- " << n;
            if (((int) fileLine[i] > 96 && (int) fileLine[i] < 123) || ((int) fileLine[i] > 64 && (int) fileLine[i] < 91)){

                if (!isMatExist(temp_matrices, fileLine[i])){

                    Matrix tempMat;
                    tempMat.setName(fileLine[i]);
                    temp_matrices[matNo] = tempMat;
//                    temp_matrices[n].setName(matArr[n][i]);

                    operation = 'a';

                    matNo++;

                }

                matStr += fileLine[i];

            }
            else if (fileLine[i] == '['){

                temp_matrices[matNo - 1].setValues(fileLine.substr(i + 1, fileLine.find(']') - i - 1));
//                temp_matrices[matNo - 1].setName(matStr[0]);
                //temp_matrices[n].display();
                operation = 'a';


                break;

            }
            else if (fileLine[i] == '+' || fileLine[i] == '-' || fileLine[i] == '*' || fileLine[i] == '/' || fileLine[i] == '\'' || fileLine[i] == '.'){

                operation = fileLine[i];

                if (fileLine[i] == '/' && fileLine[i - 1] == '.'){
                    operation = '.';
                }
            }

            else if (fileLine[i] == ' '){
                continue;
            }

        }

        if (operation != 'a'){

            Matrix mat1, mat2, mat3;
            int matIndex = 0;

            switch (operation){

                case '+':

                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    mat2 = temp_matrices[findMatrix(temp_matrices, matStr[2])];
//                mat2.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat3 = temp_matrices[matIndex];
                    mat3 = mat1 + mat2;


                    mat3.setName(temp_matrices[matIndex].getName());
                    mat3.display();

                    temp_matrices[matIndex] = mat3;

                    break;
                case '-':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    mat2 = temp_matrices[findMatrix(temp_matrices, matStr[2])];
//                mat2.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat3 = temp_matrices[matIndex];

                    mat3 = mat1 - mat2;

                    mat3.setName(temp_matrices[matIndex].getName());

                    mat3.display();
                    temp_matrices[matIndex] = mat3;

                    break;
                case '*':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    mat2 = temp_matrices[findMatrix(temp_matrices, matStr[2])];
//                mat2.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat3 = temp_matrices[matIndex];

                    mat3 = mat1 * mat2;

                    mat3.setName(temp_matrices[matIndex].getName());

                    mat3.display();
                    temp_matrices[matIndex] = mat3;

                    break;
                case '/':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    mat2 = temp_matrices[findMatrix(temp_matrices, matStr[2])];
//                mat2.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat3 = temp_matrices[matIndex];

                    mat3 = mat1 / mat2;

                    mat3.setName(temp_matrices[matIndex].getName());

                    mat3.display();
                    temp_matrices[matIndex] = mat3;

                    break;

                case '\'':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat2 = temp_matrices[matIndex];
//                mat2.display();

                    mat2 = ~mat1;

                    mat2.setName(temp_matrices[matIndex].getName());

                    mat2.display();
                    temp_matrices[matIndex] = mat2;

                    break;
                case '.':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat2 = temp_matrices[matIndex];
//                mat2.display();

                    // implement here

                    //mat2 ./ mat1


                    mat2.setName(temp_matrices[matIndex].getName());

                    break;
            }


        }

        matStr = "";
        n++;
    }

    if (fileData.is_open()){
        fileData.close();
    }


    return 0;
}