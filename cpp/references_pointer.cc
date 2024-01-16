#include <iostream>

/*
In C++, references are designed to provide a convenient and safe way to alias
existing objects. They are meant to act as an alternative name for an already
existing object and are particularly useful in function parameter passing.
However, references have certain characteristics that make them unsuitable for
dynamic memory allocation scenarios:

1. **Cannot be Reassigned:** Once a reference is initialized to refer to an
object, it cannot be reassigned to refer to a different object. This
immutability makes references unsuitable for scenarios where you might need to
change the object being referred to, such as reallocating memory.

    ```cpp
    int x = 5;
    int& ref = x;
    ref = 10;  // Fine, changes the value of x
    // ref = new int;  // Error: references cannot be reassigned to a new object
    ```

2. **No Null References:** References must always refer to a valid object; they
cannot be null. This makes them unsuitable for scenarios where you need to
represent the absence of an object, such as when handling dynamic memory
allocation where allocation can fail.

    ```cpp
    int* ptr = new int;
    int& ref = *ptr;  // Fine, ref now refers to the allocated memory
    // int& invalidRef = nullptr;  // Error: references cannot be null
    ```

Dynamic memory allocation in C++ typically involves using pointers with `new`
and `delete` or, preferably, using smart pointers like `std::unique_ptr` and
`std::shared_ptr` to manage memory automatically.

```cpp
int* dynamicInt = new int;  // Dynamic memory allocation using a pointer
std::unique_ptr<int> dynamicIntPtr = std::make_unique<int>();  // Dynamic memory
allocation using std::unique_ptr
```

These dynamic memory allocation methods provide more flexibility, the ability to
reassign, and the ability to represent null pointers when necessary. References,
due to their nature, are not well-suited for managing dynamic memory allocation
and are primarily intended for aliasing existing objects in a safer and more
convenient way.
*/

int return_val(int *a) {
  *a = *a + 5;
  return *a;
}

int *return_ptr(int *a) {
  *a = *a + 5;
  return a;
}

int main() {
  int a = 5;
  int &b = a;
  int *c = &a;

  int *d = new int;
  *d = 5;

  std::cout << &a << " " << &b << " " << c << std::endl;
  std::cout << a << b << *c << *d << std::endl;
}
