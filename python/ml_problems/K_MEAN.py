# K - MEAN

# Use the k-means algorithm to return the k means (or centroids) for the provided user features.
#
# These user features are the result of a dimensionality reduction by PCA on some user-app interaction
# data. You'll have access to a LÜSERLÉEAXURELMAP) dictionary, mapping each user "uid_i " to a
# respective list of 4 features associated with the user in question.

# Note that:
# • The initial centroid locations are selected for you to ensure consistency when verifying your solution.
# • You should execute at least 10 iterations of the k-means algorithm, not including the initialization of  the centroids.
# • You should use the Manhattan distance as the distance metric.
# • You shouldn't use any libraries that implement k-means for you.
# • Your output values will automatically be rounded to the fourth decimal.

import unittest

import math
import numpy as np
import os
import pickle
import random

_DATA_DIR = os.path.dirname(os.path.realpath(__file__)) + "/data"


def get_feature_map():
    with open(f"{_DATA_DIR}/kmeans.pickle", "rb") as handle:
        return pickle.load(handle)


class Centroid:
    def __init__(self, location):
        self.location = location
        self.closest_users = set()


def get_manhattan_distance(features, other_features):
    absolute_differences = []
    for i in range(len(features)):
        absolute_differences.append(abs(features[i] - other_features[i]))
    return sum(absolute_differences)


def get_centroid_average(centroid, user_feature_map, num_features_per_user):
    centroid_average = [0] * num_features_per_user

    for i in range(num_features_per_user):
        for user in centroid.closest_users:
            centroid_average[i] = centroid_average[i] + user_feature_map[user][i]

    return [
        centroid_dimension / len(centroid.closest_users)
        for centroid_dimension in centroid_average
    ]


def get_k_means(user_feature_map, num_features_per_user, k):
    # Don't change the following two lines of code.
    random.seed(42)
    # Gets the initial users, to be used as centroids.
    initial_centroid_users = random.sample(sorted(list(user_feature_map.keys())), k)

    centroids = [
        Centroid(user_feature_map[initial_centroid_user])
        for initial_centroid_user in initial_centroid_users
    ]
    for _ in range(10):
        for uid, features in user_feature_map.items():
            closest_centroid_distance = float("inf")
            closest_centroid = None

            for centroid in centroids:
                features_to_centroid_distance = get_manhattan_distance(
                    features, centroid.location
                )
                if features_to_centroid_distance < closest_centroid_distance:
                    closest_centroid_distance = features_to_centroid_distance
                    closest_centroid = centroid
            closest_centroid.closest_users.add(uid)

        for centroid in centroids:
            centroid.location = get_centroid_average(
                centroid, user_feature_map, num_features_per_user
            )
            centroid.closest_users.clear()
    return [centroid.location for centroid in centroids]


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        k = 1
        actual = get_k_means(get_feature_map(), 4, k)
        expected = [[-1.0659, -1.0981, -1.0667, -1.0846]]
        self.assertEqual(round_output_values(actual), expected)

    def test_case_2(self):
        k = 2
        actual = get_k_means(get_feature_map(), 4, k)
        expected = [
            [0.3109, 0.3282, 0.3325, 0.3437],
            [-1.479, -1.526, -1.4864, -1.5131],
        ]
        self.assertEqual(round_output_values(actual), expected)

    def test_case_3(self):
        k = 3
        actual = get_k_means(get_feature_map(), 4, k)
        expected = [
            [0.3109, 0.3282, 0.3325, 0.3437],
            [-1.1271, -1.6013, -1.4669, -1.5284],
            [-1.7739, -1.4629, -1.5028, -1.5004],
        ]
        self.assertEqual(round_output_values(actual), expected)

    def test_case_4(self):
        k = 4
        actual = get_k_means(get_feature_map(), 4, k)
        expected = [
            [-1.2694, -1.5202, -1.1358, -1.5602],
            [-1.2249, -1.6868, -1.8245, -1.3984],
            [-1.8371, -1.4109, -1.5173, -1.5607],
            [0.3109, 0.3282, 0.3325, 0.3437],
        ]
        self.assertEqual(round_output_values(actual), expected)

    def test_case_5(self):
        k = 5
        actual = get_k_means(get_feature_map(), 4, k)
        expected = [
            [-1.1544, -1.4444, -1.1587, -1.6412],
            [-1.251, -1.7981, -1.7665, -1.3378],
            [-1.6647, -1.2963, -1.8271, -1.6676],
            [0.3109, 0.3282, 0.3325, 0.3437],
            [-1.8224, -1.5567, -1.1926, -1.4176],
        ]
        self.assertEqual(round_output_values(actual), expected)


def round_output_values(centroids):
    if type(centroids) is not list:
        # Bad output; let tests fail.
        return centroids

    return [[round_to_4(x) for x in centroid] for centroid in centroids]


def round_to_4(number):
    if not is_number(number):
        # Bad output; let tests fail.
        return number

    return round(number, 4)


def is_number(element):
    return type(element) in (int, float, np.float64)
