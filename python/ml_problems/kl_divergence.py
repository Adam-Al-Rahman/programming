import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm


# Function to compute KL divergence between two normal distributions
def kl_divergence_normal(mu_p, sigma_p, mu_q, sigma_q):
    # KL divergence between two normal distributions
    term1 = np.log(sigma_q / sigma_p)
    term2 = (sigma_p**2 + (mu_p - mu_q) ** 2) / (2 * sigma_q**2)
    term3 = -0.5
    return term1 + term2 + term3


# Generate two distributions (Normal distributions)
np.random.seed(0)
mu_p, sigma_p = 0, 1  # True distribution parameters: N(0, 1)
mu_q, sigma_q = 0.5, 1.5  # Approximate distribution parameters: N(0.5, 1.5)

# Compute KL divergence between the two normal distributions
kl_value = kl_divergence_normal(mu_p, sigma_p, mu_q, sigma_q)

# Print the KL divergence value
print(
    f"KL Divergence between N({mu_p},{sigma_p**2}) and N({mu_q},{sigma_q**2}): {kl_value:.4f}"
)

# Generate random samples from the two distributions
true_dist = np.random.normal(mu_p, sigma_p, 1000)  # N(0, 1)
approx_dist = np.random.normal(mu_q, sigma_q, 1000)  # N(0.5, 1.5)

# Plotting the two distributions
plt.figure(figsize=(10, 6))

# Plot the true distribution (P)
plt.hist(true_dist, bins=50, alpha=0.6, label="True Distribution (P)", density=True)

# Plot the approximate distribution (Q)
plt.hist(
    approx_dist, bins=50, alpha=0.6, label="Approximate Distribution (Q)", density=True
)

# Add labels and legend
plt.title("KL Divergence between True and Approximate Distributions")
plt.xlabel("Value")
plt.ylabel("Density")
plt.legend()

# Display the plot
plt.show()
