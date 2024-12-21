// Longest Palindromic Substring

// Write a function that, given a string, returns its longest palindromic substring.

// A palindrome is defined as a string that's written the same forward and backward. Note that
// single-character strings are palindromes.

// You can assume that there will only be one longest palindromic substring.

#include <cassert>
#include <string>
#include <vector>

std::vector<int> getLongestPalindromeFrom(std::string str, int leftIdx, int rightIdx) {
  while (leftIdx >= 0 && rightIdx < str.size()) {
    if (str[leftIdx] != str[rightIdx]) break;
    leftIdx -= 1;
    rightIdx += 1;
  }

  return std::vector<int>{leftIdx + 1, rightIdx};
}

std::string longestPalindromicSubstring(std::string str) {
  std::vector<int> currentLongest{0, 1};  // {start index, length}

  for (int i = 1; i < str.size(); i++) {
    std::vector<int> odd = getLongestPalindromeFrom(str, i - 1, i + 1);
    std::vector<int> even = getLongestPalindromeFrom(str, i - 1, i);
    std::vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
    currentLongest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? currentLongest : longest;
  }

  return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
}

int main() { assert(longestPalindromicSubstring("abaxyzzyxf") == "xyzzyx"); }
