#include <iostream>
#include <limits>
#include <cstdint>
#include <algorithm>

// use signed because for negative weights
constexpr std::int32_t INF = std::numeric_limits<std::int32_t>::max();

int main(){

  std::uint32_t v; // # vertices
  std::cin >> v;

  std::uint32_t e; // # edges
  std::cin >> e;
  
  v++;
  std::vector<std::vector<std::int32_t>> distance(v, std::vector<int>(v, INF));

  for(int i = 0; i < e; ++i){
    std::int32_t src, dest, wt; // wt: weight
    std::cin >> src >> dest >> wt;
    distance[src][dest] = wt;
  }

  for(int k = 0; k < v; k++){
    for(int i = 0; i < v; i++){
      for(int j = 0; j < v; j++){
        // main logic
        if (distance[i][k] < INF && distance[k][j] < INF) distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
      }
    }
  }

    for(int i = 0; i < v; i++){
      for(int j = 0; j < v; j++){
        if (distance[i][j] == INF) std::cout << "I ";
        else std::cout << distance[i][j] << " ";
      }
      std::cout << '\n';
    }


}
