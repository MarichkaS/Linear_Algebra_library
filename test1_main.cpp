#include <gtest/gtest.h>
#include "Matrix.h"

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
        Matrix<int> Get = A+=B;
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

    TEST_F(MatrixTest, Subtr_matr_3){
        Matrix<int> A = {-100, -1013, -132, -38, -98, -32, -120, -129, -33, -21, -43, -78, -128, -21, -78, -329,};
        Matrix<int> B = {-39, -381, -121, -48, -23, -343, -43, -88, -923, -32, -12, -131, -5, -988, -425, -16,};

        Matrix<int> res = A -= B;
        Matrix<int> exp = { -61,-632,-11, 10, -75, 311, -77, -41, 890,  11, -31,  53,-123, 967, 347,-313};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Subtr_matr_4){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        float b = 10;
        Matrix<int > res = A-=b;
        Matrix<int > exp = {90, 1003, 122, 28, 88, 22, 110, 119, 23, 11, 33, 68, 118, 11, 68, 319,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Subtr_matr_5){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        Matrix<int > res = -A;
        Matrix<int > exp = {-100, -1013, -132, -38, -98, -32, -120, -129, -33, -21, -43, -78, -128, -21, -78, -329,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Subtr_matr_6){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        int b = 10;
        Matrix<int > res = A - b;
        Matrix<int > exp = {90, 1003, 122, 28, 88, 22, 110, 119, 23, 11, 33, 68, 118, 11, 68, 319,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Subtr_matr_7){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        int b = 10;
        Matrix<int > res = b - A;
        Matrix<int > exp = {-90, -1003, -122, -28, -88, -22, -110, -119, -23, -11, -33, -68, -118, -11, -68, -319,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, ScalPlusMatrix_1){
        Matrix<int> A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        float b = 1;
        Matrix<int > res = A+=b;
        Matrix<int > exp = {101, 1014, 133, 39, 99, 33, 121, 130, 34, 22, 44, 79, 129, 22, 79, 330,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, ScalPlusMatrix_2){
        Matrix<double > A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        double b = 21/3;
        Matrix<double > res = b + A;
        Matrix<double > exp = {107.0, 1020.0, 139.0, 45.0, 105.0, 39.0, 127.0, 136.0, 40.0, 28.0, 50.0, 85.0, 135.0, 28.0, 85.0, 336.0,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, ScalPlusMatrix_3){
        Matrix<double > A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        double b = 21/3;
        Matrix<double > res = A + b;
        Matrix<double > exp = {107.0, 1020.0, 139.0, 45.0, 105.0, 39.0, 127.0, 136.0, 40.0, 28.0, 50.0, 85.0, 135.0, 28.0, 85.0, 336.0,};

        EXPECT_EQ(exp, res);
    }


    TEST_F(MatrixTest, Matrix_multipl){
        Matrix<int > A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        Matrix<int> B = {-39, -381, -121, -48, -23, -343, -43, -88, -923, -32, -12, -131, -5, -988, -425, -16,};
        Matrix<int > res = A * B;
        Matrix<int > exp = {-149225, -427327, -73393, -111844, -115963,-179606,-69499,-25304,-41849,-98216,-38562,-10313, -79114, -383519, -157152,-23474};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Matrix_multipl_2){
        Matrix<int > A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        int b = 10;
        Matrix<int > res = A*=b;
        Matrix<int > exp = {1000, 10130, 1320, 380, 980, 320, 1200, 1290, 330, 210, 430, 780, 1280, 210, 780, 3290,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Matrix_multipl_3){
        Matrix<int > A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        int b = 10;
        Matrix<int > res = A * b;
        Matrix<int > exp = {1000, 10130, 1320, 380, 980, 320, 1200, 1290, 330, 210, 430, 780, 1280, 210, 780, 3290,};

        EXPECT_EQ(exp, res);
    }

    TEST_F(MatrixTest, Matrix_multipl_4){
        Matrix<int > A = {100, 1013, 132, 38, 98, 32, 120, 129, 33, 21, 43, 78, 128, 21, 78, 329,};
        int b = 10;
        Matrix<int > res = b * A;
        Matrix<int > exp = {1000, 10130, 1320, 380, 980, 320, 1200, 1290, 330, 210, 430, 780, 1280, 210, 780, 3290,};

        EXPECT_EQ(exp, res);
    }
int main(int ac, char* av[])
{
   testing::InitGoogleTest(&ac, av);
   return RUN_ALL_TESTS();
}
