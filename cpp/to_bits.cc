/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief:
 * @source:
 * @tags: ["topics/bits", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <bitset>
#include <cstring>

template <typename T>
std::bitset<sizeof(T) * 8> toBits(const T& value) {
  std::bitset<sizeof(T) * 8> bits;
  std::memcpy(bits.data(), &value, sizeof(T));
  return bits;
}
