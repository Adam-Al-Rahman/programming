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
