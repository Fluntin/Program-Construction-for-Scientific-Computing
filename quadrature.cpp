#include <iostream>
#include "quadrature.h"

int main() {
    int evalCounter = 0;

    auto exampleFunction = [](double x) {
        return x + cos(pow(x, 5));
    };

    double integralValue = simpsonAdaptive(exampleFunction, &evalCounter, 0, M_PI, 1e-8);

    std::cout << "Numerical Integral Value: " << integralValue << "\n";
    std::cout << "Number of Function Evaluations: " << evalCounter << "\n";

    return 0;
}