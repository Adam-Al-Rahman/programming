"""
Repeating Heads

You're considering a $100 bet with your friend. If `n` consecutive fair coin flips result in all heads, then you
win - else your friend wins. Your friend agrees to let you attempt the bet as many times as you'd like.
Assuming you attempt the bet `x` times, what's the probability that you'll win the bet at least once? As well,
what should your winning payout ($100, $200, etc) be to ensure that you at least break even given
unlimited attempts of the bet?

Write a function which takes in the number of consecutive coin flips (n) and the number of bet attempts (x)
and returns a list containing:
• Firstly, the probability that you win the bet at least once
• Secondly, your required winning payout

Note that:
• You can assume a fair coin.
• You shouldn't use any libraries.
• Your output values will automatically be rounded to the fourth decimal.
"""

import unittest


def repeating_heads(n, x):
    bet_size = 100
    head_chance = 1 / 2
    trial_win_chance = head_chance**n
    trial_lose_chance = 1 - trial_win_chance
    repeated_trial_lose_chance = trial_lose_chance**x
    repeated_trial_win_chance = 1 - repeated_trial_lose_chance
    break_even_point = bet_size / repeated_trial_win_chance
    return [repeated_trial_win_chance * 100, break_even_point]


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        n = 3
        x = 10
        expected = [73.6924, 135.6991]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_2(self):
        n = 0
        x = 5
        expected = [100.0, 100.0]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_3(self):
        n = 1
        x = 12
        expected = [99.9756, 100.0244]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_4(self):
        n = 2
        x = 18
        expected = [99.4362, 100.567]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_5(self):
        n = 4
        x = 30
        expected = [85.5743, 116.8576]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_6(self):
        n = 5
        x = 52
        expected = [80.8129, 123.7426]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_7(self):
        n = 6
        x = 77
        expected = [70.2584, 142.3317]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_8(self):
        n = 7
        x = 87
        expected = [49.4575, 202.1936]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_9(self):
        n = 8
        x = 92
        expected = [30.2379, 330.7112]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_10(self):
        n = 9
        x = 98
        expected = [17.4358, 573.5342]
        actual = repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_11(self):
        n = 10
        x = 100
        expected = [9.3083, 1074.314]
        actual = program.repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_12(self):
        n = 10
        x = 1
        expected = [0.0977, 102400.0]
        actual = program.repeating_heads(n, x)
        self.assertEqual(round_output_values(actual), expected)


def round_output_values(results):
    if type(results) is not list:
        # Bad output; let tests fail.
        return results
    return [round_to_4(result) for result in results]


def round_to_4(number):
    if not is_number(number):
        # Bad output; let tests fail.
        return number

    return round(number, 4)


def is_number(element):
    return type(element) in (int, float)
