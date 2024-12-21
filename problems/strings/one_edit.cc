// One Edit

// You're given two strings stri ngOne and stri ngTwo . Write a function that determines if
// these two strings can be made equal using only one edit.

// There are 3 possible edits:
// • Replace: One character in one string is swapped for a different character.
// • Add: One character is added at any index in one string.
// • Remove: One character is removed at any index in one string.

// Note that both strings will contain at least one character. If the strings are the same, your
// function should return true.

#include <cassert>
#include <string>

bool oneEdit(std::string s1, std::string s2) {
  int l1 = s1.size();
  int l2 = s2.size();

  if (std::abs(l1 - l2) > 1) return false;

  bool madeEdit = false;
  int i1 = 0;
  int i2 = 0;

  while (i1 < l1 && i2 < l2) {
    if (s1[i1] != s2[i2]) {
      if (madeEdit) return false;
      madeEdit = true;

      if (l1 > l2) {
        i1 += 1;
      } else if (l2 > l1) {
        i2 += 1;
      } else {
        i1 += 1;
        i2 += 1;
      }

    } else {
      i1 += 1;
      i2 += 1;
    }
  }

  return true;
}

int main() {
  auto stringOne = "hello";
  auto stringTwo = "helo";
  auto expected = true;
  auto actual = oneEdit(stringOne, stringTwo);
  assert(expected == actual);
}
