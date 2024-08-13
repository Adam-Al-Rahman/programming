// Copyright 2024 Adam-Al-Rahman

#include <iostream>

// Basic Enumeration
enum BasicColor { RED, GREEN, BLUE };

// Scoped Enumeration (Recommended)
enum class ScopedColor { RED, GREEN, BLUE };

int main() {
  BasicColor b_color = RED;
  ScopedColor s_color = ScopedColor::BLUE;

  if (b_color == RED) std::cout << "The color is red!" << '\n';
  if (s_color == ScopedColor::BLUE) std::cout << "The color is blue!" << '\n';
  std::cout << std::flush;
}
