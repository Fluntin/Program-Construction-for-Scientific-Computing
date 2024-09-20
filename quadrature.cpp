#include <iostream>
#include <cmath>
#include <stdexcept>
#include "quadrature.h"  // Include the corresponding header

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

template <typename Func>
inline double computeSimpson(Func f, int* evalCounter, double a, double b) {
    *evalCounter += 4;
    return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

template <typename Func>
double simpsonAdaptive(Func f, int* evalCounter, double a, double b, double tol, int depth, int maxDepth) {
    if (tol <= 0) {
        throw underflow_error("Tolerance too small: " + to_string(tol));
    }

    if (depth >= maxDepth) {
        throw runtime_error("Maximum recursion depth reached.");
    }

    double mid = (a + b) / 2;
    double I1 = computeSimpson(f, evalCounter, a, b);
    double I2 = computeSimpson(f, evalCounter, a, mid) + computeSimpson(f, evalCounter, mid, b);

    double error = abs(I1 - I2);

    if (error < 15 * tol) {
        return I2;
    } else {
        return simpsonAdaptive(f, evalCounter, a, mid, tol / 2, depth + 1, maxDepth) +
               simpsonAdaptive(f, evalCounter, mid, b, tol / 2, depth + 1, maxDepth);
    }
}

int main() {
    int evalCounter = 0;

    auto exampleFunction = [](double x) {
        return x + cos(pow(x, 5));
    };

    double integralValue = simpsonAdaptive(exampleFunction, &evalCounter, 0, M_PI, 1e-8);

    cout << "Numerical Integral Value: " << integralValue << "\n";
    cout << "Number of Function Evaluations: " << evalCounter << "\n";

    return 0;
}
