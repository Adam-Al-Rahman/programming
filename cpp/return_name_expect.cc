

// return_type function_name expect_type
//
class ADD {
 private:
  int a;
  int b;

 public:
  int add(int a, int b) { return a + b; }
};

int main() {
  const ADD value = ADD();
  value.add(5, 5);
}
