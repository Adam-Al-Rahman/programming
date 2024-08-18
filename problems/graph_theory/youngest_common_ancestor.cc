/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: youngest Common Ancestor
 * @brief:
 * @source:
 * @tags: ["topics/graph", "algorithms/", "methods/"]
 * @status: solved
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class AncestralTree {
 public:
  char name;
  AncestralTree* ancestor;

  explicit AncestralTree(char name) : name(name), ancestor(nullptr) {}

  void add_ancestor(std::vector<AncestralTree*> descendants) {
    for (AncestralTree* descendant : descendants) {
      descendant->ancestor = this;
    }
  }
};

std::unordered_map<char, AncestralTree*> getAncestralTrees() {
  std::unordered_map<char, AncestralTree*> trees;
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (char a : alphabet) {
    trees.insert({a, new AncestralTree(a)});
  }
  return trees;
}

int descendant_depth(AncestralTree* descendant, AncestralTree* topAncestor) {
  int depth = 0;

  while (descendant != topAncestor) {
    depth += 1;
    descendant = descendant->ancestor;
  }

  return depth;
}

AncestralTree* backtrack_ancestor(AncestralTree* lower_ancestor, AncestralTree* higher_ancestor, int depth_diff) {
  // Bring the lower_ancestor pointer to same level as higher_ancestor pointer
  while (depth_diff > 0) {
    lower_ancestor = lower_ancestor->ancestor;
    depth_diff -= 1;
  }

  // Check for common ancestor
  while (lower_ancestor != higher_ancestor) {
    lower_ancestor = lower_ancestor->ancestor;
    higher_ancestor = higher_ancestor->ancestor;
  }

  return lower_ancestor;  // now, they both copy pointer are equal to there ancestor;
}

AncestralTree* getYoungestCommonAncestor(AncestralTree* topAncestor, AncestralTree* descendantOne,
                                         AncestralTree* descendantTwo) {
  int done_depth = descendant_depth(descendantOne, topAncestor);
  int dtwo_depth = descendant_depth(descendantTwo, topAncestor);

  if (done_depth > dtwo_depth) return backtrack_ancestor(descendantOne, descendantTwo, done_depth - dtwo_depth);

  return backtrack_ancestor(descendantTwo, descendantOne, dtwo_depth - done_depth);
}

int main() {
  auto trees = getAncestralTrees();
  trees.at('A')->add_ancestor({trees.at('B'), trees.at('C')});
  trees.at('B')->add_ancestor({trees.at('D'), trees.at('E')});
  trees.at('D')->add_ancestor({trees.at('H'), trees.at('I')});
  trees.at('C')->add_ancestor({trees.at('F'), trees.at('G')});

  AncestralTree* yca = getYoungestCommonAncestor(trees.at('A'), trees.at('E'), trees.at('I'));

  std::cout << yca->name;
}
