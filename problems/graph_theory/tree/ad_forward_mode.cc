// Copyright 2024 Adam-Al-Rahman
// Automatic Differentiation: Forward Mode

#include <iostream>
#include <memory>

class Variable;

class Expression {
 public:
  virtual ~Expression() = default;
  virtual float evaluate() const = 0;
  virtual float derive(const Variable* variable) const = 0;
};

class Variable : public Expression {
  float value;

 public:
  explicit Variable(float val) : value(val) {}

  float evaluate() const override { return value; }

  float derive(const Variable* variable) const override { return (this == variable) ? 1.0f : 0.0f; }
};

class Plus : public Expression {
  std::shared_ptr<Expression> a, b;

 public:
  Plus(std::shared_ptr<Expression> a, std::shared_ptr<Expression> b) : a(std::move(a)), b(std::move(b)) {}

  float evaluate() const override { return a->evaluate() + b->evaluate(); }

  float derive(const Variable* variable) const override { return a->derive(variable) + b->derive(variable); }
};

class Multiply : public Expression {
  std::shared_ptr<Expression> a, b;

 public:
  Multiply(std::shared_ptr<Expression> a, std::shared_ptr<Expression> b) : a(std::move(a)), b(std::move(b)) {}

  float evaluate() const override { return a->evaluate() * b->evaluate(); }

  float derive(const Variable* variable) const override {
    return b->evaluate() * a->derive(variable) + a->evaluate() * b->derive(variable);
  }
};

class ExpressionResult {
  std::shared_ptr<Expression> expression;

 public:
  ExpressionResult(std::shared_ptr<Expression> expr) : expression(std::move(expr)) {}

  float evaluate() const { return expression->evaluate(); }

  float derive(const Variable* variable) const { return expression->derive(variable); }
};

int main() {
  // Example: Finding the partials of z = x * (x + y) + y * y at (x, y) = (2, 3)
  auto x = std::make_shared<Variable>(2.0f);
  auto y = std::make_shared<Variable>(3.0f);

  auto p1 = std::make_shared<Plus>(x, y);
  auto m1 = std::make_shared<Multiply>(x, p1);
  auto m2 = std::make_shared<Multiply>(y, y);
  auto z = std::make_shared<Plus>(m1, m2);

  ExpressionResult result(z);
  float xPartial = result.derive(x.get());
  float yPartial = result.derive(y.get());

  std::cout << "∂z/∂x = " << xPartial << ", "
            << "∂z/∂y = " << yPartial << std::endl;

  return 0;
}
