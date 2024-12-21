// Four Number Sum

// Write a function that takes in a non-empty array of distinct integers and an integer representing
// a target sum. The function should find all quadruplets in the array that sum up to the target sum
// and return a two-dimensional array of all these quadruplets in no particular order.

// If no four numbers sum up to the target sum, the function should return an empty array.

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>

std::string sortAndStringify(std::vector<int> array) {
  std::sort(array.begin(), array.end());

  std::string s;
  for (int elem : array) {
    s += std::to_string(elem);
    s += ",";
  }

  return s;
}

bool isIncluded(std::vector<std::string> array, std::string str1) {
  for (std::string str2 : array) {
    if (str1 == str2) return true;
  }

  return false;
}

// Avg:: TC: O(n^2) | SC: O(n^2)
// Worst:: TC: O(n^3) | SC: O(n^2)
std::vector<std::vector<int>> fourNumberSum(std::vector<int> array, int targetSum) {
  std::unordered_map<int, std::vector<std::vector<int>>> allPairSums;
  std::vector<std::vector<int>> quadruplets{};

  for (int i = 1; i < array.size() - 1; i++) {
    for (int j = i + 1; j < array.size(); j++) {
      int currentSum = array[i] + array[j];
      int diff = targetSum - currentSum;

      if (allPairSums.find(diff) != allPairSums.end()) {
        for (std::vector<int> pair : allPairSums[diff]) {
          pair.push_back(array[i]);
          pair.push_back(array[j]);
          quadruplets.push_back(pair);
        }
      }
    }

    for (int k = 0; k < i; k++) {
      int currentSum = array[i] + array[k];
      allPairSums[currentSum].push_back(std::vector<int>{array[k], array[i]});
    }
  }

  return quadruplets;
}

int main() {
  std::vector<std::vector<int>> output = fourNumberSum({7, 6, 4, -1, 1, 2}, 16);
  std::vector<std::string> output2{};
  for (std::vector<int> arr : output) output2.push_back(sortAndStringify(arr));

  std::vector<std::vector<int>> quadruplets{
      {7, 6, 4, -1},
      {7, 6, 1, 2},
  };

  assert(output2.size() == 2);
  for (std::vector<int> quadruplet : quadruplets) {
    std::string str1 = sortAndStringify(quadruplet);
    bool included = isIncluded(output2, str1);
    assert(included == true);
  }
}
