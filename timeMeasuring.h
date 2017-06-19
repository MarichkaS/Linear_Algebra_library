//
// Created by dzvinka on 19.06.17.
//

#ifndef LINEAR_ALGEBRA_LIBRARY_TIMEMEASURING_H
#define LINEAR_ALGEBRA_LIBRARY_TIMEMEASURING_H
#include <chrono>
#include <atomic>

using namespace std;

inline chrono::high_resolution_clock::time_point getCurrentTimeFenced()
{
    atomic_thread_fence(memory_order::memory_order_seq_cst);
    auto res_time = chrono::high_resolution_clock::now();
    atomic_thread_fence(memory_order::memory_order_seq_cst);
    return res_time;
}
template<class D>
inline  long long toMilliSec(const D& d)
{
    return chrono::duration_cast<std::chrono::milliseconds>(d).count();
}
template<class D>
inline  long long toMicroSec(const D& d)
{
    return chrono::duration_cast<std::chrono::microseconds>(d).count();
}
#endif //LINEAR_ALGEBRA_LIBRARY_TIMEMEASURING_H
