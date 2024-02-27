/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <vector>

// n signs of apocalypse
// i-th sign occurs every a_{i} years (in years a_{i}, 2 * a_{i}, 3 * a_{i})
//
// apocalypse happens, signs must occur sequentially
// tasks:
// - in which year will n-th sign occur and apocalypse will happen

std::int32_t chaya_calendar(std::vector<std::int32_t> years) {
  std::int32_t prev_year = years[0];

  std::int32_t index = 1;
  while (index < years.size()) {
    if (years[index] > prev_year)
      prev_year = years[index];
    else
      prev_year = ((prev_year / years[index]) + 1) * years[index];

    index++;
  }

  return prev_year;
}

int main() {
  std::uint16_t tests;
  std::cin >> tests;

  while (tests--) {
    std::uint16_t n;
    std::cin >> n;

    std::vector<std::int32_t> years;
    for (int i = 0; i < n; i++) {
      std::int32_t a;
      std::cin >> a;
      years.push_back(a);
    }
    std::cout << chaya_calendar(years) << '\n' << std::flush;
  }
}
