// Knight Connection

// You're given the position of two knight pieces on an infinite chess board. Write a function that
// returns the minimum number of turns required before one of the knights is able to capture the
// other knight, assuming the knights are working together to achieve this goal.

// The position of each knight is given as a list of 2 values, the x and y coordinates. A knight can
// make 1 of 8 possible moves on any given turn. Each of these moves involves moving in an "L"
// shape. This means they can either move 2 squares horizontally and 1 square vertically, or they
// can move 1 square horizontally and 2 squares vertically. For example, if a knight is currently at
// position [0, O], then it can move to any of these 8 locations on its next move:

// { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, { -2, -1 } }

// A knight is able to capture the other knight when it is able to move onto the square currently
// occupied by the other knight.

// Each turn allows each knight to move up to one time. For example, if both knights moved
// towards each other once, and then knightA captures knightB on its next move, two turns would
// have been used (even though knightB never made its second move).

#include <cassert>
#include <cmath>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

std::string positionToString(std::vector<int> position) {
  return std::to_string(position[0]) + "," + std::to_string(position[1]);
}

// TC: O(n * m) | SC: O(n * m)
int knightConnection(std::vector<int> knightA, std::vector<int> knightB) {
  std::vector<std::vector<int>> possibleMoves = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                                                 {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

  std::queue<std::vector<int>> nodes;
  nodes.push({knightA[0], knightA[1], 0});

  std::unordered_set<std::string> visited;
  visited.insert(positionToString(knightA));

  while (true) {
    std::vector<int> currentPosition = nodes.front();
    nodes.pop();

    if (currentPosition[0] == knightB[0] && currentPosition[1] == knightB[1]) {
      return std::ceil(static_cast<double>(currentPosition[2]) / 2);
    }

    for (auto const& move : possibleMoves) {
      std::vector<int> position = {currentPosition[0] + move[0], currentPosition[1] + move[1]};
      std::string positionString = positionToString(position);

      if (visited.find(positionString) == visited.end()) {
        position.push_back(currentPosition[2] + 1);
        nodes.push(position);
        visited.insert(positionString);
      }
    }
  }

  return -1;
}

int main() {
  auto knightA = {0, 0};
  auto knightB = {2, 1};
  auto expected = 1;
  auto actual = knightConnection(knightA, knightB);
  assert(expected == actual);
}
