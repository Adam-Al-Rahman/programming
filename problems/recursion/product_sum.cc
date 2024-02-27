/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: Product Sum
 * @brief: write function that take input as "special" array and return it
 * product sum.
 * - A special array is a non-empty array that contains either
 * integers or other "special" arrays. The product sum of a "special" array is
 * the sum of its elements, where "special" arrays inside it are summed
 * themselves and then multiplied by their level of depth.
 * - The depth of a "special" array is how far nested it is. For instance, the
 * depth of [] is 1; the depth of the inner array is [[]] is 2; the depth of the
 * innermost array in [[[]]] is 3;
 * @source:
 * @tags: ["recursion", "vector"]
 * @status: solved
 */

#include <any>  // since c++17
#include <iostream>
#include <vector>

std::int32_t product_sum(const std::vector<std::any> &list,
                         std::int32_t index = 0, std::int32_t depth = 1,
                         std::int32_t sum = 0) {
  if (index >= list.size()) return sum;

  if (list[index].type() == typeid(std::int32_t)) {
    sum += std::any_cast<std::int32_t>(list[index]);
  }

  if (list[index].type() == typeid(std::vector<std::any>)) {
    depth++;
    sum +=
        (depth * product_sum(std::any_cast<std::vector<std::any>>(list[index]),
                             0, depth));
    depth--;
  }

  return product_sum(list, index + 1, depth, sum);
}

std::int32_t product_sum_iter(const std::vector<std::any> &list,
                              std::int32_t depth = 1) {
  std::int32_t sum = 0;

  for (std::any element : list) {
    if (element.type() == typeid(std::vector<std::any>)) {
      sum += product_sum_iter(std::any_cast<std::vector<std::any>>(element),
                              depth + 1);
    } else {
      sum += std::any_cast<std::int32_t>(element);
    }
  }
  return sum * depth;
}

int main() {
  std::vector<std::any> list = {
      5,
      2,
      std::vector<std::any>{7, -1},
      3,
      std::vector<std::any>{6, std::vector<std::any>{-13, 8}, 4},
  };

  std::cout << product_sum_iter(list);
}
