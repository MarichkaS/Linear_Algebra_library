#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {
//    testing matrices:
    Matrix<int> A(4,2);
    A = {1,1,1,1,1,1,1,1};

    Matrix<int> B(2, 4);
    B = {2,2,2,2,2,2,2,2};
//    cout << B << endl;

    Matrix<int> C(2, 2);
    C = {2, 2, 2, 2,};
//    cout << C;

//    A = A * B;
//    cout << A << endl;

//    B +=2;
//    cout << B << endl;


//    testing vectors:
    Vector<int > vec2(3);
    Vector<int> vec1(3);
    Vector<int> vec3(12);
    Vector<int > vec4(12);
    vec2 = {4, 3, 2};
    vec1 = {10, 10, 10};
    vec3 = {1, 2, 3, 4,5,6,7,8,9,10,11,12};
    vec4 = {1,1,1,1,1,1,1,1,1,1,1,1,};

//    cout << "vec2: "  << vec2 << endl;
//    cout << "vec1: "   << vec1  <<endl;
//    vec1 += vec2;
//    cout << "res: " << vec1;

    float_t res=0;
    cout << "vec2: "  << vec3 << endl;
    cout << "vec1: "   << vec4  <<endl;
     res = vec3 * vec4;
    cout << "res: " << res;
////    Vector<int> vector1 = vec * vec2;
////    cout << vector1 << endl;
////    float_t vec = vec1 * vec2;


    return 0;
}