#include <iostream>
#include <vector>

std::vector<std::vector<std::uint64_t>> permutation(
    const std::vector<std::uint64_t>& list,
    std::vector<std::uint64_t> result = {}) {
  std::vector<std::vector<std::uint64_t>> permutes;

  if (list.empty()) {
    permutes.push_back(result);
    return permutes;
  }

  for (std::size_t i = 0; i < list.size(); ++i) {
    std::vector<std::uint64_t> newList = list;
    std::vector<std::uint64_t> newResult = result;

    newResult.push_back(newList[i]);
    newList.erase(newList.begin() + i);

    std::vector<std::vector<std::uint64_t>> subPerms =
        permutation(newList, newResult);
    permutes.insert(permutes.end(), subPerms.begin(), subPerms.end());
  }

  return permutes;
}

int main() {
  std::vector<std::uint64_t> input = {1, 2, 3};
  std::vector<std::vector<std::uint64_t>> result = permutation(input);

  for (const auto& perm : result) {
    for (std::uint64_t num : perm) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
