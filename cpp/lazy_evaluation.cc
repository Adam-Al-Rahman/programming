// Copyright 2024 Adam-Al-Rahman

#include <functional>
#include <iostream>

// Expensive calculation function that takes parameters
int expensiveCalculation(int a, int b) {
  std::cout << "Expensive calculation done with " << a << " and " << b << "!" << std::endl;
  return a * b;
}

void processResult(const std::function<int()>& lazyResult, bool condition) {
  if (condition) {
    // Now the expensive calculation is performed
    int result = lazyResult();
    std::cout << "Result: " << result << std::endl;
  } else {
    std::cout << "Condition not met, skipping calculation." << std::endl;
  }
}

int main() {
  int x = 5, y = 10;

  // Use a lambda to capture the parameters and defer execution
  auto lazyResult = [x, y] { return expensiveCalculation(x, y); };

  // Pass the lazy evaluation to another function
  processResult(lazyResult, false);  // Condition is false, calculation skipped
  processResult(lazyResult, true);   // Condition is true, calculation performed
}
