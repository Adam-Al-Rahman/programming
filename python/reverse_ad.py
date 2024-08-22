from abc import ABC, abstractmethod


class Node(ABC):  # ABC: Abstract Base Class
    def __init__(self):
        self.gradient = 0
        self._value = None  # Cache for the evaluated value

    @abstractmethod
    def _evaluate(self) -> float:
        """Actual evaluation logic to be implemented by subclasses."""
        pass

    @abstractmethod
    def derivative(self, wrt_variable: "Variable") -> float:
        """Compute the derivative with respect to the given variable."""
        pass

    @abstractmethod
    def backprop(self, prev_gradient: float):
        """Perform backpropagation with the given gradient."""
        pass

    def evaluate(self) -> float:
        """Evaluate the node and return its value."""
        if self._value is None:
            self._value = self._evaluate()
        return self._value

    def reset_cache(self):
        """Reset cached values, useful for re-evaluating the graph."""
        self._value = None


class Constant(Node):
    def __init__(self, value: float):
        super().__init__()
        self.value = value

    def _evaluate(self) -> float:
        return self.value

    def derivative(self, wrt_variable: "Variable") -> float:
        return 0

    def backprop(self, prev_gradient: float):
        pass


class Variable(Node):
    count = 0

    def __init__(self, value: float):
        super().__init__()
        Variable.count += 1
        self.name = "var" + str(Variable.count)
        self.value = value

    def _evaluate(self) -> float:
        return self.value

    def derivative(self, wrt_variable: "Variable") -> float:
        return 1 if wrt_variable == self else 0

    def backprop(self, prev_gradient: float):
        self.gradient += prev_gradient


class BinaryOperator(Node):
    def __init__(self, a: Node, b: Node):
        super().__init__()
        self.a = a
        self.b = b

    @abstractmethod
    def _evaluate(self) -> float:
        """Actual evaluation logic to be implemented by subclasses."""
        pass

    @abstractmethod
    def derivative(self, wrt_variable: "Variable") -> float:
        """Compute the derivative with respect to the given variable."""
        pass

    @abstractmethod
    def backprop(self, prev_gradient: float):
        """Perform backpropagation with the given gradient."""
        pass


class Add(BinaryOperator):
    def _evaluate(self) -> float:
        return self.a.evaluate() + self.b.evaluate()

    def derivative(self, wrt_variable: "Variable") -> float:
        return self.a.derivative(wrt_variable) + self.b.derivative(wrt_variable)

    def backprop(self, prev_gradient: float):
        self.a.backprop(prev_gradient)
        self.b.backprop(prev_gradient)


class Multiply(BinaryOperator):
    def _evaluate(self) -> float:
        return self.a.evaluate() * self.b.evaluate()

    def derivative(self, wrt_variable: "Variable") -> float:
        return (self.a.derivative(wrt_variable) * self.b.evaluate()) + (
            self.a.evaluate() * self.b.derivative(wrt_variable)  # noqa: E126
        )

    def backprop(self, prev_gradient: float):
        self.a.backprop(self.b.evaluate() * prev_gradient)
        self.b.backprop(self.a.evaluate() * prev_gradient)


# Example usage
x = Variable(3.0)
y = Variable(5.0)

graph = Add(Add(Multiply(x, x), Multiply(x, y)), Constant(2))
graph.backprop(1.0)

# Reset cache if needed for re-evaluation
x.reset_cache()
y.reset_cache()
graph.reset_cache()

print("""
Equation: z = x*x + x*y + 2
z(x) = v(u(x))
forward diff --> z'(x) = u'(x)*v'(u(x))
backward diff --> z'(x) = v'(u(x))*u'(x)
""")

print(f"For x = 3, y = 5 we get z = {graph.evaluate()}")
print(f"Forward: ∂z/∂x = {graph.derivative(x)}, ∂z/∂y = {graph.derivative(y)}")
print(f"Backward: ∂z/∂x = {x.gradient}, ∂z/∂y = {y.gradient}")
