// ╔════════════════════════════════════════════════════════════════════╗
// ║ Competitive programming is not about solving problems.             ║
// ║ It's about continuously evolving your approach to problem-solving. ║
// ╚════════════════════════════════════════════════════════════════════╝
// author: Adam-Al-Rahman <https://atiq-ur-rehaman.netlify.app>

// ONLINE_JUDGE
// #define ONLINE_JUDGE

// HEADERS (Required)
#include <cstdint>  // std::int32_t, std::int16_t, std::int64_t
#include <cstdio>   // freopen
#include <ctime>    // std::clock
#include <ios>      // std::ios_base
#include <iostream>
#include <tuple>  // std::tuple

// HEADERS (Current)
#include <unordered_set>
#include <vector>

// GLOBAL CONSTANTS EXPRESSIONS
namespace px {
constexpr std::int32_t mod = std::int32_t(1e9) + 7;  // Modulus
constexpr std::int32_t num = std::int32_t(2e5) + 5;
}  // namespace px

// PROBLEM KEYPOINTS

// HELPER FUNCTIONS | STRUCT | CLASS | ALIAS
namespace px {
using node = std::tuple<std::int64_t, std::int64_t, std::int64_t>;  // NOTE: {high priority, low priority }
}  // namespace px

class DisjointSetUnion {
 public:
  std::vector<int> parent;
  std::vector<int> rank;

  explicit DisjointSetUnion(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int u) {
    while (u != parent[u]) {
      parent[u] = parent[parent[u]];  // path compression
      u = parent[u];
    }
    return u;
  }

  void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v) return;  // Already in the same set

    // Union by rank
    if (rank[root_u] < rank[root_v]) {
      parent[root_u] = root_v;
    } else if (rank[root_u] > rank[root_v]) {
      parent[root_v] = root_u;
    } else {
      parent[root_v] = root_u;
      rank[root_u]++;
    }
  }
};

int find_circle_num(std::vector<std::vector<int>>& isConnected) {
  DisjointSetUnion dsu(isConnected.size());

  // convert `adjacent matrix` --> `adjacent list`
  std::vector<px::node> edges;  // Store all edges as {weight, u, v}
  for (int u = 0; u < isConnected.size(); u++) {
    for (int v = 0; v < isConnected[0].size(); v++) {
      if (isConnected[u][v] != 0 && u != v) {  // NOTE: Constrains
        edges.emplace_back(isConnected[u][v], u, v);
      }
    }
  }

  for (const auto& [weight, u, v] : edges) {
    if (dsu.find(u) != dsu.find(v)) dsu.unite(u, v);
  }

  std::unordered_set<int> unique_parent;
  for (int i = 0; i < dsu.parent.size(); ++i) {
    unique_parent.insert(dsu.find(i));  // Find the ultimate parent/root of each node
  }

  return unique_parent.size();
}

// PROBLEM SOLUTION
void solution() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> isConnected(n, std::vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) std::cin >> isConnected[i][j];
  }

  std::cout << "Number of Provinces: " << find_circle_num(isConnected);
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

#ifndef ONLINE_JUDGE
  (void)freopen("./zero/input.txt", "r", stdin);
  (void)freopen("./zero/output.txt", "w", stdout);
#endif  // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  std::clock_t start_time = std::clock();
#endif  // ONLINE_JUDGE

  std::uint32_t tests = 1;
  // std::cin >> tests;  // overwrite
  while (tests--) solution();

#ifndef ONLINE_JUDGE
  std::clock_t end_time = std::clock();
  std::cerr << "Experimental Run Time(sec): " << (static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC)
            << std::endl;
#endif  // ONLINE_JUDGE
}
