#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <cctype>
#include <stdexcept>

class ExpressionEvaluator {
private:
    // Check if character is an operator
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
    
    // Get operator precedence
    int getPrecedence(char op) {
        switch(op) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            default:
                return 0;
        }
    }
    
    // Check if operator is left associative
    bool isLeftAssociative(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }
    
    // Convert infix expression to postfix using Shunting Yard algorithm
    std::queue<std::string> infixToPostfix(const std::string& expression) {
        std::queue<std::string> output;
        std::stack<char> operators;
        
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            
            // Skip whitespace
            if (std::isspace(c)) {
                continue;
            }
            
            // If character is a digit or decimal point, read the complete number
            if (std::isdigit(c) || c == '.') {
                std::string number = "";
                while (i < expression.length() && (std::isdigit(expression[i]) || expression[i] == '.')) {
                    number += expression[i];
                    i++;
                }
                i--; // Adjust for the extra increment in the for loop
                output.push(number);
            }
            // If character is an operator
            else if (isOperator(c)) {
                while (!operators.empty() && 
                       operators.top() != '(' &&
                       ((isLeftAssociative(c) && getPrecedence(c) <= getPrecedence(operators.top())) ||
                        (!isLeftAssociative(c) && getPrecedence(c) < getPrecedence(operators.top())))) {
                    output.push(std::string(1, operators.top()));
                    operators.pop();
                }
                operators.push(c);
            }
            // If character is opening parenthesis
            else if (c == '(') {
                operators.push(c);
            }
            // If character is closing parenthesis
            else if (c == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    output.push(std::string(1, operators.top()));
                    operators.pop();
                }
                if (operators.empty()) {
                    throw std::runtime_error("Mismatched parentheses");
                }
                operators.pop(); // Remove the opening parenthesis
            }
            else {
                throw std::runtime_error("Invalid character in expression: " + std::string(1, c));
            }
        }
        
        // Pop remaining operators
        while (!operators.empty()) {
            if (operators.top() == '(' || operators.top() == ')') {
                throw std::runtime_error("Mismatched parentheses");
            }
            output.push(std::string(1, operators.top()));
            operators.pop();
        }
        
        return output;
    }
    
    // Evaluate postfix expression
    double evaluatePostfix(std::queue<std::string> postfix) {
        std::stack<double> operands;
        
        while (!postfix.empty()) {
            std::string token = postfix.front();
            postfix.pop();
            
            // If token is a number
            if (std::isdigit(token[0]) || (token[0] == '.' && token.length() > 1)) {
                operands.push(std::stod(token));
            }
            // If token is an operator
            else if (token.length() == 1 && isOperator(token[0])) {
                if (operands.size() < 2) {
                    throw std::runtime_error("Invalid expression: insufficient operands");
                }
                
                double operand2 = operands.top(); operands.pop();
                double operand1 = operands.top(); operands.pop();
                double result;
                
                switch (token[0]) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 == 0) {
                            throw std::runtime_error("Division by zero");
                        }
                        result = operand1 / operand2;
                        break;
                    default:
                        throw std::runtime_error("Unknown operator: " + token);
                }
                
                operands.push(result);
            }
            else {
                throw std::runtime_error("Invalid token: " + token);
            }
        }
        
        if (operands.size() != 1) {
            throw std::runtime_error("Invalid expression: too many operands");
        }
        
        return operands.top();
    }
    
public:
    double evaluate(const std::string& expression) {
        if (expression.empty()) {
            throw std::runtime_error("Empty expression");
        }
        
        try {
            std::queue<std::string> postfix = infixToPostfix(expression);
            return evaluatePostfix(postfix);
        }
        catch (const std::exception& e) {
            throw std::runtime_error("Error evaluating expression: " + std::string(e.what()));
        }
    }
};

int main() {
    ExpressionEvaluator evaluator;
    
    // Test cases
    std::vector<std::string> testExpressions = {
        "3 + (8 - 7.5) * 10 / 5 - (2 + 5 * 7)",
        "10 + 2 * 6",
        "100 * 2 + 12",
        "(1 + 2) * (3 + 4)",
        "2 + 3 * 4 - 1",
        "10 / 2 + 3 * 4",
        "((2 + 3) * 4) / 2",
        "5.5 + 2.3 * 1.2",
        "3 + 4 *" // Invalid expression
    };
    
    std::cout << "Mathematical Expression Evaluator\n";
    std::cout << "=================================\n\n";
    
    for (const std::string& expr : testExpressions) {
        try {
            double result = evaluator.evaluate(expr);
            std::cout << "Expression: " << expr << std::endl;
            std::cout << "Result: " << result << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Expression: " << expr << std::endl;
            std::cout << "Error: " << e.what() << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}