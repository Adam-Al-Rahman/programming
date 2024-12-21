// Count Squares

// Write a function that takes in a list of Cartesian coordinates (i.e., (x, y) coordinates) and returns
// the number of squares that can be formed by these coordinates.

// A square must have its four corners amongst the coordinates in order to be counted. A single
// coordinate can be used as a corner for multiple different squares.

// You can also assume that no coordinate will be farther than 100 units from the origin.

#include <cassert>
#include <cmath>
#include <string>
#include <unordered_set>
#include <vector>

std::string pointToString(std::vector<int> const& point) {
  return std::to_string(point[0]) + "," + std::to_string(point[1]);
}

std::string dbPointToString(std::vector<double> const& point) {
  if (std::fmod(point[0], 1) == 0 && std::fmod(point[1], 1) == 0) {
    return std::to_string((int)point[0]) + "," + std::to_string((int)point[1]);
  }
  return std::to_string(point[0]) + "," + std::to_string(point[1]);
}

int countSquares(std::vector<std::vector<int>> points) {
  std::unordered_set<std::string> pointsSet;
  for (auto const& point : points) pointsSet.insert(pointToString(point));

  int count = 0;
  for (auto const& pointA : points) {
    for (auto const& pointB : points) {
      if (pointA == pointB) continue;

      std::vector<double> midpoint = {(pointA[0] + pointB[0]) / 2.0, (pointA[1] + pointB[1]) / 2.0};

      double xDistanceFromMid = pointA[0] - midpoint[0];
      double yDistanceFromMid = pointA[1] - midpoint[1];

      std::vector<double> pointC = {midpoint[0] + yDistanceFromMid, midpoint[1] - xDistanceFromMid};
      std::vector<double> pointD = {midpoint[0] - yDistanceFromMid, midpoint[1] + xDistanceFromMid};

      if (pointsSet.count(dbPointToString(pointC)) && pointsSet.count(dbPointToString(pointD))) count += 1;
    }
  }

  return count / 4;
}

int main() {
  std::vector<std::vector<int>> input = {{1, 1}, {0, 0}, {0, 1}, {1, 0}};
  auto expected = 1;
  auto actual = countSquares(input);
  assert(expected == actual);
}
