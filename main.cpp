#include <iostream>
#include "Matrix.h"
//#include "Vector.h"

using namespace std;

int main() {

    Matrix<int> A(2,2);
    A = {1, 2, 3, 4};
//    //Vector<double> vA = {1,2,1,2}; what's wrong with this init?
//
//

    Matrix<int> B(2, 2);
     B = {5, 7, 1, 8};

    Matrix<int> C = B+A;
    cout << C;


    //Matrix<int> C = A.multiplication(B);
    //cout << C;
//    Matrix<int> De(2, 2);
//
//    //cout << A << endl;
//    //B += A;
//    //cout << "Result of adding 2 matrices with +=:" << endl;
//    //cout << B << endl;
//
//    Matrix<int> C(2, 2);
//    Matrix<int> D(2, 2);
//    Matrix<int> Mat(2, 2);
//
//    D = 2 * B;
//    cout << "Result of multiplying scalar and matrix with *"<< endl;
//    cout << D << endl;

 /**   C = B + A;
    cout << "Result of adding 2 matrices with +:" << endl;
    cout << C << endl;

    C = B + 2;
    cout << "Result of adding a scalar to matrix with +:" << endl;
    cout << C << endl;

    C = 2 + B;
    cout << "Result of adding a scalar to matrix with +:" << endl;
    cout << C << endl;


    D = B - A;
    cout << "Result of adding 2 matrices with -:"<< endl;
    cout << D << endl;

    
    B-= A;
    cout << "Result of -= for 2 matr.: "<< endl;
    cout << B << endl;

    D = B * A;
    cout << "Result of multiplying 2 matrices with *"<< endl;
    cout << D << endl;

    D = B * 2;
    cout << "Result of multiplying matrix and scalar with *"<< endl;
    cout << D << endl;

    D = 2 * B;
    cout << "Result of multiplying scalar and matrix with *"<< endl;
    cout << D << endl;


    De = - A;
    cout << "Result of unary minus: "<< endl;
    cout << De << endl;

    Mat = 1 - A;
    cout << "Result of substraction scalar(1) and matrix" << endl << A <<"result: "<< endl;
    cout << Mat << endl;
    */


    return 0;
}