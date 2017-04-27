#ifndef LINEAR_ALGEBRA_LIBRARY_VECTOR_H
#define LINEAR_ALGEBRA_LIBRARY_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class Vector {

private:

    struct VectorMemory {

        T *data;

        size_t cols;

        VectorMemory(size_t c) : cols(c) {

            data = new T[cols];

        }


        ~VectorMemory() // RAII

        {

            delete[] data;

        }


        inline T &operator()(size_t i) {

            return *(data + i);

        }

        inline const T &operator()(size_t i) const {

            return *(data + i);

        }


        void bf() const {}


    } vec_data;

public:

    Vector(size_t c) : vec_data(c) {}

    void operator = (T arr[])
    {
        // std::copy(std::begin(matr_data.data), std::end(matr_data.data), std::begin(arr));
        for (int i = 0; i < vec_data.cols; i ++)
        {
            vec_data.data[i] = arr[i];
        }

    }
    void operator = (std::initializer_list<T> ilst)
    {
        if (ilst.size() != vec_data.cols)
        {
            throw std::out_of_range("Too big arr to initialize vector with");
        }
        typename std::initializer_list<T>::iterator i;
        for (i = begin(ilst); i != end(ilst); i++)
        {
            vec_data.data[i - begin(ilst)] = *i;
        }
    }

    size_t cols()
    {
        return vec_data.cols;
    }

    T* const vecToArr()
    {
        return vec_data.data;
    }

    void operator = (Vector<T> v)
    {
        vec_data = VectorMemory(v.cols());
        *this = v.vecToArr();
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

    double operator*(const Vector &other){
        const Vector &self = *this;
        double result = 0;
        for (size_t i = 0; i < this->cols(); i++) {
            result += self(i) * other(i);
        }
        return result;
    }

    Vector operator+(const Vector &other) {
        const Vector &self = *this;
        Vector<double> res(this->cols());
        for (size_t i = 0; i < this->cols(); i++) {
            res(i) = self(i) + other(i);
        }
        for(int i = 0; i < res.cols(); i++){
            std::cout << res(i) << std::endl;
        }
        return res;
    }

    Vector operator-(const Vector &other) {
        const Vector &self = *this;
        Vector<double> res(this->cols());
        for (size_t i = 0; i < this->cols(); i++) {
            res(i) = self(i) - other(i);
        }
        for(int i = 0; i < res.cols(); i++){
            std::cout << res(i) << std::endl;
        }
        return res;
    }
};

//inline Vector operator+(Vector x, const  Vector& y);

#endif //LINEAR_ALGEBRA_LIBRARY_VECTOR_H
