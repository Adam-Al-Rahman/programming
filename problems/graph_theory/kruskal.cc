/**
 * Copyright 2024 Adam-Al-Rahman
 */
#include <algorithm>
#include <iostream>
#include <vector>

struct Edge {
  int u;
  int v;
  int weight;

  // `<` operator overload
  bool operator<(this Edge& self, const Edge& other) const { return self.weight < other.weight; }
};

// Edge alternative px::node
namespace px {
using node = std::tuple<std::int64_t, std::int64_t, std::int64_t>;

bool operator<(const node& lhs, const node& rhs) { return std::get<2>(lhs) < std::get<2>(rhs); }
}  // namespace px

// Data structure for Kruskal's Algorithm
class DisjointSetUnion {
 public:
  std::vector<int> parent;
  std::vector<int> rank;

  DisjointSetUnion(this DisjointSetUnion& self, const int& n) {
    self.parent.resize(n);
    self.rank.resize(n, 0);
    for (int i = 0; i < n; i++) self.parent[i] = i;
  }

  int find(this DisjointSetUnion& self, int u) {
    while (u != self.parent[u]) {
      self.parent[u] = self.parent[self.parent[u]];  // path compression
      u = self.parent[u];
    }
    return u;
  }

  void unite(this DisjointSetUnion& self, int u, int v) {
    int root_u = self.find(u);
    int root_v = self.find(v);

    if (root_u == root_v) return;  // Already in the same set;

    // Union by rank
    if (self.rank[root_u] < self.rank[root_v]) {
      self.parent[root_u] = root_v;
    } else if (self.rank[root_u] > self.rank[root_v]) {
      self.parent[root_v] = root_u;
    } else {
      self.parent[root_v] = root_u;
      self.rank[root_u]++;
    }
  }
};

// Kruskal Algorithm
int kruskal(const int& n, std::vector<Edge>& edges) {
  DisjointSetUnion dsu(n);
  std::sort(edges.begin(), edges.end());

  int mst_weight = 0;
  for (const Edge& edge : edges) {
    if (dsu.find(edge.u) != dsu.find(edge.v)) {
      mst_weight += edge.weight;
      dsu.unite(edge.u, edge.v);
    }
  }

  return mst_weight;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    std::cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }
  std::cout << "Weight of the MST is " << kruskal(n, edges) << std::endl;
  return 0;
}
