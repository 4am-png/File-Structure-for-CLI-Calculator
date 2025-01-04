#include "parser.h"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <stack>

std::vector<std::string> tokenizeInput(const std::string &input) {
    std::vector<std::string> tokens;
    std::istringstream stream(input);
    std::string token;

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

bool validateInput(const std::string &input) {
    int openBrackets = 0, closeBrackets = 0;

    for (char ch : input) {
        if (!std::isdigit(ch) && !std::isspace(ch) && ch != '+' && ch != '-' &&
            ch != '*' && ch != '/' && ch != '(' && ch != ')') {
            return false;
        }

        if (ch == '(') ++openBrackets;
        if (ch == ')') ++closeBrackets;
    }

    return openBrackets == closeBrackets;
}

std::vector<std::string> infixToPostfix(const std::vector<std::string> &tokens) {
    std::vector<std::string> postfix;
    std::stack<std::string> operators;

    auto precedence = [](const std::string &op) {
        if (op == "+" || op == "-") return 1;
        if (op == "*" || op == "/") return 2;
        return 0;
    };

    for (const auto &token : tokens) {
        if (std::isdigit(token[0])) {
            postfix.push_back(token);
        } else if (token == "(") {
            operators.push(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != "(") {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
        } else {
            while (!operators.empty() && precedence(token) <= precedence(operators.top())) {
                postfix.push_back(operators.top());
                operators.pop();
            }
            operators.push(token);
        }
    }

    while (!operators.empty()) {
        postfix.push_back(operators.top());
        operators.pop();
    }

    return postfix;
}
