#include <iostream>

const void mixed_type_expx() {
  int total{};
  int num_1{}, num_2{}, num_3{};
  const int count{3};

  std::cout << "Enter III integers: ";
  std::cin >> num_1 >> num_2 >> num_3;

  total = num_1 + num_2 + num_3;

  double average{0.0};

  average = static_cast<double>(total) / count;
  // average = (double)total/count ***This is OLD-STYLE***

  std::cout << "Average ([" << num_1 << " " << num_2 << " " << num_3
            << "]): " << average;
}

const void static_casting_to_int() {
  int rating{3};
  double star{4.0};

  double rating_star = rating / star;

  std::cout << rating_star;
}
