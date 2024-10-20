// Sweet And Savory

// You're hosting an event at a food festival and want to showcase the best possible pairing of two
// dishes from the festival that complement each other's flavor profile.

// Each dish has a flavor profile represented by an integer. A negative integer means a dish is
// sweet, while a positive integer means a dish is savory. The absolute value of that integer
// represents the intensity of that flavor. For example, a flavor profile of -3 is slightly sweet, one of
// -10 is extremely sweet, one of 2 is mildly savory, and one of 8 is significantly savory.

// You're given an array of these dishes and a target combined flavor profile. Write a function that
// returns the best possible pairing of two dishes (the pairing with a total flavor profile that's closest
// to the target one). Note that this pairing must include one sweet and one savory dish. You're also
// concerned about the dish being too savory, so your pairing should never be more savory than
// the target flavor profile.

// All dishes will have a positive or negative flavor profile; there are no dishes with a 0 value. For
// simplicity, you can assume that there will be at most one best solution. If there isn't a valid
// solution, your function should return [O, O] . The returned array should be sorted, meaning
// the sweet dish should always come first.

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

std::vector<int> sweetAndSavory(std::vector<int> dishes, int target) {
  std::sort(dishes.begin(), dishes.end());

  // Edge case: If all dishes are savory (positive) or sweet (negative)
  if (dishes.empty() || dishes[0] >= 0 || dishes.back() <= 0) return {0, 0};

  std::vector<int> sweet;
  std::vector<int> savory;
  for (int dish : dishes) {
    if (dish < 0)
      sweet.push_back(dish);
    else
      savory.push_back(dish);
  }

  int i = 0, j = savory.size() - 1;
  int closest_sum = std::numeric_limits<int>::min();
  std::vector<int> result(2, 0);

  while (i < sweet.size() && j < savory.size()) {
    int sum = sweet[i] + savory[j];

    if (sum <= target && sum > closest_sum) {
      closest_sum = sum;
      result = {sweet[i], savory[j]};
    }

    // Move pointers: If sum exceeds target, move the savory pointer to get a smaller savory dish
    if (sum > target)
      j -= 1;
    else
      i += 1;
  }

  return result;
}

int main() {
  std::vector<int> dishes = {-3, -5, 1, 7};
  int target = 8;
  std::vector<int> expected = {-3, 7};
  auto actual = sweetAndSavory(dishes, target);
  assert(expected == actual);
}
