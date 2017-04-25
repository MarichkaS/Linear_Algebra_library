//
// Created by maria on 24.04.17.
//

#include "Vector.h"

template <class T>

class Vector {
private:

    struct VectorMemory {
        T *data;
        size_t cols;

        VectorMemory(int c) :
                cols(c) {
            data = new T[cols];
        }

        ~VectorMemory() // RAII
        {
            delete[] data;
        }

        inline T &operator()(size_t i, size_t j) {
            return i * cols + j;
        }

        inline const T &operator()(size_t i, size_t j) const {
            return i * cols + j;
        }

        void bf() const {}

    } vect_data;


public:

    Vector(int c) : vect_data(c) {}

    inline T &operator()(size_t i, size_t j) {
        return vect_data(i, j);
    }

    inline const T &operator()(size_t i, size_t j) const {
        return vect_data(i, j);
    }

    void operator = (T arr[]){
        //Vector(arr.length, arr);
        copy(begin(vect_data.data), end(vect_data.data), begin(arr));
    }
    Vector &operator+=(const Vector &b) {
        // here code
        return *this;
    }
};

Vector::Vector(int c) {
    vect_data = c;
}

inline Vector operator+( Vector x, const  Vector& y)
{
    return x+=y;
}
