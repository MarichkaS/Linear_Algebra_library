#ifndef LINEAR_ALGEBRA_LIBRARY_VECTOR_H
#define LINEAR_ALGEBRA_LIBRARY_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <cmath>
#include <thread>
#include <mutex>
#include <vector>
#include <math.h>

using namespace std;

#define NUMB_OF_THREADS 10
mutex myMutex;

template<class T>
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

        VectorMemory(const VectorMemory &other) :
                cols(other.cols) {
            data = new T[other.cols];
            std::copy(other.data, other.data + cols, data);
        }

        static void swap(VectorMemory &a, VectorMemory &b) {
            std::swap(a.data, b.data);
            std::swap(a.cols, b.cols);
        }


        VectorMemory &operator=(const VectorMemory &b) {
            VectorMemory temp(b);
            VectorMemory::swap(temp, *this);
            return *this;
        }

    } vec_data;

public:
    Vector(size_t c) : vec_data(c) {}


    Vector(std::initializer_list<T> ilst) : vec_data(std::sqrt(ilst.size())) {
        assert(std::sqrt(ilst.size()) == ilst.size());
        for (auto i = begin(ilst); i != end(ilst); i++) {
            vec_data.data[i - begin(ilst)] = *i;
        }

    }

    Vector &operator=(std::initializer_list<T> ilst) {
        if (ilst.size() != vec_data.cols) {
            throw std::out_of_range("Too big lst to initialize vector with");
        }

        for (auto i = begin(ilst); i != end(ilst); i++) {
            vec_data.data[i - begin(ilst)] = *i;
        }
        return *this;
    }

    size_t cols() const {
        return vec_data.cols;
    }

    T *const vecToArr() {
        return vec_data.data;
    }

    inline T &operator()(size_t i) {
        if (i >= vec_data.cols || i < 0) {
            throw std::out_of_range("Vector index out of range");
        }
        return vec_data(i);
    }

    inline const T &operator()(size_t i) const {
        if (i >= vec_data.cols || i < 0) {
            throw std::out_of_range("Vector index out of range");
        }
        return vec_data(i);

    }

    friend std::ostream &operator<<(std::ostream &out, const Vector &val) {
        std::string c = "";
        for (int i = 0; i < val.vec_data.cols; i++) {
            c += std::to_string(val(i));
            c += " ";
        }
        out << c;
        return out;
    }

    bool operator==(const Vector &other) const {
        if (cols() != other.cols())
            return false;
        for (int i = 0; i < vec_data.cols; i++) {
            if ((*this)(i) != other(i))
                return false;
        }
        return true;
    }

    bool operator!=(const Vector &other) const {
        return !((*this) == other);
    }

    void vctr_addition(const Vector &other, int index, int size) {
        int c = index % cols();

        Vector &self = *this;
        for (int i = 0; i < size; i++) {
            self(c) = self(c) + other(c);
            c++;
            if (c == cols()) { c = 0; }
        }
    }

    Vector &operator+=(const Vector &other) {
        /**
         * Parallel vectors' addition
         */

        assert(cols() == other.cols());
        int size_for_one_thr = ceil(cols() / NUMB_OF_THREADS);
        int j = 0;
        vector<thread> th;

        for (size_t n = 0; n < NUMB_OF_THREADS - 1; ++n) {
            th.push_back(thread(&Vector::vctr_addition, this, other, j, size_for_one_thr));
            j += size_for_one_thr;
        }

        th.push_back(thread(&Vector::vctr_addition, this, other, j, size_for_one_thr + (cols()) % NUMB_OF_THREADS));

        for (auto &t : th) t.join();
        return *this;
    }

    void vect_substr(const Vector &other, int index, int size) {
        int c = index % cols();

        Vector &self = *this;
        for (int i = 0; i < size; i++) {
            self(c) = self(c) - other(c);
            c++;
            if (c == cols()) { c = 0; }
        }

    }


    Vector &operator-=(const Vector &other) {
        /**
         * Parallel vectors' substraction
         */
        assert(cols() == other.cols());
        int size_for_one_thr = ceil(cols() / NUMB_OF_THREADS);
        int j = 0;
        vector<thread> th;

        for (size_t n = 0; n < NUMB_OF_THREADS - 1; ++n) {
            th.push_back(thread(&Vector::vect_substr, this, other, j, size_for_one_thr));
            j += size_for_one_thr;
        }

        th.push_back(thread(&Vector::vect_substr, this, other, j, size_for_one_thr + (cols()) % NUMB_OF_THREADS));

        for (auto &t : th) t.join();
        return *this;
    }

    void vect_plus_scalar(int scalar, int index, int size) {
        int c = index % cols();
        Vector &self = *this;
        for (int i = 0; i < size; i++) {
            self(c) = self(c) + scalar;
            c++;
            if (c == cols()) { c = 0; }
        }
    }

    Vector &operator+=(const T &scalar) {
        /** Vector + Scalar
         */
        int size_for_one_thr = ceil(cols() / NUMB_OF_THREADS);
        int j = 0;
        vector<thread> th;

        for (size_t n = 0; n < NUMB_OF_THREADS - 1; ++n) {
            th.push_back(thread(&Vector::vect_plus_scalar, this, scalar, j, size_for_one_thr));
            j += size_for_one_thr;
        }

        th.push_back(thread(&Vector::vect_plus_scalar, this, scalar, j, size_for_one_thr + (cols()) % NUMB_OF_THREADS));

        for (auto &t : th) t.join();
        return *this;
    }

    void vect_minus_scalar(int scalar, int index, int size) {
        int c = index % cols();
        Vector &self = *this;
        for (int i = 0; i < size; i++) {
            self(c) = self(c) - scalar;
            c++;
            if (c == cols()) { c = 0; }
        }
    }

    Vector &operator-=(const T &scalar) {
        /** Vector - Scalar
         */
        int size_for_one_thr = ceil(cols() / NUMB_OF_THREADS);
        int j = 0;
        vector<thread> th;

        for (size_t n = 0; n < NUMB_OF_THREADS - 1; ++n) {
            th.push_back(thread(&Vector::vect_minus_scalar, this, scalar, j, size_for_one_thr));
            j += size_for_one_thr;
        }

        th.push_back(
                thread(&Vector::vect_minus_scalar, this, scalar, j, size_for_one_thr + (cols()) % NUMB_OF_THREADS));

        for (auto &t : th) t.join();
        return *this;
    }


    static void worker(int a, int b, Vector self, Vector other, float_t &res) { // ,
        for (int i = a; i < b; i++) {
            lock_guard<mutex> lock(myMutex);

            res += (float_t) self(i) * other(i);
            cout << "res :" << res << endl;
        }
    }

    float_t multthread(const Vector &other, const Vector &self, int n) {
        float_t res = 0;
        vector<thread> tp;
        for (int k = 0; k < NUMB_OF_THREADS - 1; k++) {
            cout << n / NUMB_OF_THREADS*k << " " << n / NUMB_OF_THREADS*(k+1) << endl;
            tp.push_back(
                    thread(worker, n / NUMB_OF_THREADS * k, n / NUMB_OF_THREADS * (k + 1), other, self, ref(res))); // ,
        }
        cout << n / NUMB_OF_THREADS * NUMB_OF_THREADS<< " " << endl;
        tp.push_back(thread(worker, n / NUMB_OF_THREADS * NUMB_OF_THREADS, n, other, self, ref(res))); // ,
        for (int i = 0; i < tp.size(); ++i) {
            tp[i].join();
        }
        return res;

    }

    float_t operator*(const Vector &other) {

        /**
        *  Parallel multiplication of two vectors
        */
        assert(cols() == other.cols());
        const Vector<T> &self = *this;
        return multthread(ref(other), ref(self), cols());
    }

    static void worker_2(int a, int b, double scalar, Vector self, Vector &res) { // ,float_t &res
        for (int i = a; i < b; i++) {
            cout << "self(i) :"<< self(i) << endl;
            lock_guard<mutex> lock(myMutex);
            res = self(i) *scalar;
        }
    }

    Vector &multhread_2(const double &scalar, const Vector &self, int n) {
        Vector res(cols());

        vector<thread> tp;
        for (int k = 0; k < NUMB_OF_THREADS - 1; k++) {
//            cout << n / NUMB_OF_THREADS*k << " " << n / NUMB_OF_THREADS*(k+1) << endl;
            tp.push_back(thread(worker_2, n / NUMB_OF_THREADS * k, n / NUMB_OF_THREADS * (k + 1), scalar, self,
                                ref(res))); //
        }
//        cout << n / NUMB_OF_THREADS * NUMB_OF_THREADS<< " " << endl;
        tp.push_back(thread(worker_2, n / NUMB_OF_THREADS * NUMB_OF_THREADS, n, scalar, self, ref(res))); //
        for (int i = 0; i < tp.size(); ++i) {
            tp[i].join();
        }

        return res;
    }


    Vector &operator*=(const T &scalar) {
        const Vector &self = *this;
        return multhread_2(ref(scalar), ref(self), cols());
//        vector<thread> tp;
//        for (int k = 0; k < NUMB_OF_THREADS-1; k++) {
////            cout << n / NUMB_OF_THREADS*k << " " << n / NUMB_OF_THREADS*(k+1) << endl;
//            tp.push_back(thread(worker_2, cols() / NUMB_OF_THREADS*k, cols()/ NUMB_OF_THREADS*(k+1), scalar, self )); // ,ref(res)
//        }
////        cout << n / NUMB_OF_THREADS * NUMB_OF_THREADS<< " " << endl;
//        tp.push_back(thread(worker_2, cols() / NUMB_OF_THREADS * NUMB_OF_THREADS, cols(), scalar, self)); //  ref(res)
//        for (int i =0 ; i  < tp.size(); ++i){
//            tp[i].join();
//        }
//        return self;

    }

    Vector &operator-() {
        Vector &vect = *this;

        for (size_t i = 0; i < cols(); i++) {
            vect(i) = -vect(i);
        }
        return vect;
    }

    Vector &operator+() {
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
inline Vector<T> operator+(Vector<T> left, const T &scalar) {
    return left += scalar;
}

template<typename T>
inline Vector<T> operator-(Vector<T> left, const Vector<T> &other) {
    assert(left.cols() == other.cols());
    return left -= other;
}

template<typename T>
inline Vector<T> operator-(Vector<T> vec, const T &scalar) {
    return vec -= scalar;
}

template<typename T>
inline Vector<T> operator-(const T &scalar, Vector<T> right) {
    return -right += scalar;
}

template<typename T>
inline Vector<T> operator*(Vector<T> left, const T &scalar) {
    return left *= scalar;
}

template<typename T>
inline Vector<T> operator*(const T &scalar, Vector<T> right) {
    return right *= scalar;
}


#endif //LINEAR_ALGEBRA_LIBRARY_VECTOR_H