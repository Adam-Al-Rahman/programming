/*
 * @question: Single Cyclic Search
 * @brief: You're given an array of integers where each integer represents a
 jump of its value in the array. For instance, the integer 2 represents a jump
 of two indices forward in the array; the integer -3 represents a
 jump of three indices backward in the array.

 If a jump spills past the array's bounds, it wraps over to the other side. For
 instance, a jump of <span>-1</span> at index <span>0</span> brings us to the
 last index in the array. Similarly, a jump of <span>1</span> at the last index
 in the array brings us to index <span>0</span>.

 Write a function that returns a boolean representing whether the jumps in the
 array form a single cycle. A single cycle occurs if, starting at any index in
 the array and following the jumps, every element in the array is visited
 exactly once before landing back on the starting index.

 * @source:
 * @tags: ["graph", "cycle_check", "cpp"]
 * @status: unsolved
*/

#include <iostream>
#include <vector>

std::int16_t get_next_index(std::int16_t current_index,
                            const std::vector<std::int16_t> &list) {
  std::int16_t next_index = (current_index + list[current_index]) % list.size();

  // for positive number else negative numbers
  return next_index >= 0 ? next_index : next_index + list.size();
}

bool has_single_cycle(const std::vector<std::int16_t> &list) {
  std::int16_t num_element_visited = 0;
  std::int16_t current_index = 0;

  while (num_element_visited < list.size()) {
    // If return to start index before visiting each element
    if (num_element_visited > 0 && current_index == 0) return false;

    num_element_visited += 1;
    current_index = get_next_index(current_index, list);
  }

  std::cout << "\nvisited: " << num_element_visited << std::endl;
  std::cout << "\ncurrent index: " << current_index << std::endl;

  return current_index == 0;
}

int main() {
  std::cout << "Value: " << has_single_cycle({2, 3, 1, -4, -4, 2}) << std::endl;
}
