// Graph Representation
// Adjacency List
//
#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T, typename U>
struct Link {
    T from_vertex;
    std::vector<U> to_vertices;

    Link(T from_vertex, std::vector<U> to_vertices) : from_vertex(from_vertex), to_vertices(to_vertices) {};

    bool operator==(const Link<T, U>& nodes) const {
        return (from_vertex == nodes.from_vertex) && (to_vertices == nodes.to_vertices);
    }
};

namespace std {
    template <typename T, typename U>
    struct hash<Link<T, U>> { // similar to Jenkins hash function
        size_t operator()(const Link<T, U>& unit) const {
            size_t hash_val = 0;

            // Hashing the from_vertex
            std::hash<T> hasher;
            hash_val ^= hasher(unit.from_vertex) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);

            // Hashing the to_vertices
            // stringstream ss_unit_to_vertices;
            // ss_unit_to_vertices << &unit.to_vertices;
            // hash_val ^= hasher(ss_unit_to_vertices.str()) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
            for (const auto& vertex : unit.to_vertices) {
                hash_val ^= hasher(vertex) + 0x9e3779b9 + (hash_val << 6) + (hash_val >> 2);
            }

            return hash_val;
        }
    };
};

int main() {
    std::vector<char> vertices;
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char vertex;
        std::cin >> vertex;
        vertices.push_back(vertex);
    }

    std::unordered_map<Link<char, char>, std::vector<int>> graph;
    /*
     * In competitive programming instead of create unordered_map for `graph` create  a vector.
     * template<typename T, typename U>
     * class Link {
     * public:
     *   T from_vertex;
     *   std::vector<U> to_vertices
     *   int graph;
     *
     *   Link(T from_vertex, std::vector<U> to_vertices, int graph) : from_vertex(from_vertex), to_vertices(to_vertices), graph(graph){};
     * }
     *
     * std::vector<Link<char, char>> graph;
     * graph[0] = { Link<char, char>(vertices[0], { vertices[1] }), {5} };
     *
    */

    // edge graph
    graph[Link<char, char>(vertices[0], { vertices[1] })] = { 5 };
    graph[Link<char, char>(vertices[1], { vertices[0], vertices[2], vertices[4] })] = { 4, 3, 8 };
    graph[Link<char, char>(vertices[2], { vertices[4] })] = { 2 };
    graph[Link<char, char>(vertices[3], { vertices[0], vertices[1] })] = { 2, 4 };
    graph[Link<char, char>(vertices[4], { vertices[1], vertices[3] })] = { 4, 3 };


  // Q. What is weight between B --> E i.e 1 --> 2;
  // std::cout << graph[Link<char, char>(vertices[1], {vertices[2]})][1];

}
