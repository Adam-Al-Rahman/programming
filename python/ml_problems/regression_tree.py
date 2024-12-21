# Regression Tree

# Create a regression tree to predict the barrels per day (the "bpd ) produced by a particular drilling site,
# given some porosity, amma , somc , and density values.

# You'll have access to a list of training examples in the RegressionTree's root node, specifically in
# `RegressionTree.root.examples`. Each example is a dictionary with feature keys mapping to their
# respective values and with a "bpd". key mapping to the example's label.

# Note that:
# • You should use the mean squared error (MSE) as the splitting criteria.
# • You shouldn't evaluate "'bpd" as a feature to split on, since it's what you're trying to predict.
# • You shouldn't use any hyperparameters like max depth.
# • There's no need to handle missing data or to scale the features.
# • Recursive and iterative implementations are both fine.
# • You shouldn't use any libraries that implement regression trees for you, such as scikit-learn.
# • Your output values will automatically be rounded to the fourth decimal.


import unittest
import pickle
import os

_DATA_DIR = os.path.dirname(os.path.realpath(__file__)) + "/data"
with open(f"{_DATA_DIR}/drilling.pickle", "rb") as handle:
    examples = pickle.load(handle)


regression_tree = RegressionTree(examples)


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        features = {"porosity": 0.70, "gamma": 1.57, "sonic": 3666.90, "density": 2.52}
        expected = 143.0698
        actual = regression_tree.predict(features)
        self.assertEqual(round_to_4(actual), expected)

    def test_case_2(self):
        features = {
            "porosity": 0.5718721746302671,
            "gamma": 1.372854959321451,
            "sonic": 3538.467028856794,
            "density": 1.6920987581448308,
        }
        expected = 197.8710
        actual = regression_tree.predict(features)
        self.assertEqual(round_to_4(actual), expected)

    def test_case_3(self):
        features = {"porosity": 0.1, "gamma": 1.2, "sonic": 3538, "density": 1.6}
        expected = 187.8121
        actual = regression_tree.predict(features)
        self.assertEqual(round_to_4(actual), expected)

    def test_case_4(self):
        features = {"porosity": 0.4, "gamma": 1.9, "sonic": 2538, "density": 2.6}
        expected = 389.3450
        actual = regression_tree.predict(features)
        self.assertEqual(round_to_4(actual), expected)

    def test_case_5(self):
        features = {"porosity": 0.65, "gamma": 1.7, "sonic": 4021, "density": 2.2}
        expected = 139.7479
        actual = regression_tree.predict(features)
        self.assertEqual(round_to_4(actual), expected)

    def test_case_6(self):
        features = {"porosity": 0.82, "gamma": 2.1, "sonic": 1710, "density": 0.9}
        expected = 816.9979
        actual = regression_tree.predict(features)
        self.assertEqual(round_to_4(actual), expected)


def round_to_4(number):
    if not is_number(number):
        # Bad output; let tests fail.
        return number

    return round(number, 4)


def is_number(element):
    return type(element) in (int, float)
