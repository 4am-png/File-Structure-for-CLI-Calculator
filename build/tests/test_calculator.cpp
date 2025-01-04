#include <gtest/gtest.h>
#include "calculator.h"

// Test for basic arithmetic operations
TEST(CalculatorTests, BasicArithmetic) {
    EXPECT_DOUBLE_EQ(calculate(5, 3, '+'), 8);
    EXPECT_DOUBLE_EQ(calculate(5, 3, '-'), 2);
    EXPECT_DOUBLE_EQ(calculate(5, 3, '*'), 15);
    EXPECT_DOUBLE_EQ(calculate(6, 3, '/'), 2);
}

// Test for division by zero
TEST(CalculatorTests, DivisionByZero) {
    EXPECT_THROW(calculate(5, 0, '/'), std::invalid_argument);
}

// Test for factorial function
TEST(CalculatorTests, Factorial) {
    EXPECT_EQ(factorial(5), 120);
    EXPECT_EQ(factorial(0), 1);
    EXPECT_THROW(factorial(-1), std::invalid_argument);
}

// Test for trigonometric functions
TEST(CalculatorTests, TrigonometricFunctions) {
    EXPECT_NEAR(evaluateTrigonometricFunction("sin", 3.14159265358979323846 / 2), 1.0, 0.0001);
    EXPECT_NEAR(evaluateTrigonometricFunction("cos", 3.14159265358979323846), -1.0, 0.0001);
    EXPECT_THROW(evaluateTrigonometricFunction("tan", 3.14159265358979323846 / 2), std::invalid_argument);
}
