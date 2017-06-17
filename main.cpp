#include <iostream>
#include "Matrix.h"
//#include "Vector.h"

using namespace std;

int main() {
//    testing matrices:
    Matrix<int> A(2,2);
    A = {1, 2, 3, 4};

    Matrix<int> B(2, 2);
     B = {5, 7, 1, 8};

    Matrix<int> C = B+A;
    cout << C;

    //Matrix<int> C = A.multiplication(B);
    //cout << C;



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