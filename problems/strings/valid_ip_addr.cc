// Copyright 2024 Adam-Al-Rahman

#include <cstdint>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

namespace px {
using node = std::tuple<std::string, std::uint16_t, std::uint16_t>;  // {ip, position, dot_count}
}

bool is_ip(std::string ip) {
  std::istringstream ss(ip);
  std::string segment;
  std::uint16_t dot_counts = 0;

  while (std::getline(ss, segment, '.')) {
    if (segment.empty() || segment.size() > 3 || (segment.size() > 1 && segment[0] == '0'))
      return false;  // NOTE: (segment.size() > 1 && segment[0] == '0'): Invalid 01.0.0.0
    std::uint16_t digits = std::stoi(segment);
    if (digits > 255) return false;
    ++dot_counts;
  }

  return dot_counts == 4;
}

std::vector<std::string> validIPAddresses(std::string digits) {
  std::vector<std::string> ips;

  std::queue<px::node> nodes;
  nodes.push({digits, 0, 0});

  while (!nodes.empty()) {
    auto [ip, position, dot_count] = nodes.front();
    nodes.pop();

    if (dot_count == 3) {
      if (is_ip(ip)) ips.push_back(ip);
      continue;
    }

    for (std::uint16_t i = 1; i <= 3 && position + i < ip.size(); ++i) {
      std::string new_ip = ip;
      new_ip.insert(position + i, 1, '.');
      nodes.push({new_ip, position + i + 1, dot_count + 1});
    }
  }

  return ips;
}

int main() {
  for (auto &x : validIPAddresses("1921680")) std::cout << x << '\n';
}
