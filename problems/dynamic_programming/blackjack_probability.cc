// Copyright 2024 Adam-Al-Rahman

/**Question
In the game of Blackjack, the dealer must draw cards until the sum of the values of their cards is greater
than or equal toa target value minus 4. For example, traditional Blackjack uses a target value of 21,
so the dealer must draw cards until their total is greater than or equal to 17, at which point they stop
drawing cards (they "stand"). Ifthe dealer draws a card that brings their total above the target (above
21 in traditional Blackjack), they lose (they "bust").
Naturally, when a dealer is drawing cards, they can either end up standing or busting, and this is entirely
up to the luck of their draw.

Write a function that takes ina target value as well asa dealer's startingHand value and returns
the probability that the dealer will bust (go over the target value before standing). The target value
will always be a positive integer, and the startingHand value will always be a positive integer that's
smaller than or equal to the target value.

For simplicity, you can assume that the dealer has an infinite deck of cards and that each card has a value
between 1 and 10 inclusive. The likelihood of drawing a card of any value is always the same, regardless of
previous draws.

Your solution should be rounded to 3 decimal places and to the nearest value. For example, a probability
of 0.314159 would be rounded to 0.314 , while a probability of o. 1337 would be rounded to 0. 134 .
*/

#include <cmath>  // std::pow, std::round
#include <iostream>
#include <stack>
#include <tuple>
#include <unordered_map>

namespace px {
using node = std::tuple<int>;

float round_f(float value, int precision) {
  float scale = std::pow(10.0, precision);
  return std::round(value * scale) / scale;
}
}  // namespace px
//

float blackjackProbability(int target, int startingHand) {
  std::unordered_map<int, float> cache;

  std::stack<px::node> nodes;
  nodes.push(startingHand);

  while (!nodes.empty()) {
    auto [current] = nodes.top();

    if (cache.count(current)) {
      nodes.pop();
      continue;
    }

    if (current > target) {
      cache[current] = 1.0f;
      nodes.pop();
      continue;
    }

    if (current + 4 >= target) {
      cache[current] = 0.0f;
      nodes.pop();
      continue;
    }

    float total_probability = 0.0f;
    bool all_cached = true;

    for (int card = 1; card <= 10; ++card) {
      int next_hand = current + card;

      if (!cache.count(next_hand)) {
        nodes.push(next_hand);
        all_cached = false;
      } else {
        total_probability += (0.1f * cache[next_hand]);
      }
    }

    if (all_cached) {
      cache[current] = total_probability;
      nodes.pop();
    }
  }

  return px::round_f(cache[startingHand], 3);
}

int main() { std::cout << "Probability: " << blackjackProbability(21, 15) << std::endl; }
