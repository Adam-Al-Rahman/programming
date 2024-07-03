#include <iostream>
#include <sstream>
#include <string>

int main() {
  int key = 30;
  std::string combination = "0>80<50>100<5>14<20";

  std::istringstream ss(combination);
  char direction;
  int number;

  // Read the starting number first
  ss >> number;

  int position = number;  // Initialize position with the starting number

  // Parse the combination string
  while (ss >> direction >> number) {
    if (direction == '>') {
      position = (position + number) % 90;
    } else if (direction == '<') {
      position = (position - number + 90) % 90;
    }
  }

  std::cout << "Final position: " << position << std::endl;
}
