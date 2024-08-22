#include <iostream>

class Foo {
 private:
  int* xptr;

 public:
  Foo() {
    xptr = new int;
    *xptr = 0;
  }

  // copy constructor is just another way of constructor overload with parameter as its own class type
  // what to do when passed same class type variable
  Foo(const Foo& p) {  // copy constructor, exectures instead of the default
    xptr = new int;
    *xptr = p.get();
  }

  void set(int i) { *xptr = i; }
  int get() const { return *xptr; }
};

int main() {
  Foo f;
  f.set(88);

  //  Iinitialize g and h with f
  //  memberwise assignment g.x = f.x;
  //
  //  Method 1: Copy initialization (shorthand)
  Foo g = f;  // This line invokes the copy constructor

  // Method 2: Explicitly invoking the copy constructor
  Foo h(f);  // This line explicitly calls the copy constructor

  std::cout << g.get() << std::endl;
  g.set(33);

  std::cout << g.get() << ", " << f.get() << std::endl;
}

/**
The line `BinaryTree(const BinaryTree& other) = delete;` in your `BinaryTree` class definition explicitly deletes
the copy constructor. Here’s what it does and why you might want to use it:

### Explanation:

1. **Copy Constructor:**
   - A copy constructor is a special constructor in C++ that initializes a new object as a copy of an existing object.
It has the following signature:
     ```cpp
     BinaryTree(const BinaryTree& other);
     ```
   - This constructor is invoked when you pass an object by value, return an object by value, or explicitly create a
copy using syntax like `BinaryTree newTree = existingTree;`.

2. **`= delete;`:**
   - The `= delete;` syntax tells the compiler that this function is explicitly deleted. It means you are intentionally
disallowing the use of the copy constructor.
   - If someone tries to copy a `BinaryTree` object, the compiler will throw an error, preventing the operation.

### Why Delete the Copy Constructor?

1. **Avoiding Shallow Copies:**
   - The `BinaryTree` class uses raw pointers (`BinaryTree* left` and `BinaryTree* right`) to manage child nodes. If the
copy constructor is used, it would perform a shallow copy of these pointers.
   - A shallow copy means both the original and the copied `BinaryTree` objects would point to the same child nodes,
leading to issues like double deletion when both objects are destroyed, or unintended modifications when one tree's
structure is changed.

2. **Preventing Incorrect Usage:**
   - By deleting the copy constructor, you avoid potential bugs that arise from copying tree structures. It forces the
user to think about how the tree should be copied or prevents copying altogether, which is often desirable for data
structures involving dynamic memory.

3. **Explicit Control:**
   - In many cases, tree structures are meant to be unique and should not be duplicated without careful consideration.
Deleting the copy constructor provides explicit control over how objects of the `BinaryTree` class are managed.

### When Would You Use This?

- **Custom Memory Management:**
  If you have custom memory management in your class or want to ensure that a tree is unique and not accidentally
duplicated, deleting the copy constructor is a good practice.

- **Performance Considerations:**
  In some cases, copying large tree structures can be expensive. By deleting the copy constructor, you avoid accidental
performance hits.

### Example:

```cpp
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  explicit BinaryTree(int value) : value(value) {}

  // Delete the copy constructor
  BinaryTree(const BinaryTree& other) = delete;

  // Optional: Define move constructor and move assignment operator
  BinaryTree(BinaryTree&& other) = default;
  BinaryTree& operator=(BinaryTree&& other) = default;
};
```

In this example, if someone tries to copy a `BinaryTree` object like this:

```cpp
BinaryTree tree1(10);
BinaryTree tree2 = tree1;  // Error: Copy constructor is deleted
```

The compiler will generate an error, preventing shallow copies and the potential issues they bring.
*/
