#include <iostream>

void array_function(int array[]) {
  for (int i = 0; i < 10; i++)
    std::cout << array[i];
}

void multiple_dim() {
  const int rows{3};
  const int cols{4};

  int moving_rating[rows][cols]{};
}
