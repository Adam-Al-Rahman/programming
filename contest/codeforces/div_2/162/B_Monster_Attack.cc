/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Monster Attack
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

/**
n monsters
i-th monster health = a_{i}
i-th monster initial location = x_{i}
*/

/** every second
1. fire k bullets at monsters
  - each bullet target only `one monster` decrease monster health by 1
2. monsters health 0 or less die.
3. all alive monster move 1 point closer to me
4. monster reach at 0, i lose.
*/

/** tasks:
 * Can you survive and kill all n
 monsters without letting any of them reach your character?
*/

/**
    xi.reserve(n);
    // Reserve space to avoid unnecessary reallocations. only
    // affects ai.capacity but not ai.size, here ai.size() is
    // zero because no value inserted, but ai.capacity() will be n;

*/

/** priority queue
#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::string monsters_attack(
    std::shared_ptr<std::vector<std::pair<int, int>>> monsters_locations_health,
    std::uint32_t k,
    std::function<bool(const std::pair<int, int>&, const std::pair<int, int>&)>
        compare_zero =
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
              return std::abs(a.first) > std::abs(b.first);
            },
    std::uint32_t left_bullet = 0) {
  if (monsters_locations_health->empty()) return "YES";

  std::uint32_t bullets_per_sec = k + left_bullet;
  std::pair<int, int> monster = monsters_locations_health->at(0);
  bullets_per_sec -= monster.second;

  if (bullets_per_sec > 0 && 2 < monsters_locations_health->size()) {
    std::pair<int, int> left_monster = monsters_locations_health->at(1);
    std::pair<int, int> right_monster = monsters_locations_health->at(2);

    if (std::abs(left_monster.first) < std::abs(right_monster.first)) {
      if (monster.second + left_monster.second > bullets_per_sec) return "NO";
      left_monster.second -= bullets_per_sec;
    } else {
      if (monster.second + right_monster.second > bullets_per_sec) return "NO";
      right_monster.second -= bullets_per_sec;
    }
  }

  if (bullets_per_sec > 0 && 1 < monsters_locations_health->size()) {
    std::pair<int, int> left_monster = monsters_locations_health->at(1);
    if (monster.second + left_monster.second > bullets_per_sec) return "NO";
    left_monster.second -= bullets_per_sec;
  }

  std::pop_heap(monsters_locations_health->begin(),
                monsters_locations_health->end(),
                compare_zero);  // swap the root to the last element;
  monsters_locations_health->pop_back();

  for (std::pair<int, int>& element : *monsters_locations_health) {
    if (element.first < 0)
      element.first += 1;
    else
      element.first -= 1;
  }

  return monsters_attack(monsters_locations_health, k, compare_zero,
                         bullets_per_sec);
}

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::uint32_t k;
    std::cin >> k;

    std::vector<std::uint64_t> ai(n, 0);  // monsters health
    for (std::uint64_t& element : ai) {
      std::cin >> element;
    }

    std::vector<std::uint64_t> xi(n, 0);  // monsters initial location
    for (std::uint64_t& element : xi) {
      std::cin >> element;
    }

    std::vector<std::pair<int, int>> monsters_locations_health;

    for (int i = 0; i < ai.size(); i++) {
      monsters_locations_health.push_back(std::make_pair(xi[i], ai[i]));
    }

    std::function<bool(const std::pair<int, int>&, const std::pair<int, int>&)>
        compare_zero =
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
              return std::abs(a.first) > std::abs(b.first);
            };

    std::make_heap(monsters_locations_health.begin(),
                   monsters_locations_health.end(), compare_zero);

    std::cout << monsters_attack(
                     std::make_shared<std::vector<std::pair<int, int>>>(
                         monsters_locations_health),
                     k, compare_zero)
              << '\n'
              << std::flush;
  }
}
*/

#include <iostream>
#include <vector>

int main() {
  std::uint32_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint32_t n;
    std::cin >> n;

    std::uint32_t k;
    std::cin >> k;

    std::vector<std::uint64_t> ai(n);  // monsters health
    for (std::uint64_t& element : ai) {
      std::cin >> element;
    }

    std::vector<std::int64_t> xi(n);  // monsters initial location
    for (std::int64_t& element : xi) {
      std::cin >> element;
    }

    std::vector<std::int64_t> monster_xi_hp(n + 1);  // corrected range
    for (std::uint64_t i = 0; i < n; ++i)
      monster_xi_hp[std::abs(xi[i])] += ai[i];

    bool win = true;
    std::int32_t left_bullets = 0;

    for (std::uint32_t i = 1; i <= n; ++i) {  // corrected loop condition
      left_bullets += k - monster_xi_hp[i];
      if (left_bullets < 0) {
        win = false;
        break;  // Break the loop if there are not enough bullets
      }
    }

    std::cout << (win ? "YES" : "NO") << '\n' << std::flush;
  }
}
