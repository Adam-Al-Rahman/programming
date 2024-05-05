#include <iostream>

int main() {
  int x = 1000000000;
  while (x--) {
    std::cout << "Hello";
    int *a = new int(10);
    delete a;
  }
}
