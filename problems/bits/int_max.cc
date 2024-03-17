/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Int Max
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <climits>
#include <cstdint>
#include <iostream>

/**
*
int b(int x) {
  int arr[4] = {x, 1, x + 1, 0};
  return arr[x % 4];
}

int bb(int x) {
  int arr[8] = {x, x, 2, 2, x + 2, x + 2, 0, 0};
  return arr[x % 8];
}

void solve() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  y = min(y, (m - y) + 1);
  x = min(x, (n - x) + 1);
  int ans = bb(m - y + n - x) ^ bb(m - y + x - 1) ^ b(m - y) ^
            bb(y - 1 + n - x) ^ bb(y - 1 + x - 1) ^ b(y - 1) ^ b(n - x) ^
            b(x - 1);
  cout << ans << endl;
}
*
*/

int main() {
  std::cout << INT_MAX << '\n' << std::flush;

  std::int32_t max_val = (1LL << 31) - 1;
  std::cout << max_val;
}
