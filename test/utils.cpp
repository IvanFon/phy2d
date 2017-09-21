#include <cmath>
#include <iostream>

// Maximum difference between numbers to be considered close enough
const double ERROR = 1e-5;

// Compare floats & doubles correctly
template<typename A, typename B>
bool compare(A a, B b) {
    return a == b || std::abs(a - b) < ERROR;
}
