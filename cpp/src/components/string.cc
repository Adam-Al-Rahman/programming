#include "./boost/include/range/adaptor/reversed.hpp"
#include <iostream>
#include <string>

const std::string string_reverse(std::string string_x) {
  std::string return_string;
  for (char const &each_character : boost::adaptors::reverse(string_x))
    return_string.append(each_character);
  return return_string;
}

int main() {
  char a = 'a';
  std::string str = "Hello World";
  std::cout << str << std::endl;

  std::string str_2;
  std::cin >> str_2;

  // for (char const &each_character : str_2)
  //   std::cout << each_character;
  std::cout << string_reverse(str_2);
}
