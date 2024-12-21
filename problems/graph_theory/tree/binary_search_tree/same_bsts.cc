// Same BSTs

// An array of integers is said to represent the Binary Search Tree (BST) obtained by inserting each
// integer in the array, from left to right, into the BST.

// Write a function that takes in two arrays of integers and determines whether these arrays
// represent the same BST. Note that you're notallowed to construct any BSTs in your code.

// A BST is a Binary Tree that consists onlyof BST nodes. A node is said to be a valid BST node if
// and only if it satisfies the BST property: its value is strictly greater than the values of every node
// to its left; its value is less than or equal to the values of every node to its right; and its children
// nodes are either valid BST nodes themselves or None / null

#include <cassert>
#include <climits>
#include <vector>

int getIdxOffFirstSmaller(std::vector<int> array, int startingIdx, int minVal) {
  for (int i = startingIdx + 1; i < array.size(); i++) {
    if (array[i] < array[startingIdx] && array[i] >= minVal) return i;
  }

  return -1;
}

int getIdxOffFirstBiggerOrEqual(std::vector<int> array, int startingIdx, int maxVal) {
  for (int i = startingIdx + 1; i < array.size(); i++) {
    if (array[i] >= array[startingIdx] && array[i] < maxVal) return i;
  }

  return -1;
}

bool areSameBsts(std::vector<int> arrayOne, std::vector<int> arrayTwo, int rootIdxOne, int rootIdxTwo, int minVal,
                 int maxVal) {
  if (rootIdxOne == -1 || rootIdxTwo == -1) return rootIdxOne == rootIdxTwo;

  if (arrayOne[rootIdxOne] != arrayTwo[rootIdxTwo]) return false;

  int leftRootIdxOne = getIdxOffFirstSmaller(arrayOne, rootIdxOne, minVal);
  int leftRootIdxTwo = getIdxOffFirstSmaller(arrayTwo, rootIdxTwo, minVal);

  int rightRootIdxOne = getIdxOffFirstBiggerOrEqual(arrayOne, rootIdxOne, maxVal);
  int rightRootIdxTwo = getIdxOffFirstBiggerOrEqual(arrayTwo, rootIdxTwo, maxVal);

  int currentValue = arrayOne[rootIdxOne];
  bool leftAreSame = areSameBsts(arrayOne, arrayTwo, leftRootIdxOne, leftRootIdxTwo, minVal, currentValue);
  bool rightAreSame = areSameBsts(arrayOne, arrayTwo, rightRootIdxOne, rightRootIdxTwo, currentValue, maxVal);

  return leftAreSame && rightAreSame;
}

bool sameBsts(std::vector<int> arrayOne, std::vector<int> arrayTwo) {
  return areSameBsts(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}

int main() {
  std::vector<int> arrayOne = {10, 15, 8, 12, 94, 81, 5, 2, 11};
  std::vector<int> arrayTwo = {10, 8, 5, 15, 2, 12, 11, 94, 81};
  assert(sameBsts(arrayOne, arrayTwo) == true);
}
