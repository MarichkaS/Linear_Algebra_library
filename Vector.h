#ifndef LINEAR_ALGEBRA_LIBRARY_VECTOR_H
#define LINEAR_ALGEBRA_LIBRARY_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class Vector {

private:

    struct VectorMemory
    {
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

        void bf() const {}

    } vec_data;

public:

    Vector(size_t c) : vec_data(c) {}

    Vector(const Vector<T>& other) : vec_data(other.cols())
    {
        copy(other.vec_data.data, other.vec_data.data + vec_data.cols, vec_data.data);
    }

    void operator = (T* arr[])
    {
         std::copy(vec_data.data, vec_data.data + cols(), arr);
//        for (int i = 0; i < vec_data.cols; i ++)
//        {
//            vec_data.data[i] = arr[i];
//        }

    }
    void operator = (std::initializer_list<T> ilst)
    {
        if (ilst.size() != vec_data.cols)
        {
            throw std::out_of_range("Too big arr to initialize vector with");
        }

        for (auto i = begin(ilst); i != end(ilst); i++)
        {
            vec_data.data[i - begin(ilst)] = *i;
        }
    }

    size_t cols() const
    {
        return vec_data.cols;
    }

    T* const vecToArr()
    {
        return vec_data.data;
    }

    Vector& operator = (const Vector<T>& other)
    {
        vec_data = VectorMemory(other.vec_data.cols);
        copy(other.vec_data.data, other.vec_data.data + vec_data.cols, vec_data.data);
        return *this;
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
        double res = 0;
        for (size_t i = 0; i < this->cols(); i++) {
            res += self(i) * other(i);
        }
        return res;
    }

    Vector& operator+=(const Vector &other)
    {
        assert(cols()==other.cols());
        Vector &self = *this;
        for (size_t i = 0; i < this->cols(); i++) {
             self(i) += other(i);
        }
        return *this;  //memory saving?
    }

    Vector operator-=(const Vector &other) {
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
inline Vector<T> operator+(const T &scalar, Vector<T> other) {
    return other += scalar;
}

template<typename T>
inline Vector<T> operator+(Vector<T> vec, const T &scalar){
    return vec += scalar;
}



//inline Vector operator+(Vector x, const  Vector& y);

#endif //LINEAR_ALGEBRA_LIBRARY_VECTOR_H
