import math

def calculate(operand1, operand2, operation):
    if operation == '+':
        return operand1 + operand2
    elif operation == '-':
        return operand1 - operand2
    elif operation == '*':
        return operand1 * operand2
    elif operation == '/':
        if operand2 == 0:
            raise ValueError("Division by zero")
        return operand1 / operand2
    else:
        raise ValueError("Unsupported operation")

def factorial(n):
    if n < 0:
        raise ValueError("Factorial is undefined for negative numbers.")
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def evaluate_trig_function(function, value):
    if function == "sin":
        return math.sin(value)
    elif function == "cos":
        return math.cos(value)
    elif function == "tan":
        return math.tan(value)
    else:
        raise ValueError(f"Unsupported trigonometric function: {function}")
    
def evaluate_expression(expression):
    # Placeholder for more complex evaluation logic (like handling parentheses, etc.)
    return 0.0  # Can be implemented later
