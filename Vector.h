#ifndef LINEAR_ALGEBRA_LIBRARY_VECTOR_H
#define LINEAR_ALGEBRA_LIBRARY_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <cmath>
#include "Vector.h"
#include <thread>
#include <mutex>
#include <vector>    

template <class T>
class Vector {

private:

    struct VectorMemory {
        T *data;
        size_t cols;

        VectorMemory(size_t c) : cols(c)
        {
            data = new T[cols];
        }

        ~VectorMemory() // RAII
        {
            delete[] data;
        }

        inline T &operator()(size_t i)
        {
            return *(data + i);
        }

        inline const T &operator()(size_t i) const
        {
            return *(data + i);
        }

        VectorMemory (const VectorMemory& other):
        cols(other.cols)
        {
            data = new T[other.cols];
            std::copy(other.data, other.data + cols, data);
        }

        static void swap(VectorMemory & a, VectorMemory & b){
            std::swap(a.data, b.data);
            std::swap(a.cols, b.cols);
        }


        VectorMemory& operator= (const VectorMemory& b)
        {
            VectorMemory temp(b);
            VectorMemory::swap(temp, *this);
            return *this;
        }

//    Vector(const Vector<T>& other) : vec_data(other.cols())
//    {
//        copy(other.vec_data.data, other.vec_data.data + vec_data.cols, vec_data.data);
//    }
//
//        VectorMemory (const VectorMemory<T>& other):
//                vec_data(other.cols())
//        {
//            copy(other.vec_data.data, other.vec_data.data + vec_data.cols, vec_data.data);
//        }
//
////                cols(other.cols)
////        {
////            data = new T[other.cols];
////            copy(other.vect_data.data, other.data + cols, data);      //???????????????
////
////        }

    } vec_data;

public:

    Vector(size_t c) : vec_data(c) {}



    Vector(std::initializer_list<T> ilst) : vec_data(std::sqrt(ilst.size()))
    {
        assert(std::sqrt(ilst.size())==ilst.size());
        for (auto i = begin(ilst); i != end(ilst); i++)
        {
            vec_data.data[i - begin(ilst)] = *i;
        }

    }

    Vector& operator = (std::initializer_list<T> ilst)
    {
        if (ilst.size() != vec_data.cols)
        {
            throw std::out_of_range("Too big lst to initialize vector with");
        }

        for (auto i = begin(ilst); i != end(ilst); i++)
        {
            vec_data.data[i - begin(ilst)] = *i;
        }
        //std::copy(matr_data.data, matr_data.data + (matr_data.rows * matr_data.cols), begin(ilst));
        return *this;
    }


    size_t cols() const
    {
        return vec_data.cols;
    }

    T* const vecToArr()
    {
        return vec_data.data;
    }

    inline T& operator()(size_t i) {
        if (i >= vec_data.cols || i < 0) {
            throw std::out_of_range ("Vector index out of range");
        }
        return vec_data(i);
    }

    inline const T& operator()(size_t i) const {
        if (i >= vec_data.cols || i < 0) {
            throw std::out_of_range ("Vector index out of range");
        }
        return vec_data(i);

    }

    friend std::ostream& operator<<(std::ostream& out, const Vector& val){
        std::string c = "";
        for (int i = 0; i < val.vec_data.cols; i++)
        {
            c += std::to_string(val(i));
            c += " ";
        }
        out << c;
        return out;
    }

    Vector& operator+=(const Vector &other)
    {
        assert(cols()==other.cols());
        Vector &self = *this;

        for (size_t i = 0; i < this->cols(); i++) {
            self(i) += other(i);
        }
        return *this;
    }

    Vector& operator-=(const Vector &other) {
        assert(cols() == other.cols());
        Vector &self = *this;

        for (size_t i = 0; i < this->cols(); i++) {
            self(i) -= other(i);
        }
        return *this;
    }

    Vector& operator+=(const T &scalar)
    {
        Vector &self = *this;
        for (size_t i = 0; i < cols(); i++) {
            self(i) = self(i) + scalar;
        }

        return self;
    }

    Vector& operator-=(const T &scalar)
    {
        Vector &self = *this;
        for (size_t i = 0; i < cols(); i++) {
            self(i) = self(i) - scalar;
        }
        return self;
    }


    float_t operator*(const Vector &other){
        const Vector &self = *this;
        float_t res_n = 0;

        for (size_t i = 0; i < cols(); i++) {
            res_n += self(i) * other(i);
        }

        return res_n;
    }

    Vector& operator*=(const T &scalar)
    {
        Vector &self = *this;
        for (size_t i=0; i < cols(); i++){
            self(i) = self(i) *scalar;
        }
        return self;
    }
    Vector &operator- ()
    {
        Vector &vect =*this;

            for (size_t i=0; i<cols(); i++){
                vect(i) =  - vect(i);
            }
        return vect;
    }

    Vector &operator+ ()
    {
        return *this;
    }

};

template<typename T>
inline Vector<T> operator+(Vector<T> left, const Vector<T> &other) {
    assert(left.cols() == other.cols());
    return left += other; //Vector+=Vector operator is overloaded inside the class
}

template<typename T>
inline Vector<T> operator+(const T &scalar, Vector<T> right) {
    return right += scalar;
}

template<typename T>
inline Vector<T> operator+(Vector<T> left, const T &scalar){
    return left += scalar;
}

template<typename T>
inline Vector<T> operator- (Vector<T> left, const Vector<T> &other){
    assert(left.cols() == other.cols());
    return left -= other;
}

template<typename T>
inline Vector<T> operator- (Vector<T> vec, const T &scalar) {
    return vec -= scalar;
}

template<typename T>
inline Vector<T> operator- (const T &scalar, Vector<T> right) {
    return -right += scalar;
}

template<typename T>
inline Vector<T> operator*(Vector<T> left, const T& scalar){
    return left *= scalar;
}

template<typename T>
inline Vector<T> operator*(const T& scalar, Vector<T> right){
    return right *= scalar;
}


#endif //LINEAR_ALGEBRA_LIBRARY_VECTOR_H