#include <iostream>

const void overflow_x() {
  int a = 100000;
  int b = 100000;
  // int c = a * b; // compile time: overflow warning;
  // long int c = a * b; // compile time: overflow warning; because first the
  // a*b is calculated which return a integer of 10^10 which is greater than
  // 10^9 and then it store in the variable;
  long int c =
      a * 1LL * b; // 1LL = 1 long long; ever though a and b are integers a *
                   // 1LL * b this return long long because of 1LL;
  int d = 1e+9;    // 1000000000
}
