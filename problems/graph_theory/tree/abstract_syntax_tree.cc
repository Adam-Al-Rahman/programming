// Copyright 2024 Adam-Al-Rahman
// Abstract Syntax Tree

#include <cctype>
#include <iostream>
#include <memory>
#include <stack>
#include <string>

// Base class for AST nodes
class ASTNode {
 public:
  ASTNode() = default;
  virtual ~ASTNode() = default;
  virtual int evaluate() const = 0;
};

// Class for operand nodes
class NumberNode : public ASTNode {
 public:
  explicit NumberNode(int value) : value(value) {}

  int evaluate() const override { return value; }

 private:
  int value;
};

// Class for operator nodes
class OperatorNode : public ASTNode {
 public:
  OperatorNode(std::unique_ptr<ASTNode> left, char op, std::unique_ptr<ASTNode> right)
      : left(std::move(left)), op(op), right(std::move(right)) {}

  int evaluate() const override {
    int leftVal = left->evaluate();
    int rightVal = right->evaluate();
    switch (op) {
      case '+':
        return leftVal + rightVal;
      case '-':
        return leftVal - rightVal;
      case '*':
        return leftVal * rightVal;
      case '/':
        return leftVal / rightVal;
      default:
        return 0;
    }
  }

 private:
  std::unique_ptr<ASTNode> left;
  std::unique_ptr<ASTNode> right;
  char op;
};

// Function to parse the expression and create the AST
std::unique_ptr<ASTNode> parseExpression(const std::string& expression) {
  std::stack<std::unique_ptr<ASTNode>> numbers;
  std::stack<char> operators;

  auto applyOp = [](std::unique_ptr<ASTNode> left, std::unique_ptr<ASTNode> right,
                    char op) -> std::unique_ptr<ASTNode> {
    return std::make_unique<OperatorNode>(std::move(left), op, std::move(right));
  };

  for (int i = 0; i < expression.length(); ++i) {
    if (std::isspace(expression[i])) continue;

    if (std::isdigit(expression[i])) {
      int num = 0;
      while (i < expression.length() && std::isdigit(expression[i])) {
        num = num * 10 + (expression[i] - '0');
        ++i;
      }
      numbers.push(std::make_unique<NumberNode>(num));
      --i;  // Adjust index after number parsing
    } else if (expression[i] == '(') {
      operators.push(expression[i]);
    } else if (expression[i] == ')') {
      while (!operators.empty() && operators.top() != '(') {
        char op = operators.top();
        operators.pop();
        auto right = std::move(numbers.top());
        numbers.pop();
        auto left = std::move(numbers.top());
        numbers.pop();
        numbers.push(applyOp(std::move(left), std::move(right), op));
      }
      operators.pop();  // Pop the '('
    } else if (expression[i] == '+' || expression[i] == '-') {
      while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
        char op = operators.top();
        operators.pop();
        auto right = std::move(numbers.top());
        numbers.pop();
        auto left = std::move(numbers.top());
        numbers.pop();
        numbers.push(applyOp(std::move(left), std::move(right), op));
      }
      while (!operators.empty() && (operators.top() == '+' || operators.top() == '-')) {
        char op = operators.top();
        operators.pop();
        auto right = std::move(numbers.top());
        numbers.pop();
        auto left = std::move(numbers.top());
        numbers.pop();
        numbers.push(applyOp(std::move(left), std::move(right), op));
      }
      operators.push(expression[i]);
    } else if (expression[i] == '*' || expression[i] == '/') {
      while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
        char op = operators.top();
        operators.pop();
        auto right = std::move(numbers.top());
        numbers.pop();
        auto left = std::move(numbers.top());
        numbers.pop();
        numbers.push(applyOp(std::move(left), std::move(right), op));
      }
      operators.push(expression[i]);
    }
  }

  while (!operators.empty()) {
    char op = operators.top();
    operators.pop();
    auto right = std::move(numbers.top());
    numbers.pop();
    auto left = std::move(numbers.top());
    numbers.pop();
    numbers.push(applyOp(std::move(left), std::move(right), op));
  }

  return std::move(numbers.top());
}

int main() {
  std::string expression = "(39 + 5) * 2";
  std::unique_ptr<ASTNode> ast = parseExpression(expression);
  std::cout << "Result: " << ast->evaluate() << std::endl;
  return 0;
}
