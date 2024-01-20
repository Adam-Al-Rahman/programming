// Move Semantic
// It was possible in c++11 because in c++11 the `rvalue references` was
// introduced Which is required for move semantics
//

#include <cstdint>
#include <cstring>

class String {
private:
  char *m_data;
  std::uint32_t m_size;

public:
  String() = default;
  String(const char *string) {
    m_size = strlen(string);
    m_data = new char[m_size];
    memcpy(m_data, string, m_size);
  }
};

int main() {}
