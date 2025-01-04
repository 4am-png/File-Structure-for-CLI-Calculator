#include <gtest/gtest.h>
#include "parser.h"

// Test for tokenizing input
TEST(ParserTests, TokenizeInput) {
    std::string input = "3 + 5 * (2 - 8)";
    std::vector<std::string> expected_tokens = {"3", "+", "5", "*", "(", "2", "-", "8", ")"};
    
    std::vector<std::string> tokens = tokenizeInput(input);
    EXPECT_EQ(tokens, expected_tokens);
}

// Test for validating correct input syntax
TEST(ParserTests, ValidateInput) {
    EXPECT_TRUE(validateInput("3 + 5 * (2 - 8)"));
    EXPECT_FALSE(validateInput("3 + 5 * (2 - 8"));
    EXPECT_FALSE(validateInput("3 ++ 5"));
}

// Test for converting infix to postfix
TEST(ParserTests, InfixToPostfix) {
    std::vector<std::string> tokens = {"3", "+", "5", "*", "(", "2", "-", "8", ")"};
    std::vector<std::string> expected_postfix = {"3", "5", "2", "8", "-", "*", "+"};
    
    std::vector<std::string> postfix = infixToPostfix(tokens);
    EXPECT_EQ(postfix, expected_postfix);
}
