package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func calculate(operand1 float64, operand2 float64, operation string) (float64, error) {
	switch operation {
	case "+":
		return operand1 + operand2, nil
	case "-":
		return operand1 - operand2, nil
	case "*":
		return operand1 * operand2, nil
	case "/":
		if operand2 == 0 {
			return 0, fmt.Errorf("division by zero")
		}
		return operand1 / operand2, nil
	default:
		return 0, fmt.Errorf("unsupported operation")
	}
}

func factorial(n int) (int, error) {
	if n < 0 {
		return 0, fmt.Errorf("factorial is undefined for negative numbers")
	}
	result := 1
	for i := 1; i <= n; i++ {
		result *= i
	}
	return result, nil
}

func evaluateTrigFunction(function string, value float64) (float64, error) {
	switch function {
	case "sin":
		return math.Sin(value), nil
	case "cos":
		return math.Cos(value), nil
	case "tan":
		return math.Tan(value), nil
	default:
		return 0, fmt.Errorf("unsupported trigonometric function: %s", function)
	}
}

func main() {
	// Example usage
	fmt.Println("Welcome to the Go CLI Calculator!")

	operand1, operand2 := 5.0, 3.0
	operation := "+"

	result, err := calculate(operand1, operand2, operation)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Printf("Result: %.2f\n", result)
	}

	// Example factorial calculation
	factorialResult, err := factorial(5)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Printf("Factorial(5) = %d\n", factorialResult)
	}

	// Example trigonometric function calculation
	trigResult, err := evaluateTrigFunction("sin", math.Pi/2)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Printf("sin(π/2) = %.2f\n", trigResult)
	}
}
