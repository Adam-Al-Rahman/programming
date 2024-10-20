"""
Distance And Similarities

Write a series of functions that take in two lists, X=x_l ... x n and Y = y_l ... and return a list
containing:
Firstly, the Euclidean distance between X and Y.
Secondly, the Manhattan distance between X and Y.
Thirdly, the Cosine similarity of X and Y.
Finally, the Jaccard similarity of X and Y.

Note that:
You shouldn't use any libraries.
Your output values will automatically be rounded to the fourth decimal.
X and Y will consist of positive integers up to 1000.
X and Y will have cardinalities between 1 and 10 inclusive.
"""

import unittest
import math


class Metrics:
    def euclidean_distance(self, X, Y):
        sum_of_squares = sum(math.pow(x - y, 2) for x, y in zip(X, Y))
        return math.sqrt(sum_of_squares)

    def manhattan_distance(self, X, Y):
        return sum(abs(x - y) for x, y in zip(X, Y))

    def cosine_similarity(self, X, Y):
        dot_product = sum(x * y for x, y in zip(X, Y))
        norm_x = math.sqrt(sum(x**2 for x in X))
        norm_y = math.sqrt(sum(y**2 for y in Y))

        return dot_product / (norm_x * norm_y) if norm_x and norm_y else 0.0

    def jaccard_similarity(self, X, Y):
        insertion_cardinality = len(set.intersection(*[set(X), set(Y)]))
        union_cardinality = len(set.union(*[set(X), set(Y)]))

        return (
            insertion_cardinality / float(union_cardinality)
            if union_cardinality
            else 0.0
        )


def distances_and_similarities(X, Y):
    metrics = Metrics()
    return [
        metrics.euclidean_distance(X, Y),
        metrics.manhattan_distance(X, Y),
        metrics.cosine_similarity(X, Y),
        metrics.jaccard_similarity(X, Y),
    ]


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        X = [1, 3, 4, 5]
        Y = [7, 6, 3, 1]
        expected = [7.874, 14, 0.6034, 0.3333]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_2(self):
        X = [1, 1, 2, 5, 6]
        Y = [1, 2, 3, 5, 7, 9]
        expected = [1.7321, 3, 0.7142, 0.4286]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_3(self):
        X = [111, 367, 414, 144, 143, 123, 232, 132]
        Y = [211, 267, 314, 244, 43, 223, 132, 232]
        expected = [282.8427, 800, 0.9066, 0.1429]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_4(self):
        X = [1]
        Y = [1]
        expected = [0.0, 0, 1.0, 1.0]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_5(self):
        X = [1, 1]
        Y = [1, 1]
        expected = [0.0, 0, 1.0, 1.0]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_6(self):
        X = [1, 1, 1]
        Y = [1, 1, 1]
        expected = [0.0, 0, 1.0, 1.0]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_7(self):
        X = [1, 2, 3]
        Y = [3, 2, 1]
        expected = [2.8284, 4, 0.7143, 1.0]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_8(self):
        X = [10, 100, 1000]
        Y = [1, 10, 100]
        expected = [904.5336, 999, 1.0, 0.5]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_9(self):
        X = [12, 15, 27, 88, 11, 34, 24]
        Y = [7, 6, 3, -1]
        expected = [92.7524, 127, 0.1657, 0.0]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_10(self):
        X = [3, 5, 4, 1]
        Y = [6, 7, 3, 1]
        expected = [3.7417, 6, 0.9482, 0.3333]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_11(self):
        X = [1, 1]
        Y = [1]
        expected = [0.0, 0, 0.7071, 1.0]
        actual = distances_and_similarities(X, Y)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_12(self):
        X = [2]
        Y = [2, 2]
        expected = [0.0, 0, 0.7071, 1.0]
        actual = distances_and_similarities(X, Y)
        print(f"____>>>: {actual}")
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
