#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

// Performs a mathematical operation on two operands
double calculate(double operand1, double operand2, char operation);

// Evaluates a single mathematical expression
double evaluateExpression(const std::string &expression);

// Calculates the factorial of a number
long long factorial(int number);

// Evaluates trigonometric functions (e.g., sin, cos)
double evaluateTrigonometricFunction(const std::string &function, double value);

#endif // CALCULATOR_H
