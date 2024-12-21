// Sunset Views

// Given an array of buildings and a direction that all of the buildings face,
// return an array of the indices of the buildings that can see the sunset.

// A building can see the sunset if it's strictly taller than all of the buildings that come after it in the
// direction that it faces.

// The input array named buildi ngs contains positive, non-zero integers representing the
// heights of the buildings. A building at index i thus has a height denoted by buildi ngs [i]
// All of the buildings face the same direction, and this direction is either east or west, denoted by
// the input string named di rection , which will always be equal to either " EAST" or "WEST"
// In relation to the input array, you can interpret these directions as right for east and left for west.

// Important note: the indices in the ouput array should be sorted in ascending order.

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

// TC: O(n) | SC: O(n)
std::vector<int> sunsetViews(std::vector<int> buildings, std::string direction) {
  std::vector<int> candidateBuildings;

  // direction = WEST
  int startIdx = buildings.size() - 1;
  int step = -1;

  if (direction == "EAST") {
    startIdx = 0;
    step = 1;
  }

  int idx = startIdx;
  while (idx >= 0 && idx < buildings.size()) {
    int buildingHeight = buildings[idx];

    while (candidateBuildings.size() > 0 &&
           buildings[candidateBuildings[candidateBuildings.size() - 1]] <= buildingHeight) {
      candidateBuildings.pop_back();
    }

    candidateBuildings.push_back(idx);

    idx += step;
  }

  if (direction == "WEST") std::reverse(candidateBuildings.begin(), candidateBuildings.end());

  return candidateBuildings;
}

int main() {
  std::vector<int> buildings = {3, 5, 4, 4, 3, 1, 3, 2};
  std::string direction = "EAST";
  std::vector<int> expected = {1, 3, 6, 7};
  std::vector<int> actual = sunsetViews(buildings, direction);
  assert(expected == actual);
}
