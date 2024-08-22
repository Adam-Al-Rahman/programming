// Copyright 2024 Adam-Al-Rahman
// Automatic Differentiation: Reverse Mode

#include <iostream>
#include <memory>

class Expression {
 public:
  virtual ~Expression() = default;
  virtual void evaluate() = 0;
  virtual void derive(float seed) = 0;
  float value = 0.0f;
};

class Variable : public Expression {
 public:
  float partial = 0.0f;

  explicit Variable(float value) { this->value = value; }

  void evaluate() override {}

  void derive(float seed) override { partial += seed; }
};

// Operator Overloading for Addition
class Plus : public Expression {
  std::shared_ptr<Expression> a, b;

 public:
  Plus(std::shared_ptr<Expression> a, std::shared_ptr<Expression> b) : a(std::move(a)), b(std::move(b)) {}

  void evaluate() override {
    a->evaluate();
    b->evaluate();
    value = a->value + b->value;
  }

  void derive(float seed) override {
    a->derive(seed);
    b->derive(seed);
  }
};

// Operator Overloading for Multiplication
class Multiply : public Expression {
  std::shared_ptr<Expression> a, b;

 public:
  Multiply(std::shared_ptr<Expression> a, std::shared_ptr<Expression> b) : a(std::move(a)), b(std::move(b)) {}

  void evaluate() override {
    a->evaluate();
    b->evaluate();
    value = a->value * b->value;
  }

  void derive(float seed) override {
    a->derive(b->value * seed);
    b->derive(a->value * seed);
  }
};

// Overloaded operators for more natural expressions
std::shared_ptr<Expression> operator+(std::shared_ptr<Expression> a, std::shared_ptr<Expression> b) {
  return std::make_shared<Plus>(std::move(a), std::move(b));
}

std::shared_ptr<Expression> operator*(std::shared_ptr<Expression> a, std::shared_ptr<Expression> b) {
  return std::make_shared<Multiply>(std::move(a), std::move(b));
}

int main() {
  // Example: Finding the partials of z = ((x * (x + y)) + (y * y)) at (x, y) = (2, 3)
  auto x = std::make_shared<Variable>(2.0f);
  auto y = std::make_shared<Variable>(3.0f);

  auto z = x * (x + y) + y * y;

  z->evaluate();
  std::cout << "z = " << z->value << std::endl;
  // Output: z = 19

  z->derive(1.0f);
  std::cout << "∂z/∂x = " << x->partial << ", "
            << "∂z/∂y = " << y->partial << std::endl;
  // Output: ∂z/∂x = 7, ∂z/∂y = 8
}
