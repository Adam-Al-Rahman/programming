// Copyright 2024 Adam-Al-Rahman

#include <functional>
#include <iostream>

void fib_n(int user_n) {
  std::int64_t a = 0;
  std::int64_t b = 1;

  // Define a recursive lambda function using std::function
  std::function<void(int)> print_fibonacci = [&](int n) {
    if (n <= 0) return;         // Base case
    std::cout << b << " ";      // Print the current Fibonacci number
    std::int64_t next = a + b;  // Calculate the next Fibonacci number
    a = b;                      // Update a
    b = next;                   // Update b
    print_fibonacci(n - 1);     // Recursive call
  };  // <-- semi-colon necessary

  print_fibonacci(user_n);
}

int main() {
  int n;
  std::cout << "Enter the value of n: ";
  std::cin >> n;
  fib_n(n);  // Print Fibonacci sequence from 1 to n
  std::cout << std::endl;
}
