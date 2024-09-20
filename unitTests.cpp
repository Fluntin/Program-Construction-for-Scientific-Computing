#include <iostream>
#include <stdexcept>
#include <cmath>
#include "utest.h"
#include "quadrature.h"

using namespace std;

// Unit Test for checking if the integral of f(x) = x from 0 to 1 equals 1/2
UTEST(simpson, check_integral_value) {
    int evalCounter = 0;
    auto identityFunction = [](double x) {
        return x;
    };

    // Using a very small tolerance for high accuracy
    double integralValue = simpsonAdaptive(identityFunction, &evalCounter, 0, 1, 1e-9);
    double expectedValue = 0.5;

    // Assert that the computed value matches the expected value (1/2)
    ASSERT_NEAR(integralValue, expectedValue, 1e-9);
}

// This runs the unit test
UTEST_MAIN();
