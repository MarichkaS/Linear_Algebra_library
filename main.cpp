#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {
//    testing matrices:
    Matrix<int> A(4,2);
    A = {1,1,1,1,1,1,1,1};
    cout << A(0,1)<< endl;
    cout << A.cols() << endl;

    Matrix<int> B(2, 4);
    B = {2,2,2,2,2,2,2,2};
//
//    Matrix<int> C = B+A;
//    cout << C;
//    cout << A;

//    Matrix<int> D = 1 + B;
//    cout << B;
//    cout << D;

    Matrix<int> C = A * B;
    cout << C << endl;
//    B *=2;
//    cout << C << endl;


//    testing vectors:
    Vector<int > vec2(3);
    Vector<int> vec1(3);
//    Vector<int> vec(3);
    vec2 = {4, 3, 2};
    vec1 = {10, 10, 10};

    cout << "vec2: "  << vec2 << endl;
    cout << "vec1: "   << vec1  <<endl;

//    Vector<int> vector1 = vec * vec2;
//    cout << vector1 << endl;
//    float_t vec = vec1 * vec2;
    vec1 *= 8;

    cout << "res: " << vec1;

    return 0;
}