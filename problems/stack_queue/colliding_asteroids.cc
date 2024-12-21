// Colliding Asteroids

// You're given an array of integers asteroi ds , where each integer represents the size of an
// asteroid. The sign of the integer represents the direction the asteroid is moving (positive = right,
// negative = left). All asteroids move at the same speed, meaning that two asteroids moving in the
// same direction can never collide.

// For example, the integer 4 represents an asteroid of size 4 moving to the right. Similarly, -7
// represents an asteroid of size 7 moving to the left.

// If two asteroids collide, the smaller asteroid (based on absolute value) explodes. If two colliding
// asteroids are the same size, they both explode.

// Write a function that takes in this array of asteroids and returns an array of integers
// representing the asteroids after all collisions occur.

#include <cassert>
#include <cstdlib>
#include <vector>

// TC: O(n) | SC: O(n)
std::vector<int> collidingAsteroids(std::vector<int> asteroids) {
  std::vector<int> stack;

  for (int asteroid : asteroids) {
    if (stack.empty() || asteroid > 0 || stack.back() < 0) {
      stack.push_back(asteroid);
      continue;
    }

    while (!stack.empty()) {
      if (stack.back() < 0) {
        stack.push_back(asteroid);
        break;
      }

      int asteroidSize = std::abs(asteroid);
      if (stack.back() > asteroidSize) break;

      if (stack.back() == asteroidSize) {
        stack.pop_back();
        break;
      }

      stack.pop_back();

      if (stack.empty()) {
        stack.push_back(asteroid);
        break;
      }
    }
  }

  return stack;
}

int main() {
  std::vector<int> input = {-3, 5, -8, 6, 7, -4, -7};
  std::vector<int> expected = {-3, -8, 6};
  auto actual = collidingAsteroids(input);
  assert(expected == actual);
}
