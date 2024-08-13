// Q: https://projecteuler.net/problem=2
//
#include <cstdint>
#include <iostream>
#include <queue>

std::uint64_t ProjectEulerFib() {
  std::queue<std::uint64_t> nodes;
  nodes.push(1);
  nodes.push(2);

  std::uint64_t even_sum = 2;  // Start with the first even Fibonacci number
  std::uint64_t result = 0;

  while (true) {
    std::uint64_t first = nodes.front();
    nodes.pop();

    std::uint64_t second = nodes.front();

    result = first + second;
    if (result > 4000000) break;

    if (result % 2 == 0) even_sum += result;
    nodes.push(result);
  }

  return even_sum;
}

int main() { std::cout << ProjectEulerFib() << std::endl; }
