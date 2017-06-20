#ifndef LINEAR_ALGEBRA_LIBRARY_MATRIX_H
#define LINEAR_ALGEBRA_LIBRARY_MATRIX_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <cmath>
#include "Vector.h"
#include <thread>
#include <mutex>
#include <vector>
#define NUMB_OF_THREADS 5

using namespace std;
//mutex mtx;
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

    Matrix(size_t r, size_t c) : matr_data(r, c) {}
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
        return *this;
    }

    Matrix& fromVector(std::vector<T> vc)
    {
        for (auto i = begin(vc); i != end(vc); i++)
        {
            matr_data.data[i - begin(vc)] = *i;
        }
        return *this;
    }

    Matrix& fromVector(std::vector<T> vc)
    {
        for (auto i = begin(vc); i != end(vc); i++)
        {
            matr_data.data[i - begin(vc)] = *i;
        }
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

    inline T& operator()(size_t i, size_t j) {

        if (i >= rows())
        {
            throw std::out_of_range ("rows indexes out of range");
        }
        if (j >= cols())
        {
            throw std::out_of_range ("cols indexes out of range");
        }
        return matr_data(i, j);

    }

    inline const T& operator()(size_t i, size_t j) const {

        if (i >= rows())
        {
            throw std::out_of_range ("rows indexes out of range");
        }
        if (j >= cols())
        {
            throw std::out_of_range ("cols indexes out of range");
        }
        return matr_data(i, j);

    }


    friend std::ostream& operator<<(std::ostream& out, const Matrix& val){
        string c = "";
        for (int i = 0; i < val.matr_data.rows; i++)
        {
            for (int j = 0; j< val.matr_data.cols; j++){
                c+= std::to_string(val(i, j));
                c += " ";
            }
            c +='\n';
        }
        out << c;
        return out;
    }

    bool operator==(const Matrix &other) const
    {
        if(rows()!=other.rows() || cols()!=other.cols())
            return false;
        for (int i = 0; i < matr_data.cols; i ++)
        {
            for (int j = 0; j< matr_data.rows; j ++){
                if( (*this)(i,j) != other(i,j))
                    return false;
            }
        }
        return true;
    }


    bool operator!=(const Matrix &other) const {
        return !((*this) == other);
    }


    void mtrx_addition(const Matrix other, int indx, int size){
        int r = indx / rows();
        int c = indx % cols();
        for (int i = 0; i < size; i++)
        {
            (*this)(r, c) = (*this)(r, c) + other(r, c);
            c++;
            if (c == cols())
            {
                c = 0;
                r++;
            }
        }

    }
    Matrix& operator+=(const Matrix &other)
    {
        /**
         * Parallel matrix addition (Matrix + Matrix)
         */
        std::vector<std::thread> th;


        int entriesPerTHread = (rows() * cols()) / NUMB_OF_THREADS;
        int j = 0;
        for(int i = 0; i < NUMB_OF_THREADS - 1; i++)
        {
            th.push_back(std::thread(&Matrix::mtrx_addition, this, other, j, entriesPerTHread));
            j += entriesPerTHread;
        }
        th.push_back(std::thread(&Matrix::mtrx_addition, this, other, j,
                                 entriesPerTHread + (rows() * cols()) % NUMB_OF_THREADS));
        for (auto &t : th) {
            t.join();
        }
        return *this;
    }


    void mtrx_subtraction(const Matrix other, int indx, int size){

        int r = indx / rows();
        int c = indx % cols();
        for (int i = 0; i < size; i++)
        {
            (*this)(r, c) = (*this)(r, c) - other(r, c);
            c++;
            if (c == cols())
            {
                c = 0;
                r++;
            }
        }

    }

    Matrix& operator-=(const Matrix &other)
    {
        /**
         * Parallel subtraction (Matrix - Matrix)
         */
        std::vector<std::thread> th;

        int entriesPerTHread = (rows() * cols()) / NUMB_OF_THREADS;
        int j = 0;
        for(int i = 0; i < NUMB_OF_THREADS - 1; i++)
        {
            th.push_back(std::thread(&Matrix::mtrx_subtraction, this, other, j, entriesPerTHread));
            j += entriesPerTHread;
        }
        th.push_back(std::thread(&Matrix::mtrx_subtraction, this, other, j,
                                 entriesPerTHread + (rows() * cols()) % NUMB_OF_THREADS));
        for (auto &t : th) {
            t.join();
        }
        return *this;
    }

    void sc_addition(double scalar, int indx, int size) {

        int r = indx / rows();
        int c = indx % cols();
        for (int i = 0; i < size; i++)
        {
            (*this)(r, c) = (*this)(r, c) + scalar;
            c++;
            if (c == cols())
            {
                c = 0;
                r++;
            }
        }
    }

    Matrix& operator+=(const T &scalar)
    {
        /**
         * Parallel addition of scalar to matrix (Matrix + scalar)
         */
        std::vector<std::thread> th;

        int entriesPerTHread = (rows() * cols()) / NUMB_OF_THREADS;
        int j = 0;
        for(int i = 0; i < NUMB_OF_THREADS - 1; i++)
        {
            th.push_back(std::thread(&Matrix::sc_addition, this, scalar, j, entriesPerTHread));
            j += entriesPerTHread;
        }
        th.push_back(std::thread(&Matrix::sc_addition, this, scalar, j,
                                 entriesPerTHread + (rows() * cols()) % NUMB_OF_THREADS));
        for (auto &t : th) {
            t.join();
        }
        return *this;
    }


    void sc_subtraction(double scalar, int indx, int size) {

        int r = indx / rows();
        int c = indx % cols();
        for (int i = 0; i < size; i++)
        {
            (*this)(r, c) = (*this)(r, c) - scalar;
            c++;
            if (c == cols())
            {
                c = 0;
                r++;
            }
        }
    }

    Matrix& operator-=(const T &scalar)
    {
        /**
         * Parallel subtraction (Matrix - scalar)
         */
        std::vector<std::thread> th;


        int entriesPerTHread = (rows() * cols()) / NUMB_OF_THREADS;
        int j = 0;
        for(int i = 0; i < NUMB_OF_THREADS - 1; i++)
        {
            th.push_back(std::thread(&Matrix::sc_subtraction, this, scalar, j, entriesPerTHread));
            j += entriesPerTHread;
        }
        th.push_back(std::thread(&Matrix::sc_subtraction, this, scalar, j,
                                 entriesPerTHread + (rows() * cols()) % NUMB_OF_THREADS));

        for (auto &t : th) {
            t.join();
        }
        return *this;
    }


    Matrix<T> operator*(const Matrix<T> &other)
    {
        /**
        *  Parallel multiplication of two matrices
        */
        if (cols() != other.rows())
        {
            throw out_of_range("Invalid matrix dimensions for multiplication");
        }
        const Matrix<T> &self = *this;
        Matrix<T> res(rows(), other.cols());
        int rowsPerThread = rows() / NUMB_OF_THREADS;

        std::vector<std::thread> workingThreads;
        int j = 0;
        for (int i = 0; i < NUMB_OF_THREADS - 1; i++) {
            workingThreads.push_back(thread(&Matrix::multthread, this, cref(other),
                                            cref(self), ref(res), j, rowsPerThread));
            j += (rowsPerThread);
        }
        workingThreads.push_back(thread(&Matrix::multthread, this, cref(other),
                                        cref(self), ref(res), j, rowsPerThread + rows() % NUMB_OF_THREADS));

        for (auto &t : workingThreads) {
            t.join();
        }
        return res;
    }


    void multthread(const Matrix& other, const Matrix &self, Matrix &result, int indxofrow, int rowperThread)
    {
        for (int k = 0; k < rowperThread; k++) {
            auto index = result.matr_data.data + (indxofrow + k) * result.cols();
            vector<T> res(other.cols());
            for (int j = 0; j < other.cols(); j++) {
                for (int i = 0; i < other.rows(); i++) {
                    res[j] += self(indxofrow + k, i) * other(i, j);
                }
            }
            copy(begin(res), end(res), index);
        }
    }

    void sc_product(double scalar, int indx, int size) {

        int r = indx / rows();
        int c = indx % cols();
        for (int i = 0; i < size; i++)
        {
            (*this)(r, c) = (*this)(r, c) * scalar;
            c++;
            if (c == cols())
            {
                c = 0;
                r++;
            }
        }

    }

    Matrix& operator*=(const T &scalar)
    {
        /**
         * Parallel multiplication by scalar
         */
        std::vector<std::thread> th;

        int entriesPerTHread = (rows() * cols()) / NUMB_OF_THREADS;
        int j = 0;
        for(int i = 0; i < NUMB_OF_THREADS - 1; i++)
        {
            th.push_back(std::thread(&Matrix::sc_product, this, scalar, j, entriesPerTHread));
            j += entriesPerTHread;
        }
        th.push_back(std::thread(&Matrix::sc_product, this, scalar, j,
                                 entriesPerTHread + (rows() * cols()) % NUMB_OF_THREADS));

        for (auto &t : th) {
            t.join();
        }
        return *this;
    }

    Matrix &operator- ()
    {
        Matrix &mat = *this;


        for (size_t i=0; i<rows(); i++)
            for (size_t j=0; j<cols(); j++)
                mat(i, j) =  - mat(i, j);
        return mat;
    }

    Matrix &operator+ ()
    {
        return *this;
    }

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
    return -right+=scalar;
}

template<typename T>
inline Matrix<T> operator*(Matrix<T> left, const T& scalar) {
    return left *= scalar;
}

template<typename T>
inline Matrix<T> operator*(const T& scalar, Matrix<T> right) {
    return right *= scalar;
}
#endif //LINEAR_ALGEBRA_LIBRARY_MATRIX_H