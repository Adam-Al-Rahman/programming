#include <iostream>

int count();

int main() {
  std::cout << "[Coroutines]" << std::endl;
  std::cout << count();
}

int count() {
  int x = 0;
  return x;
  x = 1;
  return x;
}