"""
Every night between 7 pm and midnight, two computing jobs from two different sources are randomly started with each one lasting an hour.

Unfortunately, when the jobs simultaneously run, they cause a failure in some of the company’s other nightly jobs, resulting in downtime for the company that costs $1000.

The CEO, who has enough time today to hear one word, needs a single number representing the annual (365 days) cost of this problem.

Note: Write a function to simulate this problem and output an estimated cost
Bonus: How would you solve this using probability?
"""

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns  # For KDE plot


def simulate_overlap():
    cost_per_day = 1000
    total_cost = 0
    simulations = 100

    for _ in range(simulations):
        yearly_cost = 0
        for _ in range(365):  # Simulate each day of the year
            # Job start times between 7 PM (0 minutes) and midnight (300 minutes)
            task1_start = np.random.randint(0, 300)
            task2_start = np.random.randint(0, 300)

            # Check if tasks overlap
            if abs(task1_start - task2_start) < 60:
                yearly_cost += cost_per_day

        total_cost += yearly_cost

    # Return the average cost per year
    return total_cost / simulations


# Simulate the overlap and store in a distribution list
distribution = [simulate_overlap() for _ in range(2000)]

# Create a Figure and Axes object
fig, ax = plt.subplots(nrows=1, ncols=1, figsize=(6, 4))

# Plot the distribution as a histogram
sns.histplot(
    distribution,
    bins=30,
    kde=True,
    ax=ax,
    color="grey",
    label="Estimated Cost Distribution",
)

# Configure Axes
ax.set_title("Distribution of Annual Costs for Night Job Overlap")
ax.set_xlabel("Estimated Cost ($)")
ax.set_ylabel("Frequency")
ax.legend()

# Display the plot
plt.show()
