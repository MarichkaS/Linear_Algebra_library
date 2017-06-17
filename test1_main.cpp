#include <gtest/gtest.h>
#include "Matrix.h"

namespace {
// The fixture for testing class Matrix.
    class MatrixTest : public ::testing::Test {
    protected:
        MatrixTest() {
            // for set-up work for each test here.

            Matrix<int> M(2, 2);
            M = {1, 1, 1, 1};
        }

        virtual ~MatrixTest() {
            // for clean-up work that doesn't throw exceptions here.
        }

        virtual void SetUp() {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        virtual void TearDown() {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Matrix.
        //Matrix<int> M;
    };

    TEST_F(MatrixTest, MatrixTest_Addition_Test) {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A = {1, 2, 3, 4};
        B = {1, 2, 3, 4};

        Matrix<int> Ans(2, 2);
        Ans = {2, 4, 6, 8};
        Matrix<int> Get(2, 2);
        Get = {2, 4, 6, 8};
        ASSERT_EQ(Ans, Get);
    }

    TEST_F(MatrixTest, MatrixTest_Subtraction_Test) {
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A = {1, 2, 3, 4};
        B = {1, 2, 3, 4};

        Matrix<int> Ans(2, 2);
        Ans = {0, 0 ,0,0};
        EXPECT_EQ(Ans, A-B);
    }

    TEST_F(MatrixTest, Adding_matr_first){
        Matrix<int> A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
        Matrix<int> B = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

        Matrix<int> res = A + B;
        Matrix<int> exp = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Adding_matr_sec){
        Matrix<int> A = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, };
        Matrix<int> B = {-10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, };

        Matrix<int> res = A + B;
        Matrix<int> exp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Adding_matr_thr){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 1, 1, 1, 1};
        Matrix<int> B = {39, 381, 121, 48, 23, 343, 43, 88, 923, 32, 12, 131, 1, 1, 1, 1};

        Matrix<int> res = A + B;
        Matrix<int> exp = {139, 1394, 253, 86, 121, 375, 163, 217, 956, 53, 55, 209, 2, 2, 2, 2};

        EXPECT_EQ(exp, res);
    }


    TEST_F(MatrixTest, Subtr_matr_1){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        Matrix<int> B = {39, 381, 121, 48, 23, 343, 43, 88, 923, 32, 12, 131, 5, 988, 425, 16,};

        Matrix<int> res = A - B;
        Matrix<int> exp = {61,632,11,-10,75,-311,77,41,-890,-11, 31,-53,123,-967,-347,313,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Subtr_matr_2){
        Matrix<int> A = {-100, -1013, -132, -38, -98, -32, -120, -129, -33, -21, -43, -78, -128, -21, -78, -329,};
        Matrix<int> B = {-39, -381, -121, -48, -23, -343, -43, -88, -923, -32, -12, -131, -5, -988, -425, -16,};

        Matrix<int> res = A - B;
        Matrix<int> exp = { -61,-632,-11, 10, -75, 311, -77, -41, 890,  11, -31,  53,-123, 967, 347,-313};

        EXPECT_EQ(exp, res);
    }



    //cout << A << endl;
    //B += A;
    //cout << "Result of adding 2 matrices with +=:" << endl;
    //cout << B << endl;

//    Matrix<int> C(2, 2);
//    Matrix<int> D(2, 2);
//    Matrix<int> Mat(2, 2);
//
//    D = 2 * B;
//    cout << "Result of multiplying scalar and matrix with *"<<
//    endl;
//    cout << D <<
//    endl;

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
}  // namespace

int main(int ac, char* av[])
{
   testing::InitGoogleTest(&ac, av);
   return RUN_ALL_TESTS();
}