#include <iostream>
#include <numeric>
#include <random>
#include <vector>

/**
_Problem Definition_
Suppose we want to simulate the number of emails received per hour.
We assume that the number of emails received follows a Poisson distribution
with an average rate (λ) of 5 emails per hour.
*/

int main() {
  // Parameters for the Poisson distribution
  const double lambda = 5.0;       // Average rate of emails per hour
  const int num_samples = 100000;  // Number of samples

  // Random number generator and Poisson distribution
  std::random_device rd;
  std::mt19937 gen(rd());
  std::poisson_distribution<> poisson_dist(lambda);

  // Vector to store the number of emails received in each sample
  std::vector<int> samples(num_samples);

  // Generate random samples
  for (int i = 0; i < num_samples; ++i) {
    samples[i] = poisson_dist(gen);
  }

  // Calculate the mean number of emails received
  double mean = std::accumulate(samples.begin(), samples.end(), 0.0) / num_samples;

  std::cout << "Estimated mean number of emails received per hour: " << mean << std::endl;

  return 0;
}
