// Copyright 2024 Adam-Al-Rahman

/**

i. Identify if you can break down problem into smaller problems.
ii. Write the recurrence relation if needed.
iii. Draw the recursive tree.
iv. About the tree:
  i. See the flow of functions, how they are getting in stack.
  ii. Identify & focus left tree calls and right tree calls.
v. Check return value at each steps.

*/

/**

Tail-recursive functions can be optimized by the compiler into a loop,
which prevents additional stack frames from being created.
This optimization is known as `tail call optimization (TCO)`.

*/

#include <iostream>

// Tail Recursion Functions
int tail_factorial(int n, int acc = 1) {
  if (n == 0) return acc;                 // Base case
  return tail_factorial(n - 1, n * acc);  // Recursive call is the last operation
}

// No Tail Recursion
int no_tail_factorial(int n) {
  if (n == 0) return 1;                 // Base case
  return n * no_tail_factorial(n - 1);  // Recursive call is followed by multiplication
}

// NO Tail Recursion
void message(int number) {
  if (number == 0) return;  // base condition: last function call condition to stop the call

  std::cout << number << "\n";
  message(number - 1);

  if (number != 3)
    std::cout << number << " " << std::flush;
  else
    std::cout << number << std::flush;
}

int main() { message(3); }
