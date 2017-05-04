#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {

    Matrix<int> A = {1, 2, 3, 4};
    Matrix<int> B(2, 2);
    B = {5, 7, 1, 8};

    cout << A << endl;
    B += A;
    cout << "Result of adding 2 matrices with +=:" << endl;
    cout << B << endl;

    Matrix<int> C(2, 2);
    Matrix<int> D(2, 2);

    C = B + A;
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

    return 0;
}