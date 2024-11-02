// Union Find

// The union-find data structure is similar to a traditional set data structure in that it
// contains a collection of unique values. However, these values are spread out
// amongst a variety of distinct disjoint sets, meaning that no set can have duplicate
// values, and no two sets can contain the same value.

// Write a UnionFind class that implements the union-find (also called a disjoint set)
// data structure. This class should support three methods:

// - createSet (value) : Adds a given value in a new set containing only that
// value.
// - union (valueOne, vatueTwo) : Takes in two values and determines which
// sets they are in. If they are in different sets, the sets are combined into a single
// set. If either value is not in a set or they are in the same set, the function should
// have no effect.
// - find (value) : Returns the "representative" value of the set for which a value
// belongs to. This can be any value in the set, but it should always be the same
// value, regardless of which value in the set find is passed. If the value is not in
// a set, the function should return null / None . Note that after a set is part of
// a union, its representative can potentially change.

// You can assume createSet will never be called with the same value twice.

// If you're unfamiliar with Union Find, we recommend watching the Conceptual
// Overview section of this question's video explanation before starting to code.

#include <cassert>
#include <optional>
#include <unordered_map>

class UnionFind {
 public:
  std::unordered_map<int, int> parents;
  std::unordered_map<int, int> ranks;

  void createSet(int value) {
    parents[value] = value;
    ranks[value] = 0;
  }

  // O(α(n)), approximately O(1) time | O(α(n)), approximately O(1) space
  std::optional<int> find(int value) {
    if (parents.find(value) == parents.end()) return std::nullopt;

    while (value != parents[value]) {
      parents[value] = parents[parents[value]];
      value = parents[value];
    }

    return value;
  }

  // O(α(n)), approximately O(1) time | O(α(n)), approximately O(1) space
  void createUnion(int valueOne, int valueTwo) {
    if (parents.find(valueOne) == parents.end() || parents.find(valueTwo) == parents.end()) return;

    int valueOneRoot = *find(valueOne);
    int valueTwoRoot = *find(valueTwo);

    if (ranks[valueOneRoot] < ranks[valueTwoRoot]) {
      parents[valueOneRoot] = valueTwoRoot;
    } else if (ranks[valueOneRoot] > ranks[valueTwoRoot]) {
      parents[valueTwoRoot] = valueOneRoot;
    } else {
      parents[valueTwoRoot] = valueOneRoot;
      ranks[valueOneRoot] = ranks[valueOneRoot] + 1;
    }
  }
};

int main() {
  auto unionFind = new UnionFind();
  auto findResult = unionFind->find(1);
  assert(!findResult);

  unionFind->createSet(1);
  findResult = unionFind->find(1);
  assert(findResult && *findResult == 1);

  unionFind->createSet(5);
  findResult = unionFind->find(1);
  assert(findResult && *findResult == 1);

  findResult = unionFind->find(5);
  assert(findResult && *findResult == 5);

  unionFind->createUnion(5, 1);
  findResult = unionFind->find(5);
  auto findResult2 = unionFind->find(1);
  assert(findResult && findResult2 && *findResult == *findResult2);
}
