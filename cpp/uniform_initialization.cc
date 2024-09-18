// Copyright 2024 Adam-Al-Rahman
// Uniform Initialization

// Uniform Initialization can prevent `narrowing conversion error` or `implicit conversion`.

int main() {
  int x = 1.5;  // Allowed: x will be 1
  int y{1.5};   // Error: Narrowing conversion
}
