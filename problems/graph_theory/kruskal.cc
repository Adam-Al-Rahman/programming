// Copyright 2024 Adam-Al-Rahman

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

// Edge alternative px::node
namespace px {
using node = std::tuple<std::int64_t, std::int64_t, std::int64_t>;  // {weight, u, v}
}  // namespace px

// Data structure for Kruskal's Algorithm
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
      u = parent[u];                  // NOTE: only this lead to without path compression
    }
    return u;
  }

  void unite(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);

    if (root_u == root_v) return;  // Already in the same set;

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

// Kruskal Algorithm
int kruskal(int n, std::vector<px::node>& edges) {
  DisjointSetUnion dsu(n);
  std::sort(edges.begin(), edges.end());

  int mst_weight = 0;
  for (auto [weight, u, v] : edges) {
    if (dsu.find(u) != dsu.find(v)) {
      mst_weight += weight;
      dsu.unite(u, v);
    }
  }

  return mst_weight;
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<px::node> edges(m);
  for (auto& [weight, u, v] : edges) std::cin >> u >> v >> weight;

  std::cout << "Weight of the MST is " << kruskal(n, edges) << std::endl;
}
