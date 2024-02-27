
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;

/*
- rhs is an expression that is evaluated to a value.
- The value of the rhs is stored to the lhs.
- The value of the rhs must be type compatible with the lhs.
- The lhs must be assignable.
- Assignment expression is evaluated to what was just assigned.
- More than one variable can be assigned in a single statement.

- int number {10}; // this is not assign it is initialization.
- assignment is when you change the initialized value.

----------------------------
result = counter++, means
1. counter = counter + 1;
2. result = counter;
----------------------------

----------------------------
result = ++counter, means
1. result = counter;
2. counter = counter + 1;
----------------------------
*/

const void assignment_operator() {}

int main() {
  int single_quote_integer = 3'000;
  float single_quote_float = 3'000.2365;
  const string file = "./hello-world.csv";

  cout << "Single quote int: " << single_quote_integer << endl;
  cout << "Single quote float: " << single_quote_float << endl;
  cout << "Precision with fixed: " << setprecision(2) << fixed
       << single_quote_float << endl;
  cout << "Precision without fixed: " << setprecision(2) << single_quote_float
       << endl;
  cout << "File location: " << file;
}
