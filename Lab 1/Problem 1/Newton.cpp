#include <iostream>
#include <cmath>


double f(double x) {
    // Define the function f(x) that we want to find the root of
    // In the example we where suggested to take f(x) = sin(x + 3)
    return sin(x + 3);
}

double f_prime(double x) {
    // Define the derivative f'(x)
    // Im hardcoding the derivative of f(x) = sin(x + 3) here
    return cos(x + 3);
}

int main() {
    double x0 = 1.0; // Initial guess
    double epsilon = 1e-12; // Tolerance
    int max_iter = 1e-3; // Maximum number of iterations
    int iter = 0;
    
    while (iteration < max_iter) {
        double fx = f(x0);
        double fpx = f_prime(x0);
        
        if (fabs(fpx) < epsilon) {
            std::cout << "Stopping iteration to prevent division by zero." << std::endl;
            break;
        }
        
        double x1 = x0 - fx / fpx;
        
        // Here we print the current iteration and the value of x and f(x)
        // This is not necessary, but it is useful to see the progress of the method
        std::cout << "Iteration " << iter + 1 << ": x = " << x1 << ", f(x) = " << f(x1) << std::endl;
        
        //Here we check if the value of f(x) is less than epsilon
        //If it is, we have found a root and we break the loop
        if (fabs(f(x1)) < epsilon) {
            std::cout << "Converged to a root: x = " << x1 << std::endl;
            break;
        }
        
        x0 = x1;
        iter++;
    }
    
    if (iter == max_iter) {
        std::cout << "Maximum number of iterations reached. The method did not converge." << std::endl;
    }
    
    return 0;
}
