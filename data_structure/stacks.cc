#include <iostream>
#include <stack>
#include <string>

int main(){
  
  std::stack<std::string> shelf;

  shelf.push("Book1");
  shelf.push("Book2");
  shelf.push("Book3");

  // If want to iterate without empting the stack
  // create a the copy of original stack
  while(!shelf.empty()){
    std::cout << shelf.top() << std::endl;
    shelf.pop();
  }

}
