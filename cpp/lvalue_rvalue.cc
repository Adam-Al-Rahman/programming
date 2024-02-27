/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */
#include <iostream>
#include <string>

// LVALUE | RVALUE

// Lvalue, we can only assign anything to lvalue but not to rvalue

// An lvalue is an expression that represents an object in memory, typically
// something that has a name and occupies storage.

// A function can return an lvalue by returning a reference to an object.
int &return_lvalue() {  // or &return_ref
  static int data = 7;  // Creating a static object to ensure it persists beyond
                        // the function scope
  // `data variable` In terms of scope:

  // Lifetime: The data variable has static lifetime, meaning it exists
  // throughout the entire execution of the program.

  // Visibility: The scope of the data variable is limited to the return_lvalue
  // function. It cannot be accessed directly from outside this function.

  return data;
}

// lvalue parameter (use &)
void print_name(const std::string &name) { std::cout << name << std::endl; }

// rvalue parameter (use &&)
void print_age(std::string &&name) { std::cout << name << std::endl; }

int main() {
  // lvalue = rvalue
  int i = 10;

  // lvalue = lvalue
  int a = i;

  // Lvalue from function
  int &lvalueRef = return_lvalue();

  // magic of lvalue
  // this only possible if function returns a lvalue reference
  return_lvalue() = 10;

  // NOTE: lvalue ref only accepts lvalue except for const
  // initial value of reference to non-const must be an lvalue
  // this not possible but when we make is a constant it works
  // int &value = 10;
  const int &value = 10;  // after making it const the lvalue ref can be
                          // assigned a rvalue;

  std::string first_name = "Guido";
  std::string last_name = "Rossum";

  //          lvalue   =  rvalue (because `+ operator` will concatenate them and
  //          return a rvalue)
  std::string full_name = first_name + last_name;
  print_name(full_name);
  // print_name(first_name + last_name); // not possible because `first_name +
  // last_name` give rvalue but lvalue ref should assign lvalue or make it const
  // at functional void print_name(const std::string &name)

  print_age(first_name + last_name);
}

// NOTE: lvalue and rvalue references properties are used in `move semantics`
