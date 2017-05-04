//
// Created by dzvinka on 25.04.17.
//

#ifndef LINEAR_ALGEBRA_LIBRARY_MATRIX_H
#define LINEAR_ALGEBRA_LIBRARY_MATRIX_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <cmath>

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

        MatrixMemory (const MatrixMemory& other):
                rows(other.rows), cols(other.cols)
        {
            data = new T[other.rows * other.cols];
            copy(other.data, other.data + (rows * cols), data);
        }

        static void swap(MatrixMemory & a, MatrixMemory & b)
        {
            std::swap(a.data, b.data);
            std::swap(a.cols, b.cols);
            std::swap(a.rows, b.rows);
        }

        MatrixMemory& operator=(const MatrixMemory& b)
        {
            MatrixMemory temp(b);
            MatrixMemory::swap(temp, *this);
            return *this;
        }

    } matr_data;


public:

    Matrix(size_t r, size_t c) : matr_data(c, r) {}
#if 0
    void operator = (T* arr[])
    {

        //std::cout << (sizeof(arr) / sizeof(arr[0])) << std::endl;
//        if ((sizeof(arr) / sizeof(arr[0]) ) > matr_data.rows * matr_data.cols) //TODO:FIX
//        {
//            throw std::out_of_range("Too big arr to initialize matrix with");
//        }
        std::copy(matr_data.data, matr_data.data + (matr_data.rows * matr_data.cols), arr);

    }
#endif
    // square matrix only
    Matrix(std::initializer_list<T> ilst) : matr_data(std::sqrt(ilst.size()), std::sqrt(ilst.size()))
    {
        assert(std::sqrt(ilst.size())*std::sqrt(ilst.size())==ilst.size());
        for (auto i = begin(ilst); i != end(ilst); i++)
        {
            matr_data.data[i - begin(ilst)] = *i;
        }

    }

    Matrix& operator= (std::initializer_list<T> ilst)
    {
        if (ilst.size() != matr_data.rows * matr_data.cols)
        {
            throw std::out_of_range("Too big lst to initialize matrix with");
        }

        for (auto i = begin(ilst); i != end(ilst); i++)
        {
            matr_data.data[i - begin(ilst)] = *i;
        }
        //std::copy(matr_data.data, matr_data.data + (matr_data.rows * matr_data.cols), begin(ilst));
        return *this;
    }

    size_t rows() const {
        return matr_data.rows;
    }

    size_t cols() const {
        return matr_data.cols;
    }

    T* const matrToArr()
    {
        return matr_data.data;
    }
#if 0  // Terribly wrong!
    void resize(size_t rows, size_t cols) {
        matr_data.rows = rows;
        matr_data.cols = cols;
    }
#endif

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
            c +='\n';
        }
        out << c;
        return out;
    }


    Matrix& operator+=(const Matrix &other)
    {
        assert(cols()==other.cols() && rows()==other.rows());
        Matrix &self = *this;

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                self(i, j) += other(i, j);
            }
        }
        return *this;
    }


    Matrix& operator-=(const Matrix &other)
    {
        assert(cols()==other.cols() && rows()==other.rows());
        Matrix &self = *this;

        for (size_t i = 0; i < this->rows(); i++) {
            for (size_t j = 0; j < this->cols(); j++) {
                self(i, j) -= other(i, j);
            }
        }
        return *this;
    }

    Matrix& operator+=(const T &scalar)
    {
        Matrix &self = *this;

        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                self(i, j) = self(i, j) + scalar;
            }
        }
        return self;
    }

    Matrix& operator-=(const T &scalar)
    {
        Matrix &self = *this;

        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                self(i, j) = self(i, j) - scalar;
            }
        }
        return self;
    }

    Matrix operator*(const Matrix &other) const {
//        assert(cols == other.rows) ;

        const Matrix &self = *this;
        Matrix<int> res(rows(), cols());

        for (size_t i = 0; i < rows(); i++) {
            for (size_t k = 0; k < cols(); k++) {
                for (size_t j = 0; j < other.rows(); j++) {
                    res(i, k) = self(i, j) * other(j, k);
                }
            }
        }
        return res;
    }

//
    Matrix& operator*=(const T &scalar)
    {
        Matrix &self = *this;

        for (size_t i = 0; i < rows(); i++) {
            for (size_t j = 0; j < cols(); j++) {
                self(i, j) = self(i, j) * scalar;
            }
        }
        return self;
    }

//    Matrix operator-() const
//    {
//        const Matrix &self = *this;
//        Matrix<int> res(rows(), cols());
//
//        for (size_t i = 0; i < rows(); i++) {
//            for (size_t j = 0; j < cols(); j++) {
//                res(i, j) = -self(i, j);
//            }
//        }
//
//        return res;
//    }

};

template<typename T>
inline Matrix<T> operator+(Matrix<T> left, const Matrix<T> &other) {
    assert(left.cols() == other.cols() && left.rows() == other.rows());
    return left += other;
}

template<typename T>
inline Matrix<T> operator+(const T &scalar, Matrix<T> other) {
    return other += scalar;
}


template<typename T>
inline Matrix<T> operator+(Matrix<T> left, const T &scalar)
{
    return left += scalar;
}

template<typename T>
inline Matrix<T> operator-(Matrix<T> left, const Matrix<T> &other) {
    assert(left.cols() == other.cols() && left.rows() == other.rows());
    return left -= other;

}

template<typename T>
inline Matrix<T> operator-(Matrix<T> left, const T &scalar)
{
    return left -= scalar;
}

template<typename T>
inline Matrix<T> operator-(const T &scalar, Matrix<T> right)
{
    assert(0 && "Not implemented!");
    return Matrix<T>(1,1);
}

template<typename T>
inline Matrix<T> operator*(Matrix<T> left, const T& scalar) {
    return left *= scalar;
}

template<typename T>
inline Matrix<T> operator*(const T& scalar, Matrix<T> right) {
    return right *= scalar;
}



/*
     template <class T>
    Matrix<T> Matrix<T>::operator*(const Matrix& other) const
    {
        assert(cols == other.rows) ;

        Matrix<T> temp(rows, other.cols) ;

        for(unsigned i = 0 ; i < rows ; i++)
        {
            for(unsigned j = 0 ; j < other.cols ; j++)
            {
                temp.matrix[i][j] = 0 ;
                for(unsigned k= 0 ; k < other.rows ; k++)
                {
                    temp.matrix[i][j] = temp.matrix[i][j] + (matrix[i][k]*other.matrix[k][j]) ;
                }
            }
        }
        return temp ;
 */
#endif //LINEAR_ALGEBRA_LIBRARY_MATRIX_H
