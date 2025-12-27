// When we write Point, what information does the compiler already know?
// → its name, its members, their types, alignment, access specifiers, etc.

// Normally, can we use that information in our own code at compile time?
// → No — before reflection, that information dies inside the compiler.

// What does std::meta do?
// → It exposes that internal knowledge as first-class, constexpr data.

// So what can we do with that?
// → Anything that depends on knowing structure: serialization, comparison,
// hashing, GUIs, bindings, documentation, code generation.

#include <cstdint>
#include <iostream>
#include <meta>

struct Point {
  int x;
  double y;
};

int main() {
  // The ^^ operator is the proposed reflection operator.
  // It returns a constexpr object containing metadata about the type.
  constexpr std::meta::info point_info = ^^Point;

  // We can query this metadata at compile time.
  // This line isn't used in the splicer loop below, but we'll keep it.
  [[maybe_unused]] constexpr auto members = std::meta::data_member_spec(point_info);

  // Retrieve the name of the reflected type
  // (P2996 also renamed name_of to identifier_of)
  std::cout << "Type: " << std::meta::identifier_of(point_info) << std::endl;
}
