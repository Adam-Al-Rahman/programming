from time import time
import numpy as np
import matplotlib.pyplot as plt


def calculate_calories_burned_batch(
    num_days: int,
    lower_temp: float,
    upper_temp: float,
    avg_tol: float,
    std_tol: float,
    avg_calories_burned: float,
) -> np.ndarray:
    """
    Calculates the calories burned over multiple days using vectorized operations.

    Args:
        num_days (int): Number of days to simulate.
        lower_temp (float): The lower bound for temperature.
        upper_temp (float): The upper bound for temperature.
        avg_tol (float): The average tolerance for heat.
        std_tol (float): The standard deviation of the tolerance.
        avg_calories_burned (float): The average calories burned when exercising.

    Returns:
        np.ndarray: An array of calories burned for each day.
    """
    # Vectorized generation of temperatures and tolerances
    temperatures = np.random.uniform(lower_temp, upper_temp, num_days)
    tolerances = np.random.normal(avg_tol, std_tol, num_days)

    # Vectorized calculation of calories burned
    exceeded_tolerance = temperatures > tolerances
    calories_burned = np.where(
        exceeded_tolerance, np.random.exponential(avg_calories_burned, num_days), 0.0
    )

    return calories_burned


start_time = time()

# Parameters for the simulation
DAYS = 1_000_000
daily_calories = calculate_calories_burned_batch(DAYS, 40, 60, 55, 5, 200)

end_time = time()
print(f"Time taken: {end_time - start_time:.5f} seconds")

# Plot histogram
plt.hist(daily_calories)
mean_calories = np.mean(daily_calories)
plt.title(f"Mean Calories Burned: {mean_calories:.2f}")
plt.show()

# Calculate and print the percentage of days with 0 calories burned
zero_days_percentage = np.mean(daily_calories == 0)
print(f"Percentage of days with 0 calories burned: {zero_days_percentage * 100:.2f}%")
