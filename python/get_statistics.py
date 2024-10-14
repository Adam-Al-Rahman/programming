"""
GET STATISTICS

Write a function that takes in a list of numbers and returns a dictionary containing the
following statistics about the numbers: the mean, median, mode, sample variance, sample
standard deviation, and 95% confidence interval for the mean.

Note that:
• You can assume that the given list contains a large-enough number of samples from a population to use a z-score of 1.96
• If there's more than one mode, your function can return any of them.
• You shouldn't use any libraries.
• Your output values will automatically be rounded to the fourth decimal.

python -m unittest file_name.py
"""

import unittest


import math
from collections import Counter


def get_statistics(data):
    # Sort the data in-place
    data.sort()
    n = len(data)

    # Calculate sum and mean
    data_sum = sum(data)
    mean = data_sum / n

    # Calculate median
    if n % 2 == 0:
        median = (data[n // 2 - 1] + data[n // 2]) / 2
    else:
        median = data[n // 2]

    # Calculate mode using Counter for efficiency
    data_counter = Counter(data)
    mode_data = data_counter.most_common(1)[0][0]  # Get the most frequent element

    # Calculate sample variance and standard deviation in one pass
    sum_of_squares = sum((x - mean) ** 2 for x in data)
    sample_variance = sum_of_squares / (n - 1)
    standard_deviation = math.sqrt(sample_variance)

    # Calculate confidence interval
    z = 1.96  # For a 95% confidence interval
    margin_of_error = (z * standard_deviation) / math.sqrt(n)
    confidence_interval = [mean - margin_of_error, mean + margin_of_error]

    # Return the statistics in a dictionary
    return {
        "mean": mean,
        "median": float(median),
        "mode": float(mode_data),
        "sample_variance": sample_variance,
        "sample_standard_deviation": standard_deviation,
        "mean_confidence_interval": confidence_interval,
    }


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        input = [2, 1, 3, 4, 4, 5, 6, 7]
        expected = {
            "mean": 4.0,
            "median": 4.0,
            "mode": 4.0,
            "sample_variance": 4.0,
            "sample_standard_deviation": 2.0,
            "mean_confidence_interval": [2.6141, 5.3859],
        }
        actual = get_statistics(input)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_2(self):
        input = [2, 3, 4, 5, 6, 7, 8, 8, 8, 1, 1, 1, 10, 10, 10, 11, 12, 12, 12]
        expected = {
            "mean": 6.8947,
            "median": 8.0,
            "mode": 1.0,
            "sample_variance": 15.7661,
            "sample_standard_deviation": 3.9707,
            "mean_confidence_interval": [5.1093, 8.6802],
        }
        actual = get_statistics(input)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_3(self):
        input = [0, 1]
        expected = {
            "mean": 0.5,
            "median": 0.5,
            "mode": 0.0,
            "sample_variance": 0.5000,
            "sample_standard_deviation": 0.7071,
            "mean_confidence_interval": [-0.48, 1.48],
        }
        actual = get_statistics(input)
        self.assertEqual(round_output_values(actual), expected)


def round_output_values(stats):
    if type(stats) is not dict:
        # Bad output; let tests fail.
        return stats

    new_output = {}
    for key in stats.keys():
        new_output[key] = stats[key]

        if type(stats[key]) is list:
            if len(stats[key]) >= 1:
                new_output[key][0] = round_to_4(stats[key][0])
            if len(stats[key]) >= 2:
                new_output[key][1] = round_to_4(stats[key][1])
        else:
            new_output[key] = round_to_4(stats[key])

    return new_output


def round_to_4(number):
    if not is_number(number):
        # Bad output; let tests fail.
        return number

    return round(number, 4)


def is_number(element):
    return type(element) in (int, float)
