#include "calculator.h"
#include <cmath>
#include <stdexcept>
#include <unordered_map>
#include <sstream>

double calculate(double operand1, double operand2, char operation) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) throw std::invalid_argument("Division by zero.");
            return operand1 / operand2;
        default: throw std::invalid_argument("Unsupported operation.");
    }
}

long long factorial(int number) {
    if (number < 0) throw std::invalid_argument("Factorial is undefined for negative numbers.");
    long long result = 1;
    for (int i = 1; i <= number; ++i) {
        result *= i;
    }
    return result;
}

double evaluateTrigonometricFunction(const std::string &function, double value) {
    if (function == "sin") return std::sin(value);
    if (function == "cos") return std::cos(value);
    if (function == "tan") return std::tan(value);
    throw std::invalid_argument("Unsupported trigonometric function: " + function);
}

double evaluateExpression(const std::string &expression) {
    // Placeholder: Implement evaluation logic if using postfix
    return 0.0;
}
