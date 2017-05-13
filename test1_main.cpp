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

    TEST_F(MatrixTest, MatrixTest_Addition_Test){
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A = {1,2,3,4};
    B = {1,2,3,4};

    Matrix<int> Ans(2, 2);
    Ans = {2, 4, 6, 8};
    Matrix<int> Get(2, 2);
        Get = {2, 4, 6, 8};
        //ASSERT_EQ(Ans, Get);
    }

    TEST_F(MatrixTest, MatrixTest_Subtraction_Test){
        Matrix<int> A(2, 2);
        Matrix<int> B(2, 2);

        A = {1,2,3,4};
        B = {1,2,3,4};

        Matrix<int> Ans(2, 2);
        Ans = {2, 4, 6, 8};
        //EXPECT_EQ(Ans, A-B);
    }


}  // namespace

int main(int ac, char* av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}