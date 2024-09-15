#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

// Same as om tje previous file
template <typename Func>
inline double computeSimpson(Func f, int* evalCounter, double a, double b) {
    *evalCounter += 4;
    return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

// We have a template function that computes the adaptive Simpson's rule for a given function f
template <typename Func>
double simpsonAdaptive(Func f, int* evalCounter, double a, double b, double tol, int depth = 0, int maxDepth = 1000) {
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

    // Copy paste from the previous file
    auto identityFunction = [](double x) {
        return x;
    };

    // Now we have to test the function
    // We calculate the integral of the function x over the interval [0, 1]
    // Use the adaptive Simpson's rule with a tolerance of 1e-9
    try {
        double integralValue = simpsonAdaptive(identityFunction, &evalCounter, 0, 1, 1e-9);
        cout << "Integral of x over [0, 1]: " << integralValue << "\n";
        cout << "Function evaluations: " << evalCounter << "\n";
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
