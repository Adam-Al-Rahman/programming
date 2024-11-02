// Single Cyclic Search

// You're given an array of integers where each integer represents a jump of its value in the array.
// For instance, the integer 2 represents a jump of two indices forward in the array; the integer
// -3 represents a jump of three indices backward in the array.

// If a jump spills past the array's bounds, it wraps over to the other side. For instance, a jump of
// -1 at index 0 brings us to the last index in the array. Similarly, a jump of 1 at the last index
// in the array brings us to index 0

// Write a function that returns a boolean representing whether the jumps in the array form a
// single cycle. A single cycle occurs if, starting at any index in the array and following the jumps,
// every element in the array is visited exactly once before landing back on the starting index.

#include <iostream>
#include <vector>

// The problem arises in (current_idx + list[current_idx]) % list.size() if list.size() is not cast to int32_t.
// list.size() returns an std::size_t, which is an unsigned integer (typically 64 bits on many systems). When you
// perform the modulo operation with an unsigned integer, C++ promotes the int32_t result of (current_idx +
// list[current_idx]) to std::size_t before performing the modulo operation.
std::int16_t get_next_idx(std::int16_t current_idx, const std::vector<std::int32_t> &list) {
  std::int16_t next_idx = (current_idx + list[current_idx]) % static_cast<std::int32_t>(list.size());

  // for positive number else negative numbers
  return next_idx >= 0 ? next_idx : next_idx + list.size();
}

bool hasSingleCycle(const std::vector<std::int32_t> &list) {
  std::int16_t num_element_visited = 0;
  std::int16_t current_idx = 0;

  while (num_element_visited < list.size()) {
    // If return to start index before visiting each element
    if (num_element_visited > 0 && current_idx == 0) return false;

    num_element_visited += 1;
    current_idx = get_next_idx(current_idx, list);
  }

  return current_idx == 0;
}

int main() { std::cout << "Value: " << hasSingleCycle({2, 3, 1, -4, -4, 2}) << std::endl; }
