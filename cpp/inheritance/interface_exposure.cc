// Copyright 2024 Adam-Al-Rahman
// Inheritance/AccessModifier/InterfaceExposure

/**InterfaceExposure
_Interface Exposure_

Public Inheritance: The derived class is considered an "is-a" type of the base class,
meaning it inherits the interface of the base class. This allows external code to use the derived
class as if it were an instance of the base class, accessing both public and protected members.

Protected Inheritance: The derived class does not expose the base class
interface to the outside world. It restricts access so that only the derived class and its
subclasses can interact with the base class members. This encapsulates the base class more tightly.
**/

#include <iostream>

class Base {
 public:
  void public_method() { std::cout << "Public method called." << std::endl; }

 protected:
  void protected_method() { std::cout << "Protected method called." << std::endl; }
};

class Derived : protected Base {
 public:
  void call_methods() {
    public_method();     // Accessible
    protected_method();  // Accessible
  }
};

int main() {
  Derived d;
  d.public_method();     // Error: 'public_method' is not accessible
  d.protected_method();  // Error: 'protected_method' is not accessible

  d.call_methods();  // Works, calls the methods from the Derived class
  return 0;
}
