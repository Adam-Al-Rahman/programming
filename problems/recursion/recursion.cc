/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**

i. Identify if you can break down problem into smaller problems.
ii. Write the recurrence relation if needed.
iii. Draw the recursive tree.
iv. About the tree:
  i. See the flow of functions, how they are getting in stack.
  ii. Identify & focus left tree calls and right tree calls.
v. Check return value at each steps.

*/

#include <iostream>

void message(int number) {
  if (number == 0)
    return;  // base condition: last function call condition to stop the call

  std::cout << number << "\n";
  message(number - 1);  // this is `tail recurrsion`

  if (number != 3)
    std::cout << number << " " << std::flush;
  else
    std::cout << number << std::flush;
}

int main() { message(3); }
