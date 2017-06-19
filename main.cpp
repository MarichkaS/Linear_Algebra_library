#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "timeMeasuring.h"

using namespace std;

int main() {
//    testing matrices:

    vector<int> vc1;
    vector<int> vc2;
    for (int i = 0; i < 1000000; i++)
    {
        vc1.push_back(1);
        vc2.push_back(2);
    }
    Matrix<int> A(4,2);
    A = {1,1,1,1,1,1,1,1};
    //A.fromVector(vc1);

    Matrix<int> B(2, 4);
    B = {2,2,2,2,2,2,2,2,};
    //B.fromVector(vc2);
    auto startt = getCurrentTimeFenced();

    //B+A;
    //auto end1 = getCurrentTimeFenced();

    A + 456;
    auto end1 = getCurrentTimeFenced();

    A * B;
    auto end2 = getCurrentTimeFenced();

    A * 456;
    auto end3 = getCurrentTimeFenced();

    //    cout << C;
//    cout << A;

//    Matrix<int> D = 1 + B;
//    cout << B;
//    cout << D;

    cout << toMicroSec(end1 - startt) << endl;
    cout << toMicroSec(end2 - end1) << endl;
    cout << toMicroSec(end3 - end2) << endl;
    //cout << toMicroSec(end4 - end3) << endl;
//    B *=2;
//    cout << C << endl;













////    testing vectors:
//    Vector<int > vec2(3);
//    Vector<int> vec1(3);
////    Vector<int> vec(3);
//    vec2 = {4, 3, 2};
//    vec1 = {10, 10, 10};
//
//    cout << "vec2: "  << vec2 << endl;
//    cout << "vec1: "   << vec1  <<endl;
//
////    Vector<int> vector1 = vec * vec2;
////    cout << vector1 << endl;
////    float_t vec = vec1 * vec2;
//    vec1 *= 8;
//
//    cout << "res: " << vec1;

    return 0;
}