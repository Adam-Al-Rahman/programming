// Copyright 2024 Adam Al-Rahman
// Singleton

/**
Q. Can we make `Contructor` private?

Yes, in C++, a constructor can be declared as private. This is often done to implement the Singleton design pattern,
where you want to ensure that only one instance of a class can be created. When the constructor is private, you prevent
external code from creating instances of the class directly.
**/

#include <iostream>

class Singleton {
 private:
  // Private constructor
  Singleton() { std::cout << "Singleton instance created." << std::endl; }

 public:
  // Deleted copy constructor and assignment operator
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  // Static method to get the instance of the class
  static Singleton& getInstance() {
    static Singleton instance;  // Guaranteed to be destroyed
    return instance;
  }
};

/**
In this example, the `Singleton` class has a private constructor,and the only way to access the instance is through
the `getInstance()` static method.This approach ensures that only one instance of the class is created.
**/
int main() {
  Singleton& instance = Singleton::getInstance();
  return 0;
}
