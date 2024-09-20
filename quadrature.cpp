#include <iostream>
#include "quadrature.h"  // Include the header with the template functions

int main() {
    int evalCounter = 0;

    // Example function to integrate: f(x) = x + cos(x^5)
    auto exampleFunction = [](double x) {
        return x + cos(pow(x, 5));
    };

    // Use Simpson's adaptive quadrature to calculate the integral
    double integralValue = simpsonAdaptive(exampleFunction, &evalCounter, 0, M_PI, 1e-8);

    std::cout << "Numerical Integral Value: " << integralValue << "\n";
    std::cout << "Number of Function Evaluations: " << evalCounter << "\n";

    return 0;
}
