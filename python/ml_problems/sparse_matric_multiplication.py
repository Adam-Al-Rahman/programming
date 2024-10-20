"""
Sparse Matrix Multiplication:
Write a function that takes in two integer matrices and multiplies them together.
Both matrices will be sparse, meaning that most of their elements will be zero. Take advantage
of that to reduce the number of total computations that your function performs.
If the matrices can't be multiplied together, your function should return `[[]]`

Run: python -m unittest file_name.py
"""

import unittest


def sparse_matrix_multiplication(matrix_a, matrix_b):
    # Ensure matrix_a columns equal matrix_b rows for valid multiplication
    rows_a, cols_a = len(matrix_a), len(matrix_a[0])
    rows_b, cols_b = len(matrix_b), len(matrix_b[0])

    if cols_a != rows_b:
        return [[]]

    # Initialize result matrix with zeroes
    result: list[list[int]] = [[0 for _ in range(cols_b)] for _ in range(rows_a)]

    # Sparse matrix multiplication
    for i in range(rows_a):
        for k in range(cols_a):
            if matrix_a[i][k] != 0:  # Skip zeros in matrix_a (sparse)
                for j in range(cols_b):
                    if matrix_b[k][j] != 0:  # Skip zeros in matrix_b (sparse)
                        result[i][j] += matrix_a[i][k] * matrix_b[k][j]

    return result


# Conecpt: Dictionary of keys
def get_dict_nonzero_cells(matrix) -> dict:
    dict_nonzero_cells = {}
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] != 0:
                dict_nonzero_cells[(i, j)] = matrix[i][j]

    return dict_nonzero_cells


def sparse_matrix_multiplication_optim(matrix_a, matrix_b):
    # Ensure matrix_a columns equal matrix_b rows for valid multiplication
    rows_a, cols_a = len(matrix_a), len(matrix_a[0])
    rows_b, cols_b = len(matrix_b), len(matrix_b[0])

    if cols_a != rows_b:
        return [[]]

    sparse_a = get_dict_nonzero_cells(matrix_a)
    sparse_b = get_dict_nonzero_cells(matrix_b)

    # Initialize result matrix with zeroes
    result: list[list[int]] = [[0] * cols_b for _ in range(rows_a)]

    for i, k in sparse_a.keys():
        for j in range(cols_b):
            if (k, j) in sparse_b.keys():
                result[i][j] += sparse_a[(i, k)] * sparse_b[(k, j)]

    return result


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        matrix_a = [
            [0, 2, 0],
            [0, -3, 5],
        ]
        matrix_b = [
            [0, 10, 0],
            [0, 0, 0],
            [0, 0, 4],
        ]
        expected = [
            [0, 0, 0],
            [0, 0, 20],
        ]
        actual = sparse_matrix_multiplication_optim(matrix_a, matrix_b)
        self.assertEqual(actual, expected)

    def test_case_2(self):
        matrix_a = [
            [46, 0, 0],
            [45, 47, 0],
            [0, 0, 0],
            [34, 0, 25],
            [0, 2, 0],
            [0, 0, 0],
        ]
        matrix_b = [
            [26, 34, 20, 31, 34, 15],
            [38, 30, 23, 1, 45, 22],
            [47, 9, 9, 5, 9, 31],
        ]
        expected = [
            [1196, 1564, 920, 1426, 1564, 690],
            [2956, 2940, 1981, 1442, 3645, 1709],
            [0, 0, 0, 0, 0, 0],
            [2059, 1381, 905, 1179, 1381, 1285],
            [76, 60, 46, 2, 90, 44],
            [0, 0, 0, 0, 0, 0],
        ]
        actual = sparse_matrix_multiplication_optim(matrix_a, matrix_b)
        self.assertEqual(actual, expected)

    def test_case_3(self):
        matrix_a = [
            [0, 0, 1],
            [1, 0, 2],
            [0, 0, 1],
        ]
        matrix_b = [
            [0, 1, 0],
            [1, 1, 0],
            [0, 1, 0],
        ]
        expected = [
            [0, 1, 0],
            [0, 3, 0],
            [0, 1, 0],
        ]
        actual = sparse_matrix_multiplication_optim(matrix_a, matrix_b)
        self.assertEqual(actual, expected)
