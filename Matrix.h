//
// Created by dzvinka on 25.04.17.
//

#ifndef LINEAR_ALGEBRA_LIBRARY_MATRIX_H
#define LINEAR_ALGEBRA_LIBRARY_MATRIX_H

#include <iostream>
#include <stdexcept>

template <class T>
class Matrix {

private:

    struct MatrixMemory {

        T *data;

        size_t cols, rows;

        MatrixMemory(size_t r, size_t c) :

                cols(c), rows(r) {

            data = new T[cols * rows];

        }


        ~MatrixMemory() // RAII

        {

            delete[] data;

        }


        inline T &operator()(size_t i, size_t j) {

            return *(data + i * cols + j);

        }

        inline const T &operator()(size_t i, size_t j) const {

            return *(data + i * cols + j);

        }

        void bf() const {}


    } matr_data;

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
    size_t rows()
    {
        return matr_data.rows;
    }

    size_t cols()
    {
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
        out << val(1, 1);
        return out;
    }

};



#endif //LINEAR_ALGEBRA_LIBRARY_MATRIX_H
