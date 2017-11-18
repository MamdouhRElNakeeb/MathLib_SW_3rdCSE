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


int main(int argc, char *argv[]){

    string matArr[] = {"A = [1 2 3;4 5 6;7 8 9]",
                       "B = [3 4 9;4 8 6;8 5 3]",
                       "C = A + B"};


    vector<Matrix> temp_matrices(10);
    string matStr = "";
    char operation = 'a';
    int n = 0, matNo = 0;
    bool newMat = false;
    string matrixStr = "";
    string constNo = "";



//    ifstream fileData("/Users/mamdouhelnakeeb/Desktop/ASU/CSE/3rd/Software Engineering/Project/Repo/Math_Library/bigexample.m");
    ifstream fileData(argv[1]);

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

                newMat = true;
//                temp_matrices[matNo - 1].setValues(fileLine.substr(i + 1, fileLine.find(']') - i - 1));

                //temp_matrices[n].display();
                operation = 'a';

                i++;

                while (fileLine[i] != ']'){
                    matrixStr += fileLine[i];
                    i++;

                    if(i >= fileLine.length()){
                        getline(fileData, fileLine);
                        i = 0;
                    }
                }

                if (matrixStr[matrixStr.length() - 1] == ';'){
                    matrixStr = matrixStr.substr(0, matrixStr.length() - 1);
                }
                else if (matrixStr[matrixStr.length() - 2] == ';'){
                    matrixStr = matrixStr.substr(0, matrixStr.length() - 2);
                }

                temp_matrices[matNo - 1].setValues(matrixStr);
                matrixStr = "";
                break;

            }
            else if (fileLine[i] == '+' || fileLine[i] == '-' || fileLine[i] == '*' || fileLine[i] == '/' || fileLine[i] == '\''){

                operation = fileLine[i];

                if (fileLine[i] == '/' && fileLine[i - 1] == '.'){
                    operation = 'd';
                }
                else if (fileLine[i] == '*' && fileLine[i - 1] == '.'){
                    operation = 'm';
                }
            }

            else if (fileLine[i] == ' ' || fileLine[i] == '\r' || fileLine[i] == '\n' || fileLine[i] == '='){
                continue;
            }
            else if ((int) fileLine[i] > 47 && (int) fileLine[i] < 58){

                while (fileLine[i] != ' '){
                    constNo += fileLine[i];
                    i++;
                }

            }
//            else if (fileLine[i] == ']'){
//
//                if (matrixStr[matrixStr.length() - 1] == ';' || matrixStr[matrixStr.length() - 1] == ']'){
//                    matrixStr = matrixStr.substr(0, matrixStr.length() - 1);
//                }
//
//                temp_matrices[matNo - 1].setValues(matrixStr);
//                matrixStr = "";
//                newMat = false;
//            }
//            else {
//                if (newMat){
//
//                    matrixStr += fileLine[i];
////                    cout << fileLine.substr(i, fileLine.length() - i - 1) << endl;
//
////                    break;
//
//                }
////                temp_matrices[matNo - 1].setValues(fileLine.substr(i, fileLine.find(']') - i));
//            }

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


                    cout << mat3.getName() << " = " << endl;
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

                    cout << mat3.getName() << " = " << endl;
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

                    cout << mat3.getName() << " = " << endl;
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

                    try {

                        mat3 = mat1 / mat2;

                        mat3.setName(temp_matrices[matIndex].getName());

                        cout << mat3.getName() << " = " << endl;
                        mat3.display();
                        temp_matrices[matIndex] = mat3;
                    }
                    catch (const char* msg){
                        cout << msg << endl;
                    }

                    break;

                case '\'':
                    try{
                        mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                        matIndex = findMatrix(temp_matrices, matStr[0]);
                        mat2 = temp_matrices[matIndex];
//                mat2.display();

                        mat2 = ~mat1;

                        mat2.setName(temp_matrices[matIndex].getName());

                        cout << mat2.getName() << " = " << endl;
                        mat2.display();
                        temp_matrices[matIndex] = mat2;
                    }
                    catch (string e){
                        cout << e << endl;
                    }


                    break;
                case 'd':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat2 = temp_matrices[matIndex];
//                mat2.display();

                    // implement here

                    //mat2 ./ mat1
                    mat2 = mat1.divElement(atof(constNo.c_str()));

                    mat2.setName(temp_matrices[matIndex].getName());

                    cout << mat2.getName() << " = " << endl;
                    mat2.display();

                    temp_matrices[matIndex] = mat2;
                    break;

                case 'm':
                    mat1 = temp_matrices[findMatrix(temp_matrices, matStr[1])];
//                mat1.display();
                    matIndex = findMatrix(temp_matrices, matStr[0]);
                    mat2 = temp_matrices[matIndex];
//                mat2.display();

                    // implement here

                    //mat2 .* mat1
                    mat2 = mat1.multElement(atof(constNo.c_str()));

                    mat2.setName(temp_matrices[matIndex].getName());

                    cout << mat2.getName() << " = " << endl;
                    mat2.display();

                    temp_matrices[matIndex] = mat2;
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