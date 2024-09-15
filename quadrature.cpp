

#include <iostream>
#include <functional>
#include <cmath>
#include <stdexcept>

// Define M_PI if not defined, this was added by copilot...
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// As we talked namespace std will allow me to use cout and endl without std:: prefix
using namespace std;

// This is a template function that computes the Simpson's rule for a given function f
// Same as in the pdf
template <typename Func>
inline double computeSimpson(Func f, int* evalCounter, double a, double b) {
    
    //Pointer Lecture :)
    *evalCounter += 4;
    return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

// This is a template function that computes the adaptive Simpson's rule for a given function f
// Template functions => operate with generic types.
template <typename Func>

// Here we take a function f, a pointer to an integer evalCounter, two doubles a and b, a double tol, and two integers depth and maxDepth
double simpsonAdaptive(Func f, int* evalCounter, double a, double b, double tol, int depth = 0, int maxDepth = 1000) {

    // If the tolerance is less than or equal to zero, we throw an underflow_error exception
    if (tol <= 0) {
        throw underflow_error("Tolerance too small: " + to_string(tol));
    }

    // If the depth is greater than or equal to the maximum depth, we throw a runtime_error exception
    if (depth >= maxDepth) {
        throw runtime_error("Maximum recursion depth reached.");
    }

    // We calculate the midpoint of the interval
    double mid = (a + b) / 2;

    // We calcualte two integrals using the Simpson's rule
    // I1 is the integral of the function f over the interval [a, b]
    // I2 is the integral of the function f over the interval [a, mid] plus the integral of the function f over the interval [mid, b]
    double I1 = computeSimpson(f, evalCounter, a, b);
    double I2 = computeSimpson(f, evalCounter, a, mid) + computeSimpson(f, evalCounter, mid, b);

    // We calculate the error between the two integrals
    double error = abs(I1 - I2);

    // If the error is less than 15 times the tolerance, we return I2
    if (error < 15 * tol) {
        return I2;

    // Otherwise, we recursively call the simpsonAdaptive function for the intervals [a, mid] and [mid, b]
    } else {
        return simpsonAdaptive(f, evalCounter, a, mid, tol / 2, depth + 1, maxDepth) +
               simpsonAdaptive(f, evalCounter, mid, b, tol / 2, depth + 1, maxDepth);
    }
}

// Have to declare the main function
int main() {
    int evalCounter = 0;

    // Define a lambda function that takes a double x and returns x + cos(x^5)
    // LABDA FUNCTION: A lambda function is a small anonymous function that can have any number of parameters, but can only have one expression.
    auto exampleFunction = [](double x) {
        return x + cos(pow(x, 5));
    };

    // Calculate the integral of the example function over the interval [0, pi] using the adaptive Simpson's rule
    double integralValue = simpsonAdaptive(exampleFunction, &evalCounter, 0, M_PI, 1e-8);

    // Output the integral value and the number of function evaluations
    cout << "Numerical Integral Value: " << integralValue << "\n";
    cout << "Number of Function Evaluations: " << evalCounter << "\n";

    return 0;
}

