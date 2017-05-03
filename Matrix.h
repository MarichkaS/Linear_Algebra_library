//
// Created by dzvinka on 25.04.17.
//

#ifndef LINEAR_ALGEBRA_LIBRARY_MATRIX_H
#define LINEAR_ALGEBRA_LIBRARY_MATRIX_H

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
template <class T>
class Matrix {

private:

    struct MatrixMemory {
        T *data;
        size_t cols, rows;

        MatrixMemory(size_t r, size_t c) :
                cols(c), rows(r)
        {
            data = new T[cols * rows];
        }

        ~MatrixMemory() // RAII
        {
            delete[] data;
        }

        inline T &operator()(size_t i, size_t j) {
            return *(data + i * cols + j);
        }

        inline const T &operator()(size_t i, size_t j) const
        {
            return *(data + i * cols + j);
        }

        void bf() const {}
    }
            matr_data;

public:

    Matrix(size_t r, size_t c) : matr_data(c, r) {}
    void operator = (T arr[])
    {
       // std::copy(std::begin(matr_data.data), std::end(matr_data.data), std::begin(arr));
        //std::cout << (sizeof(arr) / sizeof(arr[0])) << std::endl;
        if ((sizeof(arr) / sizeof(arr[0]) ) > matr_data.rows * matr_data.cols) //TODO:FIX
        {
            throw std::out_of_range("Too big arr to initialize matrix with");
        }
        for (int i = 0; i < matr_data.cols * matr_data.rows; i ++)
        {
            matr_data.data[i] = arr[i];
        }

    }
    void operator = (std::initializer_list<T> ilst)
    {
        if (ilst.size() != matr_data.rows * matr_data.cols)
        {
            throw std::out_of_range("Too big lst to initialize matrix with");
        }
        typename std::initializer_list<T>::iterator i;
        for (i = begin(ilst); i != end(ilst); i++)
        {
            matr_data.data[i - begin(ilst)] = *i;
        }
    }
    size_t rows()const {
        return matr_data.rows;
    }

    size_t cols() const {
        return matr_data.cols;
    }

    T* const matrToArr()
    {
        return matr_data.data;
    }

    void operator = (Matrix<T> m)
    {
        matr_data = MatrixMemory(m.rows(), m.cols());
        *this = m.matrToArr();
    }

    inline T& operator()(size_t i, size_t j) {
        if (i >= matr_data.rows || j >= matr_data.cols) {
            throw std::out_of_range ("Matrix indexes out of range");
        }
        return matr_data(i, j);

    }

    inline const T& operator()(size_t i, size_t j) const {
        if (i >= matr_data.rows || j >= matr_data.cols) {
            throw std::out_of_range ("Matrix indexes out of range");
        }
        return matr_data(i, j);

    }


    friend std::ostream& operator<<(std::ostream& out, const Matrix& val){
        string c = "";
        for (int i = 0; i < val.matr_data.cols; i ++)
        {
            for (int j = 0; j< val.matr_data.rows; j ++){
                c+= std::to_string(val(i, j));
                c += " ";
            }
        }
        out << c;
        return out;
    }


    Matrix operator*(const Matrix &other) const {
        const Matrix &self = *this;
        Matrix<int> res(this->rows(), this->cols());

        for (size_t i = 0; i < this->rows(); i++) {
            cout << "1" <<endl;
            for (size_t k = 0; k < this->cols(); k++) {
                cout <<"2"<<endl;
                for (size_t j = 0; j < other.rows(); j++) {
                    cout << other.rows() << "qdq";
                    res(i, k) += self(i, j) * other(j, k);
                }
            }
        }
        return res;
    }

    Matrix operator+(const Matrix &other) const
    {
        const Matrix &self = *this;
        Matrix<int> res(this->rows(), this->cols());

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                res(i, j) = self(i, j) + other(i, j);
            }
        }

        return res;

    }

    Matrix operator-(const Matrix &other) const
    {
        const Matrix &self = *this;
        Matrix<int> res(this->rows(), this->cols());

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                res(i, j) = self(i, j) - other(i, j);
            }
        }

        return res;
    }

    Matrix operator-() const
    {
        const Matrix &self = *this;
        Matrix<int> res(this->rows(), this->cols());

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                res(i, j) = -self(i, j);
            }
        }

        return res;
    }

    void operator+=(const Matrix &other)
    {
        Matrix &self = *this;
        self = self + other;
    }

    void operator-=(const Matrix &other)
    {
        Matrix &self = *this;
        self = self - other;
    }

    void operator*=(const Matrix &other)
    {
        Matrix &self = *this;
        self = self * other;
    }

    Matrix operator*(double scalar) const
    {
        const Matrix &self = *this;
        Matrix<int> res(this->rows(), this->cols());

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                res(i, j) = self(i, j) * scalar;
            }
        }

        return res;
    }

    Matrix operator+(double scalar) const
    {
        const Matrix &self = *this;
        Matrix<int> res(this->rows(), this->cols());

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                res(i, j) = self(i, j) + scalar;
            }
        }

        return res;
    }

    inline Matrix operator-(double scalar) const
    {
        return (*this) + (-1*scalar);
    }

    void operator*=(double scalar)
    {
        Matrix &self = *this;

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                self(i, j) = self(i, j) * scalar;
            }
        }
    }


    inline void operator+=(double scalar)
    {
        *this = (*this) + scalar;
    }

//    inline void operator-=(double scalar)
//    {
//        *this = (*this) - scalar;
//    }

//    const Matrix Matrix::operator * (const Matrix& an) const
//    {
//        Matrix<T> temp = an;
//        T sum_elems;
//        for( int i = 0; i < this->rows() - 1; ++i)
//        {
//            for(int j = 0; j < an.cols() - 1; ++j)
//            {
//                sum_elems = 0;
//                for( int k = 0; k < an.rows() - 1; ++k)
//                {
//                    sum_elems += matr_data.data[i][k] * an[k][j];
//                }
//
//                temp.matr_data[i][j] = sum_elems;
//            }
//        }
//        return temp;
//
//    }
//    inline Matrix& operator+(Matrix m) {
//        // first, make sure matrices can be added. if not, return original matrix
//        if (rows() != m.rows() || cols() != m.cols()) {
//            cerr << "Matrix sizes do not match. Mission impossible.";
//            return (*this);
//        }
//        Matrix new_mat(rows(), cols());
//        for (int i = 0; i < rows(); i++) {
//            for (int j = 0; j < cols(); j++) {
//                new_mat.matrToArr()[i][j] = matrToArr()[i][j] + m.matrToArr()[i][j];
//            }
//        }
//        return new_mat;
//    }
};



#endif //LINEAR_ALGEBRA_LIBRARY_MATRIX_H
