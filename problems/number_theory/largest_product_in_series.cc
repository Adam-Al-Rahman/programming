// Copyright 2024 Adam-Al-Rahman
// Q: https://projecteuler.net/problem=8

#include <cstdint>
#include <iostream>

std::uint64_t largest_product_series(const std::string& digits, std::uint64_t adj_digits) {
  std::uint64_t max_product = 0;
  std::uint64_t current_product = 1;
  int zero_count = 0;

  // Calculate the product of the first window
  for (std::uint64_t i = 0; i < adj_digits; ++i) {
    int digit = digits[i] - '0';
    if (digit == 0)
      zero_count++;
    else
      current_product *= digit;
  }

  // If no zeros in the first window, initialize max_product
  if (zero_count == 0) max_product = current_product;

  // Slide the window across the digits
  for (std::uint64_t i = adj_digits; i < digits.size(); ++i) {
    int digit_out = digits[i - adj_digits] - '0';
    int digit_in = digits[i] - '0';

    // Handle the outgoing digit
    if (digit_out != 0)
      current_product /= digit_out;
    else
      zero_count--;

    // Handle the incoming digit
    if (digit_in != 0)
      current_product *= digit_in;
    else
      zero_count++;

    // Update max_product if the current window has no zeros
    if (zero_count == 0 && current_product > max_product) max_product = current_product;
  }

  return max_product;
}

int main() {
  std::string digits =
      "73167176531330624919225119674426574742355349194934"
      "96983520312774506326239578318016984801869478851843"
      "85861560789112949495459501737958331952853208805511"
      "12540698747158523863050715693290963295227443043557"
      "66896648950445244523161731856403098711121722383113"
      "62229893423380308135336276614282806444486645238749"
      "30358907296290491560440772390713810515859307960866"
      "70172427121883998797908792274921901699720888093776"
      "65727333001053367881220235421809751254540594752243"
      "52584907711670556013604839586446706324415722155397"
      "53697817977846174064955149290862569321978468622482"
      "83972241375657056057490261407972968652414535100474"
      "82166370484403199890008895243450658541227588666881"
      "16427171479924442928230863465674813919123162824586"
      "17866458359124566529476545682848912883142607690042"
      "24219022671055626321111109370544217506941658960408"
      "07198403850962455444362981230987879927244284909188"
      "84580156166097919133875499200524063689912560717606"
      "05886116467109405077541002256983155200055935729725"
      "71636269561882670428252483600823257530420752963450";

  std::cout << largest_product_series(digits, 13) << std::endl;
}
