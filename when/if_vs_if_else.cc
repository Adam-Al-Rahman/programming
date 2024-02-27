/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**
Using a series of standalone `if` statements without `else` branches can be a
valid approach depending on the logic and requirements of your code. However,
the choice between `if` and `if-else` often depends on the specific behavior you
want to achieve.

Here's a brief comparison:

1. **Multiple Independent Conditions (if):**
   - If each condition is independent, and you want to check all of them
regardless of the outcome of previous conditions, using multiple `if` statements
might be appropriate.
   - This is suitable when you want to perform multiple checks, and all
conditions might need to be evaluated.

```cpp
if (condition1) {
    // Code for condition1
}

if (condition2) {
    // Code for condition2
}

// Additional if statements for other conditions...
```

2. **Mutually Exclusive Conditions (if-else):**
   - If conditions are mutually exclusive, meaning that once one condition is
true, others should not be checked, using `if-else` statements can be more
efficient and readable.
   - This is suitable when only one of the conditions should be executed.

```cpp
if (condition1) {
    // Code for condition1
} else if (condition2) {
    // Code for condition2
} else {
    // Default code if none of the conditions are met
}
```

3. **Independent Execution (if):**
   - If each condition should execute independently, without regard to the
outcome of others, multiple `if` statements can make the code more
straightforward.

```cpp
if (condition1) {
    // Code for condition1
}

if (condition2) {
    // Code for condition2
}
```

4. **All Conditions Checked (if):**
   - If you want to check all conditions even if one or more are true, multiple
`if` statements might be appropriate.

```cpp
if (condition1) {
    // Code for condition1
}

if (condition2) {
    // Code for condition2
}

// Additional if statements for other conditions...
```

In summary, whether to use standalone `if` statements or `if-else` statements
depends on the specific requirements and logic of your code. Both approaches are
valid and have their use cases. Choose the one that makes your code more
readable and meets your design goals.
*/

#include <iostream>

int main() {
  bool mutual_exclusive = true;

  if (mutual_exclusive) {
    std::cout << "IF-ELSE"
              << "\n";
  } else {
    std::cout << "IF" << std::flush;
  }
}
