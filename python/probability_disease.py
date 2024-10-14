"""
Probability of Disease

A test indicating the presence of disease in cats is 95% accurate in terms of both sensitivity and specificity.
The prevalence of the disease is 3% which means only 3% of known cats have the disease. If your cat tests
positive (negative) for the disease, whats the probability that your cat has (doesnt have) the disease?

Write a program which takes in the accuracy of a test as well as the percent of a population which has the
disease and returns a list containing:
• Firstly, the probability that an individual has the disease given a positive test result.
• Secondly, the probability that an individual does not have the disease given a negative test result.

Note that:
• You can assume the sensitivity and specificity are equal to the accuracy
• You shouldn't use any libraries.
• Your output values will automatically be rounded to the fourth decimal.
"""

import unittest


def probability_of_disease(accuracy, prevalence):
    return []


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        accuracy = 0.95
        prevalence = 0.03
        expected = [37.013, 99.8375]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_2(self):
        accuracy = 1
        prevalence = 0.01
        expected = [100, 100]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_3(self):
        accuracy = 0.9
        prevalence = 0.05
        expected = [32.1429, 99.4186]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_4(self):
        accuracy = 0.85
        prevalence = 0.1
        expected = [38.6364, 98.0769]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_5(self):
        accuracy = 0.8
        prevalence = 0.15
        expected = [41.3793, 95.7746]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_6(self):
        accuracy = 0.75
        prevalence = 0.2
        expected = [42.8571, 92.3077]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_7(self):
        accuracy = 0.7
        prevalence = 0.25
        expected = [43.75, 87.5]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_8(self):
        accuracy = 0.65
        prevalence = 0.3
        expected = [44.3182, 81.25]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_9(self):
        accuracy = 0.6
        prevalence = 0.35
        expected = [44.6809, 73.5849]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_10(self):
        accuracy = 0.55
        prevalence = 0.4
        expected = [44.898, 64.7059]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_11(self):
        accuracy = 0.5
        prevalence = 0.45
        expected = [45, 55]
        actual = probability_of_disease(accuracy, prevalence)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_12(self):
        accuracy = 0.45
        prevalence = 0.5
        expected = [45, 45]
        actual = probability_of_disease(accuracy, prevalence)
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
