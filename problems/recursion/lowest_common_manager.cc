// Copyright 2024 Adam-Al-Rahman

/**
You're given three inputs, all of which are instances of an OrgChart class that have a
di rectReports property pointing to their direct reports. The first input is the top manager in
an organizational chart (i.e., the only instance that isn't anybody else's direct report), and the
other two inputs are reports in the organizational chart. The two reports are guaranteed to be
distinct.

Write a function that returns the lowest common manager to the two reports.

Example:
topManager = Node A
reportOne = Node E
reportTwo = Node I

      A
     / \
    B   C
   / \  / \
  D   E F  G
 / \
H   I
*/

#include <cassert>
#include <cstdint>
#include <ios>
#include <iostream>
#include <iterator>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class OrgChart {
 public:
  char name;
  std::vector<OrgChart*> directReports;

  explicit inline OrgChart(char name) : name(name) {}

  inline void addDirectReports(std::vector<OrgChart*> directReports) {
    this->directReports.reserve(this->directReports.size() + directReports.size());  // Reserve space
    this->directReports.insert(this->directReports.end(), std::make_move_iterator(directReports.begin()),
                               std::make_move_iterator(directReports.end()));
  }
};

namespace px {
using node = std::tuple<std::uint16_t, OrgChart*>;  // {no_reports, current}
}

std::unordered_map<char, OrgChart*> getOrgcharts() {
  std::unordered_map<char, OrgChart*> orgCharts;
  std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (char a : alphabet) {
    orgCharts.insert({a, new OrgChart(a)});
  }
  orgCharts.at('X')->addDirectReports({
      orgCharts.at('Z'),
  });
  return orgCharts;
}

OrgChart* getLowestCommonManager(OrgChart* topManager, OrgChart* reportOne, OrgChart* reportTwo) {
  // Map to store the parent of each node
  std::unordered_map<OrgChart*, OrgChart*> parentMap;

  // Stack for DFS traversal
  std::stack<OrgChart*> nodes;
  nodes.push(topManager);

  // Perform DFS to populate parentMap
  while (!nodes.empty()) {
    OrgChart* current = nodes.top();
    nodes.pop();

    // Traverse children
    for (auto child : current->directReports) {
      parentMap[child] = current;
      nodes.push(child);
    }
  }

  // Find the path from reportOne to the topManager
  std::unordered_set<OrgChart*> ancestors;
  OrgChart* current = reportOne;

  while (current) {
    ancestors.insert(current);
    current = parentMap[current];
  }

  // Find the lowest common manager from reportTwo
  current = reportTwo;
  while (current) {
    if (ancestors.count(current)) return current;
    current = parentMap[current];
  }

  // If no common manager found (which theoretically shouldn't happen), return nullptr
  return nullptr;
}

int main() {
  auto orgCharts = getOrgcharts();
  orgCharts.at('A')->addDirectReports({orgCharts.at('B'), orgCharts.at('C')});
  orgCharts.at('B')->addDirectReports({orgCharts.at('D'), orgCharts.at('E')});
  orgCharts.at('C')->addDirectReports({orgCharts.at('F'), orgCharts.at('G')});
  orgCharts.at('D')->addDirectReports({orgCharts.at('H'), orgCharts.at('I')});

  OrgChart* lcm = getLowestCommonManager(orgCharts.at('A'), orgCharts.at('E'), orgCharts.at('I'));

  bool condition = (lcm == orgCharts.at('B'));
  assert(condition);  // This will trigger if the condition is false during debugging.

  // The std::boolalpha manipulator ensures that true or false is printed instead of 1 or 0.
  std::cout << std::boolalpha << condition << std::endl;
}
