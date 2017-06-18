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

            Vector<double> V= {1.0, 1.0};
            //V = {1.0, 1.0};
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
        Vector<double> A= {1.0, 2.0};
        Vector<double> B= {2.0, 1.0};
        // A = {1.0, 2.0};
        // B = {2.0, 1.0};

        Vector<double> Ans = {3.0, 3.0};
        Vector<double> Got = {3.0, 3.0};

        ASSERT_EQ(Ans, Got);
    }

    TEST_F(VectorTest, VectorTest_Subtraction_Test) {
        Vector<double> A = {1.0, 2.0};
        Vector<double> B = {1.0, 2.0};
        Vector<double> Ans = {0, 0};

        EXPECT_EQ(Ans, A - B);
    }

    TEST_F(VectorTest, Adding_vect_1){
        Vector<double> A = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        Vector<double> B = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        Vector<double> exp = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        Vector<double> res = A + B;

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Adding_vect_2){
        Vector<double> A = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};  // 20
        Vector<double> B = {-10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10};  // 20
        Vector<double> res = A + B;
        Vector<double> exp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // 20

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Adding_vect_3){
        Vector<double> A = {100, 1013, 132, 48, 98, 32, 120, 129, 33, 21, 43, 78};
        Vector<double> B = {39, 381, 121, 48, 23, 343, 43, 88, 923, 32, 12, 131};

        Vector<double> res = A + B;
        Vector<double> exp = {139, 1394, 253, 96, 121, 375, 163, 217, 956, 53, 55, 209};

        EXPECT_EQ(exp, res);
    }


    TEST_F(VectorTest, Subtr_vect_1){
        Vector<double> A = {100.40, 20, 31, 68, 76, 38, 60};  // 7
        Vector<double> B = {30.0, 10, 1, 7, 5, 8, 40};  // 7

        Vector<double> res = A - B;
        Vector<double> exp = {70.40,10, 30, 61, 71, 30, 20};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_2){
        Vector<double> A = {0, 21, 32, 69, 76, 30, 50};  // 7
        Vector<double> B = {30, 1, 1, 7, 5, 80, 48};  // 7
        Vector<double> res = A -= B;
        Vector<double> exp = {-30, 20, 31, 62, 71, -50, 2};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_3){
        Vector<double> A = {90.8, 54, 1.0, 35.1, 0, 10};  // 6
        Vector<double> B = {30, 13, 0, 5.2, 0.3, 3};  // 6

        Vector<double> res = A -= B;
        Vector<double> exp = {60.8, 41, 1.0, 29.9, -0.3, 7};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_4){
        Vector<double> A = {90.8, 54, 1.0, 35.1, 0, 4};  // 6
        Vector<double> B = {20, 13, 0, 5.2, 0.9, 3};  // 6

        Vector<double> res = A - B;
        Vector<double> exp = {70.8, 41, 1.0, 29.9, -0.9, 1};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_5){
        Vector<double> A = {0.1, 4, 0.2, -0.85, 9.1, 100};  // 6
        Vector<double> B = {0.3, 4, 0.7, 0, 9.2, -2};  // 6

        Vector<double> res = B -= A;
        Vector<double> exp = {0.2, 0, 0.5, 0.85, 0.1, -102};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Subtr_vect_6){
        Vector<double> A = {0.1, 3.2, 0.5, -0.835, 9.0, 1000};  // 6
        Vector<double> B = {0.3, 4, 0.7, 0, 9.2, -2.98};  // 6

        Vector<double> res = B - A;
        Vector<double> exp = {0.2, 0.8, 0.2, 0.835, 0.2, -1002.98};

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Mult_vect_1){
        Vector<double> A = {100.0, 0, 2.0, 1.0, 3.0};
        Vector<double> B = {0, 10.0, 1.0, 7.0, 5.0};

        float_t  res = A * B;
        float_t exp = 24.0;

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Mult_vect_2){
        Vector<double> A = {0, 0, 2.0, 0, 0};
        Vector<double> B = {0, 0, 1.0, 1.0, 0};

        float_t  res = A * B;
        float_t exp = 2.0;

        EXPECT_EQ(exp, res);
    }

    TEST_F(VectorTest, Mult_vect_3){
        Vector<double> A = {0, 0, 100.0, 2.0, 5.0, 11.0, 2.0, 4.0};  // 8
        Vector<double> B = {0, 0, 1.0, 1.0, 3.0, 1.0, 4.0, 0};  // 8

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