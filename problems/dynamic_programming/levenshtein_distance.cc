// Levenshtein Distance

// Write a function that takes in two strings and returns the minimum number of edit operations
// that need to be performed on the first string to obtain the second string.
//
// There are three edit operations: insertion of a character, deletion of a character, and substitution
// of a character for another.

#include <algorithm>
#include <cassert>
#include <climits>
#include <string>
#include <vector>

// TC: O(nm) | SC: O(nm)
int levenshteinDistance(std::string str1, std::string str2) {
  std::vector<std::vector<int>> cache(str1.size() + 1, std::vector<int>(str2.size() + 1, INT_MAX));
  cache[0][0] = 0;

  for (int i = 1; i <= std::max(str1.size(), str2.size()); ++i) {
    if (i <= str1.size()) cache[i][0] = i;
    if (i <= str2.size()) cache[0][i] = i;
  }

  for (int i = 1; i <= str1.size(); ++i) {
    for (int j = 1; j <= str2.size(); ++j) {
      if (str1[i - 1] == str2[j - 1])
        cache[i][j] = cache[i - 1][j - 1];
      else
        cache[i][j] = 1 + std::min({cache[i - 1][j], cache[i][j - 1], cache[i - 1][j - 1]});
    }
  }

  return cache[str1.size()][str2.size()];
}

// TC: O(nm) | SC: O(min(n, m))
int levenshtein_distance_optim(std::string str1, std::string str2) {
  // PENDING: SPACE OPTIMIZED ALGORITHM
  // COMPLETE: IT AFTER DINNER (18 OCT, 24)
}

int main() { assert(levenshteinDistance("abc", "yabd") == 2); }
