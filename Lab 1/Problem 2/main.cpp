// main.cpp
#include <iostream>
#include <cmath>
#include "functions.hpp"

int main() {
    double x0 = 1.0; // Initial guess
    double epsilon = 1e-12; // Tolerance
    int max_iterations = 100; // Maximum number of iterations
    int iteration = 0;
    
    while (iteration < max_iterations) {
        double fx = f(x0);
        double fpx = f_prime(x0);
        
        if (fabs(fpx) < epsilon) {
            std::cout << "Prevent division by zero." << std::endl;
            break;
        }
        
        double x1 = x0 - fx / fpx;
        
        std::cout << "Iteration " << iteration + 1 <<: " << x1 << ", f(x) = " << f(x1) << std::endl;
        
        if (fabs(f(x1)) < epsilon) {
            std::cout << "Converged to a root: x = " << x1 << std::endl;
            break;
        }
        
        x0 = x1;
        iteration++;
    }
    
    if (iteration == max_iterations) {
        std::cout << "Maximum number of iterations reached. The method did not converge." << std::endl;
    }
    
    return 0;
}