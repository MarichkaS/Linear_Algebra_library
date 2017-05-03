#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {

    int a[] = {1,2,3,4};
    Matrix<int> A(2, 2);
    int b[] = {1,2,3,4};
    Matrix<int> B(2, 2);
//    cout << A = B << endl;
    A = {1,2,3,4};
    //A = a;
    B = A;
    cout << A << endl;
    cout << B << endl;
//    cout << A << endl;
//    cout << A.rows();
//    Matrix<int> C = A*B;
//
//    cout << C(0,0);
//
//    Vector<double> V1(3);
//    Vector<double> V2(3);
//    double v1[] = {2, 0, 0};
//    double v2[] = {1.0, 2.0, 3.0};
//    V1 = v1;
//    V2 = v2;
//    double bb = a[1];
//    Vector<double> C(3);
//    cout << V1 * V2 << endl;
//    cout << v1 + V2 << endl;
//    cout << v1 - V2 << endl;



    return 0;
}
