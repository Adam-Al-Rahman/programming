/**
 * @copyright
 * Copyright 2024 Shahan-Ali
 */

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    std::vector<std::vector<int>> ans;

    for (int j = 0; j < nums.size(); j++) {
      for (int i = 0; i < ((2 * nums.size()) + 1); i++) {
        std::vector<int> temp;
        temp = nums;

        if (i != j + 1 && i != j && i != j) {
          temp.insert(temp.begin() + i, nums[j]);
          temp.erase(temp.begin() + j);

          ans.push_back(temp);
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution ss;
  ss.permute({1, 2, 3});
}
