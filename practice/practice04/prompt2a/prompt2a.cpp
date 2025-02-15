#include <iostream>
#include <sstream>
#include <type_traits>
#include <iomanip>

// Templated function to perform calculation
template <typename T>
T calculate(T a, T b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return (b != 0) ? a / b : throw std::runtime_error("Error: Division by zero");
    default: throw std::invalid_argument("Error: Invalid operator");
    }
}

// Function to determine if a string represents a double
bool isDouble(const std::string& str) {
    return str.find('.') != std::string::npos;
}

// Function to safely convert a string to a number template
template <typename T>
bool convertStringToNumber(const std::string& str, T& out) {
    std::istringstream iss(str);
    iss >> out;
    return !iss.fail() && iss.eof();
}

int main() {
    std::cout << "Enter first number: ";
    std::string input1, input2;
    std::cin >> input1;

    std::cout << "Enter second number: ";
    std::cin >> input2;

    std::cout << "Enter operation (+, -, *, /): ";
    char op;
    std::cin >> op;

    try {
        if (isDouble(input1) || isDouble(input2)) {
            double num1, num2;
            if (!convertStringToNumber(input1, num1) || !convertStringToNumber(input2, num2)) {
                throw std::invalid_argument("Error: Invalid number format");
            }
            double result = calculate(num1, num2, op);
            std::cout << "Result: " << std::fixed << std::setprecision(2) << result << std::endl;
        }
        else {
            int num1, num2;
            if (!convertStringToNumber(input1, num1) || !convertStringToNumber(input2, num2)) {
                throw std::invalid_argument("Error: Invalid number format");
            }
            int result = calculate(num1, num2, op);
            std::cout << "Result: " << result << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

