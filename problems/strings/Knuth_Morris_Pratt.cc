// Copyright 2024 Adam-Al-Rahman
// How to search in Linear Time? (Recommended)
// Knuth-Morris-Pratt O(n + m)

/**
When to Use Which?

_KMP_
Best for: Single pattern searches with predictable performance.
Use case: When you need consistent O(n + m) performance and are not searching for multiple patterns.

_Rabin-Karp_
Best for: Multiple pattern searches or when a good hash function is available to minimize collisions.
Use case: When dealing with multiple patterns or when hash-based approaches are beneficial, despite potential for
variable performance due to hash collisions.
*/

#include <iostream>
#include <string>
#include <vector>

// Function to compute the `longest` proper `prefix` which is also a proper `suffix`
std::vector<int> compute_lps(const std::string& pattern) {
  int length = 0;  // Length of the previous longest prefix suffix
  std::vector<int> lps(pattern.size(), 0);

  for (int i = 1; i < pattern.size(); ++i) {
    while (length > 0 && pattern[i] != pattern[length]) length = lps[length - 1];

    if (pattern[i] == pattern[length]) ++length;

    lps[i] = length;
  }

  return lps;
}

// KMP algorithm for pattern searching, returns the index where the pattern is found or -1 if not found
int kmp(const std::string& text, const std::string& pattern) {
  std::vector<int> lps = compute_lps(pattern);

  int i = 0;  // Index for text[]
  int j = 0;  // Index for pattern[]

  while (i < text.size()) {
    if (pattern[j] == text[i]) {
      ++i;
      ++j;
    }

    if (j == pattern.size()) {
      return i - j;  // Pattern found at index i - j
    } else if (i < text.size() && pattern[j] != text[i]) {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        ++i;
      }
    }
  }

  return -1;  // Pattern not found
}

int main() {
  std::string text = "abracadra";
  std::string pattern = "cad";

  int index = kmp(text, pattern);

  if (index != -1) {
    std::cout << "Pattern found at index " << index << std::endl;
  } else {
    std::cout << "Pattern not found" << std::endl;
  }
}
