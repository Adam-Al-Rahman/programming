/**
 * Copyright 2024 Adam-Al-Rahman
 */

#include <iostream>

// Explicit Object Parameters: c++23
class Object {
 public:
  Object() = default;

  std::string welcome(this Object& self, std::string msg) { return msg; }

  void test(this Object& self, const std::string& msg) {
    std::string wel = self.welcome(msg);
    std::cout << wel << std::endl;
  }
};

int main() {
  Object obj;
  obj.test("Hello!!!");
}
