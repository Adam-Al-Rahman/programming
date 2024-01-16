#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>


template <typename T, typename  U>
struct Link {
  T from_vertex;
  std::vector<U> to_vertices;

  Link(T from_vertex, std::vector<U> to_vertices) : from_vertex(from_vertex), to_vertices(to_vertices){};
};

template <typename T, typename U>
void hello(const Link<T, U>& unit) {
  
  std::stringstream ss_unit_from_vertex;
  ss_unit_from_vertex << unit.from_vertex;

  std::stringstream ss_unit_to_vertices;
  ss_unit_to_vertices << &unit.to_vertices;

  std::cout << std::hash<std::string>()(ss_unit_from_vertex.str() + " => " + ss_unit_to_vertices.str());
}

int main(){


}
