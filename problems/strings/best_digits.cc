// Best Digits

// Write a function that takes a positive integer represented as a string number and an integer
// numDigits . Remove numDigits from the string so that the number represented by the
// string is as large as possible afterwards.

// Note that the order of the remaining digits cannot be changed. You can assume numDigits
// will always be less than the length of number and greater than or equal to 0.

#include <cassert>
#include <string>

std::string bestDigits(std::string number, int numDigits) {
  std::string num;

  int idx = 0;
  while (idx < number.size()) {
    while (numDigits > 0 && num.size() > 0 && num.back() <= number[idx]) {
      num.pop_back();
      numDigits -= 1;
    }

    num.push_back(number[idx]);
    idx += 1;
  }

  while (numDigits > 0) {
    num.pop_back();
    numDigits -= 1;
  }

  num += number.substr(idx);
  return num;
}

int main() {
  std::string number = "462839";
  int numDigits = 2;
  std::string expected = "6839";
  auto actual = bestDigits(number, numDigits);
  assert(expected == actual);
}
