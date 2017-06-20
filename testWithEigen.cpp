//
// Created by dzvinka on 18.06.17.
//

#include <iostream>
#include <Eigen/Dense>
#include "timeMeasuring.h"

using Eigen::MatrixXd;
int main()
{
    MatrixXd A = MatrixXd::Random(1000,1000);
    MatrixXd B = MatrixXd::Random(1000,1000);
    auto startt = getCurrentTimeFenced();

    MatrixXd C = B+A;
    auto end1 = getCurrentTimeFenced();

    C = A / 456;
    auto end2 = getCurrentTimeFenced();

    C = A * B;
    auto end3 = getCurrentTimeFenced();

    C = A * 456;
    auto end4 = getCurrentTimeFenced();

    cout << toMicroSec(end1 - startt) << endl;
    cout << toMicroSec(end2 - end1) << endl;
    cout << toMicroSec(end3 - end2) << endl;
    cout << toMicroSec(end4 - end3) << endl;
    //cout << C << endl;

}
