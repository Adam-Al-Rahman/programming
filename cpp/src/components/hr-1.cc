#include <chrono>
#include <iostream>
#include <string>

const int first_last(std::string integer_in) {
  return ((integer_in[0] - '0') + (integer_in[integer_in.length() - 1]) - '0');
}

int main() {
  std::string integer_str;
  std::cout << "Enter a integer: ";
  std::cin >> integer_str;

  auto start = std::chrono::high_resolution_clock::now();
  int first_last_sum = first_last(integer_str);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "Duration: " << duration.count() << "\u03BCs\n"
            << "Sum[(" << integer_str[0] << ")";
  for (int i = 1; i < integer_str.length() - 1; i++)
    std::cout << integer_str[i];
  std::cout << "(" << integer_str[integer_str.length() - 1]
            << ")]: " << first_last_sum << std::endl;
}
