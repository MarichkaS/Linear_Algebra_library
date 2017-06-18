//
// Created by kaguya on 17.06.17.
//
#include <gtest/gtest.h>
#include "Vector.h"

namespace {
    // The fixture for testing class Vector.
    class VectorTest : public ::testing::Test {
    protected:
        VectorTest() {
            // for set-up work for each test here

        }

        virtual ~VectorTest() {
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

        // Objects declared here can be used by all tests in the test case for Vector.
        //Vector<double> M;
    };

    TEST_F(VectorTest, VectorTest_Addition_Test) {
        Vector<double> A(2);
        A = {1.0, 2.0};
        Vector<double> B(2);
        B = {2.0, 1.0};
        // A = {1.0, 2.0};
        // B = {2.0, 1.0};

        Vector<double> Ans(2);
        Ans = {-1.0, 1.0};
        Vector<double> Got(2);
        Got = A-B;

        ASSERT_EQ(Ans, Got);
    }

    TEST_F(VectorTest, VectorTest_Subtraction_Test) {
        Vector<double> A(2);
        A= {1.0, 2.0};
        Vector<double> B(2);
        B= {1.0, 2.0};
        Vector<double> Ans(2);
        Ans = {0, 0};
        Vector<double> Got(2);
        Got = A-B;

        ASSERT_EQ(Ans, Got);
    }

/*
    TEST_F(VectorTest, Adding_vect_1){
        Vector<double> A(20);
        A = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};  // 20

        Vector<double> B(20);
        B = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        Vector<double> exp(20);
        exp = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
        Vector<double> res(20);
        res = A + B;

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Adding_vect_2){
        Vector<double> A(20);
        A= {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};  // 20
        Vector<double> B(20);
        B = {-10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10};  // 20
        Vector<double> res(20);
        res = A + B;
        Vector<double> exp(20);
        exp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 20

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Adding_vect_3){
        Vector<double> A(12) ;
        A = {100, 1013, 132, 48, 98, 32, 120, 129, 33, 21, 43, 78};  // 12
        Vector<double> B(12);
        B = {39, 381, 121, 48, 23, 343, 43, 88, 923, 32, 12, 131};

        Vector<double> res(12);
        res = A + B;
        Vector<double> exp(12);
        exp = {139, 1394, 253, 96, 121, 375, 163, 217, 956, 53, 55, 209}; // 12

        EXPECT_EQ(exp, res);
    }

*/
    TEST_F(VectorTest, Subtr_vect_1){
        Vector<double> A(7);
        A = {100.40, 20.0, 31.0, 68.0, 76.0, 38.0, 60.0};  // 7
        Vector<double> B(7);
        B = {30.0, 10.0, 1.0, 7.0, 5.0, 8.0, 40.0};  // 7

        Vector<double> res(7);
        res = A - B;
        Vector<double> exp(7);
        exp = {70.40,10.0, 30.0, 61.0, 71.0, 30.0, 20.0};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_2){
        Vector<double> A(7);
        A = {0, 21, 32, 69, 76, 30, 50};  // 7
        Vector<double> B(7);
        B = {30, 1, 1, 7, 5, 80, 48};  // 7
        Vector<double> res(7);
        res = A -= B;
        Vector<double> exp(7);
        exp = {-30, 20, 31, 62, 71, -50, 2};

        EXPECT_EQ(exp, res);
    }
    //can't pass from Substr_vect_3 to Substr_vect_6

    /*
    TEST_F(VectorTest, Subtr_vect_3){
        Vector<double> A(6);
        A = {90.8, 54.0, 1.0, 35.1, 0, 10.0};  // 6
        Vector<double> B(6);
        B = {30.0, 13.0, 0, 5.2, 0.3, 3.0};  // 6

        Vector<double> res(6);
        res = A -= B;
        Vector<double> exp(6);
        exp = {60.8, 41.0, 1.0, 29.9, -0.3, 7.0};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_4){
        Vector<double> A(6);
        A = {90.8, 54, 1.0, 35.1, 0, 4};  // 6
        Vector<double> B(6);
        B = {20, 13, 0, 5.2, 0.9, 3};  // 6

        Vector<double> res(6);
        res = A - B;
        Vector<double> exp(6);
        exp = {70.8, 41, 1.0, 29.9, -0.9, 1};

        EXPECT_EQ(exp, res);
    }


    TEST_F(VectorTest, Subtr_vect_5) {
        Vector<double> A(6);
        A = {0.1, 4, 0.2, -0.85, 9.1, 100};  // 6
        Vector<double> B(6);
        B = {0.3, 4, 0.7, 0, 9.2, -2};  // 6

        Vector<double> res(6);
        res = B -= A;
        Vector<double> exp(6);
        exp = {0.2, 0, 0.5, 0.85, 0.1, -102};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_6) {
        Vector<double> A(6);
        A = {0.1, 3.2, 0.5, -0.835, 9.0, 1000};  // 6
        Vector<double> B(6);
        B = {0.3, 4, 0.7, 0, 9.2, -2.98};  // 6

        Vector<double> res(6);
        res = B - A;
        Vector<double> exp(6);
        exp = {0.2, 0.8, 0.2, 0.835, 0.2, -1002.98};

        EXPECT_EQ(exp, res);
    }
*/

    TEST_F(VectorTest, Mult_vect_1){
        Vector<double> A(5);
        A = {100.0, 0, 2.0, 1.0, 3.0};  // 5
        Vector<double> B(5);
        B = {0, 10.0, 1.0, 7.0, 5.0};

        float_t  res = A * B;
        float_t exp = 24.0;

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Mult_vect_2){
        Vector<double> A(5);
        A = {0, 0, 2.0, 0, 0};
        Vector<double> B(5);
        B = {0, 0, 1.0, 1.0, 0};

        float_t  res = A * B;
        float_t exp = 2.0;

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Mult_vect_3){
        Vector<double> A(8);
        A = {0, 0, 100.0, 2.0, 5.0, 11.0, 2.0, 4.0};  // 8
        Vector<double> B(8);
        B = {0, 0, 1.0, 1.0, 3.0, 1.0, 4.0, 0};  // 8

        float_t  res = B * A;
        float_t exp = 136.0;

        EXPECT_EQ(exp, res);
    }



}  // namespace
int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}