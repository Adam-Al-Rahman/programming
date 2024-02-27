#include <iostream>

/**
 * @brief Naive method
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        C[i][j] = A[i][k] * B[k][j];
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << C[i][j] << " ";
    }
    std::cout << "\n";
  }
 */

int DC_MATMUL(int A[][], int B[][], int n) {
  if (n == 2) {
  }
};

int main() {
  int A[4][4] = {{0, 0, 3, 4}, {5, 6, 0, 0}, {0, 0, 6, 5}, {4, 3, 0, 0}};
  int B[4][4] = {{0, 0, 6, 5}, {4, 3, 0, 0}, {0, 0, 3, 4}, {5, 6, 0, 0}};
  int C[4][4];
}
