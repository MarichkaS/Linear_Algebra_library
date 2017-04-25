//
// Created by maria on 24.04.17.
//

#ifndef LINEAR_ALGEBRA_LIBRARY_VECTOR_H
#define LINEAR_ALGEBRA_LIBRARY_VECTOR_H

template <class T>

class Vector {
private:
    struct VectorMemory;
    void bf() const{};
public:
    Vector(int c);
    void operator =(T arr[]);
};

//inline Vector operator+(Vector x, const  Vector& y);

#endif //LINEAR_ALGEBRA_LIBRARY_VECTOR_H
