// Copyright 2024 Adam-Al-Rahman
// How to search in Linear Time?
// Basic: Karp-Rabin String Matching Algorithm Θ(n + m)
// Advance:
//   - Monte Carlo Variant uisng multiple hash functions
//   - Las Vegas Variant

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

constexpr std::int32_t kBase = 256;   // number of possible characters
constexpr std::int32_t kPrime = 101;  // prime number for modulo operation

// Computes hash of a string with given length using base and prime
std::int32_t calculate_hash(const std::string& str, std::int32_t len, std::int32_t base, std::int32_t prime) {
  std::int32_t hash = 0;
  for (std::int32_t i = 0; i < len; ++i) hash = (base * hash + str[i]) % prime;
  return hash;
}

// Checks if the pattern matches the text starting from the given index
bool match(const std::string& text, const std::string& pattern, std::int32_t index) {
  for (std::int32_t i = 0; i < pattern.length(); ++i) {
    if (text[index + i] != pattern[i]) return false;
  }
  return true;
}

// Searches for all occurrences of the pattern in the text using the Karp-Rabin algorithm
std::vector<std::int32_t> karp_rabin_search(const std::string& text, const std::string& pattern) {
  std::int32_t text_len = text.length();
  std::int32_t pattern_len = pattern.length();

  std::vector<std::int32_t> indices;

  if (pattern_len > text_len) return indices;  // Early exit if pattern is longer than text

  std::int32_t pattern_hash = calculate_hash(pattern, pattern_len, kBase, kPrime);
  std::int32_t text_hash = calculate_hash(text, pattern_len, kBase, kPrime);

  // Precompute the highest power of base mod prime
  std::int32_t base_pow = 1;
  for (std::int32_t i = 0; i < pattern_len - 1; ++i) base_pow = (base_pow * kBase) % kPrime;

  for (std::int32_t i = 0; i <= text_len - pattern_len; ++i) {
    if (text_hash == pattern_hash && match(text, pattern, i)) indices.push_back(i);

    if (i < text_len - pattern_len) {
      text_hash = (kBase * (text_hash - text[i] * base_pow) + text[i + pattern_len]) % kPrime;

      // Handle negative hash value
      if (text_hash < 0) text_hash += kPrime;
    }
  }

  return indices;
}

int main() {
  std::string text = "abracadabra";
  std::string pattern = "abra";
  std::vector<std::int32_t> indices = karp_rabin_search(text, pattern);

  for (std::int32_t index : indices) {
    std::cout << index << std::endl;
  }
}
