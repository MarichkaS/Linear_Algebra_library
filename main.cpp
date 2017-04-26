#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {

    int a[] = {1,2,3,4};
    Matrix<int> A(2, 2);
    //A = {1,2,3,4};
    A = a;
    cout << A(1,1)<< endl;
    cout << A << endl;
    //Matrix<int> B(2, 2);
    //B = {4, 3, 2, 1};
    //A = B;
    //cout << A(1,1) << endl;
    double b[] = {1.0, 2.0, 3.0};
    Vector<double> B(3);
    B = b;
    //cout << B << endl;    Doesn't work right now, will be fixed soon




    return 0;
}