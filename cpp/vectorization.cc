// Copyright 2024 Adam-Al-Rahman
// Monte Carlo Simulation with vectorization

#include <algorithm>
#include <chrono>  // NOLINT(build/c++11)
#include <iostream>
#include <random>
#include <vector>

// Function to calculate calories burned using vectorization
std::vector<double> calculate_calories_burned_vectorized(int num_days, double lower_temp, double upper_temp,
                                                         double avg_tol, double std_tol, double avg_calories_burned) {
  std::vector<double> temperatures(num_days);
  std::vector<double> tolerances(num_days);
  std::vector<double> calories_burned(num_days, 0.0);  // Initialize with 0.0

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> temp_dist(lower_temp, upper_temp);
  std::normal_distribution<> tol_dist(avg_tol, std_tol);
  std::exponential_distribution<> exp_dist(avg_calories_burned);

  // Generate temperatures and tolerances
  std::generate(temperatures.begin(), temperatures.end(), [&]() { return temp_dist(gen); });
  std::generate(tolerances.begin(), tolerances.end(), [&]() { return tol_dist(gen); });

// Auto-vectorized loop
#pragma omp simd
  for (int i = 0; i < num_days; ++i) {
    if (temperatures[i] > tolerances[i]) {
      calories_burned[i] = exp_dist(gen);  // Only burn calories when temp exceeds tolerance
    }
  }

  return calories_burned;
}

int main() {
  const int DAYS = 1000000;  // Simulate over 1 million days for testing performance
  const double lower_temp = 40.0;
  const double upper_temp = 60.0;
  const double avg_tol = 55.0;
  const double std_tol = 5.0;
  const double avg_calories_burned = 200.0;

  auto start_time = std::chrono::high_resolution_clock::now();

  // Calculate calories burned using vectorization
  std::vector<double> daily_calories =
      calculate_calories_burned_vectorized(DAYS, lower_temp, upper_temp, avg_tol, std_tol, avg_calories_burned);

  auto end_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end_time - start_time;
  std::cout << "Time taken: " << elapsed.count() << " seconds" << std::endl;

  // Calculate the percentage of days with 0 calories burned
  int zero_days = std::count(daily_calories.begin(), daily_calories.end(), 0.0);
  double zero_days_percentage = static_cast<double>(zero_days) / DAYS * 100.0;
  std::cout << "Percentage of days with 0 calories burned: " << zero_days_percentage << "%" << std::endl;
}
