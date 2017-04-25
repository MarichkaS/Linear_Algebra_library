#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {

    int a[] = {1,2,3,4};
    Matrix<int> A(2, 2);
    //A = {1,2,3,4};
    A = a;
    cout << A(1,1);
    Matrix<int> B(2, 2);
    B = {4,3,2,1};
    A = B;
    cout << A(1,1) << endl;
    Vector<double> b(3);
    b = {1.0, 2.0, 3.0};
    cout << b(3) << endl;




    return 0;
}