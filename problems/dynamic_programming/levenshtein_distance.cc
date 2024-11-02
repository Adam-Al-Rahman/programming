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

// TC: O(nm) | SC: O(min(n, m)) | Space optimization
// Instead of maintaining a table for all subproblems,
// we only need to keep track of the current and previous rows.
// This is because the state cache[i][j] only depends on cache[i-1][j], cache[i][j-1], and cache[i-1][j-1]
int levenshtein_distance_optim(std::string str1, std::string str2) {
  std::string small = str1.length() < str2.length() ? str1 : str2;
  std::string big = str1.length() >= str2.length() ? str1 : str2;

  std::vector<int> even_edits(small.length() + 1);
  std::vector<int> odd_edits(small.length() + 1);
  for (int j = 0; j < small.length() + 1; ++j) even_edits[j] = j;

  std::vector<int>* current_edits;
  std::vector<int>* previous_edits;

  for (int i = 1; i < big.length() + 1; i++) {
    if (i % 2 == 1) {
      current_edits = &odd_edits;
      previous_edits = &even_edits;
    } else {
      current_edits = &even_edits;
      previous_edits = &odd_edits;
    }

    current_edits->at(0) = i;
    for (int j = 1; j < small.length() + 1; ++j) {
      if (big[i - 1] == small[j - 1]) {
        current_edits->at(j) = previous_edits->at(j - 1);
      } else {
        current_edits->at(j) =
            1 + std::min({previous_edits->at(j - 1), previous_edits->at(j), current_edits->at(j - 1)});
      }
    }
  }

  return big.length() % 2 == 0 ? even_edits[small.length()] : odd_edits[small.length()];
}

int main() { assert(levenshteinDistance("abc", "yabd") == 2); }
