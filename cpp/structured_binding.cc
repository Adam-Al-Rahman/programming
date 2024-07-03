/**
 * Structured Binding
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cstdint>
#include <string>
#include <tuple>

std::tuple<std::string, std::uint32_t> create_person() { return {"Aman", 22}; }

int main() {
  // Method 1
  std::tuple<std::string, std::uint32_t> person = create_person();

  // Method 2: only auto && std::get
  std::string& name_m2 = std::get<0>(person);
  std::uint32_t age_m2 = std::get<1>(person);

  // Method 3: using std::tie
  std::string name_m3;
  std::uint32_t age_m3;
  std::tie(name_m3, age_m3) = create_person();

  // Method 4: Structured Binding
  // Available: C++17
  auto [name_m4, age_m4] = create_person();
}
