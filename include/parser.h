#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

// Splits the input string into tokens (numbers, operators, functions)
std::vector<std::string> tokenizeInput(const std::string &input);

// Validates the user's input for correct syntax
bool validateInput(const std::string &input);

// Converts an infix expression to postfix notation for easier evaluation
std::vector<std::string> infixToPostfix(const std::vector<std::string> &tokens);

#endif // PARSER_H
