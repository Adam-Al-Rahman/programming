/**
 * Copyright 2024 Adam-Al-Rahman
 */

#include <cmath>
#include <iostream>
#include <random>

double estimate_pi(int num_samples) {
  int inside_circle = 0;

  // Random number generator and Gaussian distribution
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> gaussian_dist(0.0, 1.0);  // mean = 0, stddev = 1

  for (int i = 0; i < num_samples; ++i) {
    // Generate random point (x, y) using Gaussian distribution
    double x = gaussian_dist(gen);
    double y = gaussian_dist(gen);

    // Check if the point is inside the unit circle
    if (x * x + y * y <= 1.0) {
      ++inside_circle;
    }
  }

  // Estimate of π
  return (static_cast<double>(inside_circle) / num_samples) * 4.0;
}

int main() {
  int num_samples = 1000000;  // Number of random samples
  double pi_estimate = estimate_pi(num_samples);

  std::cout << "Estimated value of π: " << pi_estimate << std::endl;

  return 0;
}
