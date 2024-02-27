/*
vector: A dynamic array
-----------------------

- Size change dynamically.
- Elements are all the same types.
- Stored contiguously in memory.
- Individual elements can be accessed by their position or index.

- [ ]: this bracket does not check to see if you are out of bounds, while
accessign the elements.
- Provides many useful function that do bounds check.

- Elements initialized to zero.
- Very efficient.
- iteration (looping) is often used to process.

What if you are out of bounds?
- Array never do bounds checking.
- Many vector methods provides bounds checking.
- An exception and error message is generated.


// Example:

vector <int> test_scores (3) // this means a vector named test_scores
initialized with 3 zeros.

*/

#include <iostream>
#include <vector>

void vectorX() {
  std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
  std::vector<int> test_scores{100, 98, 89, 85, 93};
  std::vector<double> hi_temperatures(
      365, 80.8);  // (size_of_vector, initialize_value_for_all_element)
  std::cout << "First vowel: " << vowels.at(0)
            << std::endl;  // at is used to accessing elements at a index
  test_scores.push_back(80);
  test_scores.push_back(90);
  std::cout << test_scores.size() << std::endl;

  // 2D vector
  std::vector<std::vector<int>> movie_ratings{{1, 2, 3}, {2, 3, 5}, {4, 5, 2}};

  std::cout << movie_ratings[0][0] << std::endl;
  std::cout << movie_ratings.at(0).at(1) << std::endl;
}

void vector_prog() {
  std::vector<int> vector_1;
  std::vector<int> vector_2;

  vector_1.push_back(10);
  vector_1.push_back(20);

  vector_2.push_back(100);
  vector_2.push_back(200);

  // std::cout << vector_1.at(0) << " " << vector_1.at(1);

  std::vector<std::vector<int>> vector_2d;
  vector_2d.push_back(vector_1);
  vector_2d.push_back(vector_2);

  for (int i = 0; i < vector_2d.size(); i++) {
    for (int j = 0; j < vector_2d[i].size(); j++) {
      std::cout << vector_2d[i][j] << std::endl;
    }
  }

  vector_1[0] = 1000;
  for (int i = 0; i < vector_1.size(); i++) {
    std::cout << vector_1[i] << " " << std::endl;
  }
}
