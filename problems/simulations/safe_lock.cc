
/*
An old safe has a dial lock with numbers 0 to 89. The dial may turn round and round in either direction. Being an
 * old
safe it will open within 3 numbers or closer in either direction to the KEY.

Your task is to determine if the
 * safe opens or remains shut and output the opening number.

Example:
KEY 30
COMBINATION 0>80<50>100<5>14<20

start:

 * 0, move clockwise by 80
        80, move counter clockwise by 50
        30, move clockwise by 100
        40, move
 * counter clockwise by 5
        35, move clockwise by 14
        49, move counter clockwise by 20
        29

|30 -
 * 29| <= 3 so the safe will OPEN

Output:

OPEN
29


Note: during the combination the safe stopped on the opening
 * number but will not open as it is a safe and needs the full
COMBINATION to open. Only the final result may open the
 * safe.

*/

#include <cmath>
#include <iostream>
#include <sstream>

int main() {
  int key = 30;
  std::string combination = "0>80<50>100<5>14<20";

  std::istringstream ss(combination);
  char direction;
  int number;

  // Read the first number
  ss >> number;

  int position = number;  // starting position

  // Parse the combination string
  while (ss >> direction >> number) {  // NOTE: How to parse integer along with string
    if (direction == '>') {
      position = (position + number) % 90;
    } else if (direction == '<') {
      position = (position - number + 90) % 90;
    }
  }

  // Check if the final position is within 3 numbers of the KEY
  int distance = std::abs(position - key);
  if (distance <= 3 || distance >= 87) {  // considering the wrap-around
    std::cout << "OPEN\n";
  } else {
    std::cout << "SHUT\n";
  }

  std::cout << position << std::endl;

  return 0;
}
