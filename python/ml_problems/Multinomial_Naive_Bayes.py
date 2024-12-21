# Multinomial Naive Bayes

# Create a multinomial Naive Bayes classifier to add tags to articles, where tags represent categories that
# articles should belong to.

# You'll have access to training articles inside ofa dictionary MultinomialNB.articles_per_tag
# mapping tags to the articles belonging to said tags.

# Note that:
# • The Laplacian smoothing hyperparameter has been chosen to be 1 , which means that when
#    calculating likelihoods, you'll be adding to the denominator and the numerator.
# • If an input to the model contains a word that is not in the trained Naive Bayes model, that word
# should be assigned a class probability of 50%.
# • You shouldn't use use TF-IDF.
# • You shouldn't use any libraries that implement the multinomial Naive Bayes classifier for you,
# such as scikit-learn.
# • You're encouraged to use the collections module as well as the cyna!h, module.
# • Your output values will automatically be rounded to the fourth decimal.

import unittest
from collections import defaultdict
import math

import os
import pickle


_DATA_DIR = os.path.dirname(os.path.realpath(__file__)) + "/data"

with open(f"{_DATA_DIR}/articles_decimated.pickle", "rb") as handle:
    examples = pickle.load(handle)


class MultinomialNB:
    def __init__(self, articles_per_tag):
        self.alpha = 1
        self.priors_per_tag = {}
        self.likelihood_per_word_per_tag = {}
        self.articles_per_tag = articles_per_tag  # See question prompt for details.
        self.tags = articles_per_tag.keys()
        self.train()

    def train(self):
        tag_counts_map = {tag: len(self.articles_per_tag[tag]) for tag in self.tags}
        self.priors_per_tag = {
            tag: tag_counts_map[tag] / sum(tag_counts_map.values()) for tag in self.tags
        }
        self.likelihood_per_word_per_tag = self.__get_word_likelihoods_per_tag()

    def predict(self, article):
        posteriors_per_tag = {
            tag: math.log(prior) for tag, prior in self.priors_per_tag.items()
        }
        for word in article:
            for tag in self.tags:
                posteriors_per_tag[tag] = posteriors_per_tag[tag] + math.log(
                    self.likelihood_per_word_per_tag[word][tag]
                )

        return posteriors_per_tag

    def __get_word_likelihoods_per_tag(self):
        word_frequencies_per_tag = defaultdict(lambda: {tag: 0 for tag in self.tags})
        total_word_count_per_tag = defaultdict(int)

        for tag in self.tags:
            for article in self.articles_per_tag[tag]:
                for word in article:
                    word_frequencies_per_tag[word][tag] += 1
                    total_word_count_per_tag[tag] += 1
        word_likelihoods_per_tag = defaultdict(lambda: {tag: 0.5 for tag in self.tags})

        for word, tags_map in word_frequencies_per_tag.items():
            for tag in tags_map.keys():
                word_likelihoods_per_tag[word][tag] = (
                    word_frequencies_per_tag[word][tag] + 1 * self.alpha
                ) / (total_word_count_per_tag[tag] + 2 * self.alpha)

        return word_likelihoods_per_tag


multinomial_nb = MultinomialNB(examples)


class TestProgram(unittest.TestCase):
    def test_case_1(self):
        article = [
            "article",
            "writes",
            "while",
            "when",
            "owned",
            "Plus",
            "wanted",
            "upgrade",
            "memory",
            "just",
            "ordered",
            "toolkit",
            "from",
            "Macwarehouse",
            "something",
            "like",
            "included",
            "antistatic",
        ]
        expected = {"politics": -91.3016, "sports": -87.1427, "tech": -85.1920}
        actual = multinomial_nb.predict(article)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_2(self):
        article = ["Went", "Dodgers", "game", "tonight", "night", "Astacio", "pitched"]
        expected = {"politics": -18.6497, "sports": -16.9614, "tech": -19.0964}
        actual = multinomial_nb.predict(article)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_3(self):
        article = [
            "motives",
            "were",
            "twofold",
            "deeply",
            "held",
            "democratic",
            "convictions",
            "gave",
            "sense",
            "duty",
            "felt",
            "obliged",
            "shed",
            "light",
            "this",
        ]
        expected = {"politics": -41.8873, "sports": -41.6120, "tech": -40.5663}
        actual = multinomial_nb.predict(article)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_4(self):
        article = [
            "CDROMs",
            "with",
            "SCSIInterface",
            "known",
            "much",
            "they",
            "present",
            "market",
            "Please",
            "mail",
            "direcktly",
            "reguarly",
            "reading",
            "group",
        ]
        expected = {"politics": -66.1408, "sports": -63.3422, "tech": -61.7544}
        actual = multinomial_nb.predict(article)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_5(self):
        article = [
            "wall",
            "behind",
            "goals",
            "essentially",
            "outdoor",
            "arena",
            "Colognes",
            "arena",
            "only",
            "seats",
            "about",
            "70008000",
            "Berlin",
            "about",
            "6000",
        ]
        expected = {"politics": -54.4575, "sports": -52.0613, "tech": -52.1966}
        actual = multinomial_nb.predict(article)
        self.assertEqual(round_output_values(actual), expected)

    def test_case_6(self):
        article = [
            "speak",
            "anyone",
            "connected",
            "highres",
            "fixed",
            "frequency",
            "monitor",
            "their",
            "have",
            "mitubishi",
            "monitor",
            "that",
            "does",
            "1024x768",
            "60hz",
        ]
        expected = {"politics": -53.7736, "sports": -56.4307, "tech": -55.2141}
        actual = multinomial_nb.predict(article)
        self.assertEqual(round_output_values(actual), expected)


def round_output_values(output):
    if type(output) is not dict:
        # Bad output; let tests fail.
        return output

    new_output = {}
    for key in output.keys():
        new_output[key] = round_to_4(output[key])

    return new_output


def round_to_4(number):
    if not is_number(number):
        # Bad output; let tests fail.
        return number

    return round(number, 4)


def is_number(element):
    return type(element) in (int, float)
