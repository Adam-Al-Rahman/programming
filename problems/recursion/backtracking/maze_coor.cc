// Copyright 2024 Adam-Al-Rahman

#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

namespace px {
using node =
    std::tuple<std::int32_t, std::int32_t, std::string, std::vector<std::vector<bool>>>;  // {x, y, path, visited}
}

// Check if the move is valid
inline bool is_valid_move(std::int32_t x, std::int32_t y, std::int32_t rows, std::int32_t cols,
                          const std::vector<std::vector<bool>>& visited) {
  return x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y];
}

std::vector<std::string> find_paths(std::int32_t n, std::int32_t m) {
  std::vector<std::string> result;

  const std::vector<std::tuple<std::int32_t, std::int32_t, std::string>> directions = {
      {0, 1, "R"},   // Right
      {0, -1, "L"},  // Left
      {1, 0, "D"},   // Down
      {-1, 0, "U"}   // Up
  };

  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

  std::stack<px::node> nodes;
  nodes.push({0, 0, "", visited});

  while (!nodes.empty()) {
    auto [x, y, path, visited] = nodes.top();
    nodes.pop();

    if (x == n - 1 && y == m - 1) {
      result.push_back(path);
      continue;
    }

    if (visited[x][y]) continue;
    visited[x][y] = true;

    for (const auto& [dx, dy, dir] : directions) {
      std::int32_t new_x = x + dx;
      std::int32_t new_y = y + dy;

      if (is_valid_move(new_x, new_y, n, m, visited)) nodes.push({new_x, new_y, path + dir, visited});
    }

    visited[x][y] = false;
  }

  return result;
}

int main() {
  std::int32_t n = 3;
  std::int32_t m = 4;
  std::vector<std::string> paths = find_paths(n, m);

  std::cout << "# Paths: " << paths.size() << '\n';
  for (const auto& path : paths) std::cout << path << '\n';
}
