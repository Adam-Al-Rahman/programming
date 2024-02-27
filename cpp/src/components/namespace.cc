#include <iostream>

using std::cout;
using std::string;

namespace piyush {
string child = "wallah kadsjflkasflk";
}

namespace shahan {
string child = "habibi kldsaflkasjlkj";
}

// using the directive method to use the namespace
using namespace piyush;

int main() { cout << child; }
