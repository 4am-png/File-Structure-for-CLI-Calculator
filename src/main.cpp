#include <iostream>
#include <string>
#include "calculator.h"
#include "parser.h"

using namespace std;

int main() {
    cout << "Welcome to the CLI Calculator!\n";
    cout << "Enter a mathematical expression or type 'exit' to quit:\n";

    string input;
    while (true) {
        cout << ">> ";
        getline(cin, input);

        if (input == "exit") {
            cout << "Goodbye!\n";
            break;
        }

        try {
            if (!validateInput(input)) {
                throw invalid_argument("Invalid input syntax.");
            }

            vector<string> tokens = tokenizeInput(input);
            vector<string> postfix = infixToPostfix(tokens);
            double result = evaluateExpression(input);

            cout << "Result: " << result << "\n";
        } catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
