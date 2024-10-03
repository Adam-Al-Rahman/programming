# Pseudo Random Number Generator (PRNG)
# Linear Congruential Generator (LCG)
# LCG: X_{n + 1} = (a * X_{n} + C) mod m


class LCG:
    def __init__(self, seed=7):
        # Constants for LCG (these values are commonly used)
        self.m = 2**31  # modulus
        self.a = 1103515245  # multiplier
        self.c = 12345  # increment
        self.seed = seed  # initial seed
        self.state = seed  # current state

    def random(self):
        # Update the state using the LCG formula
        self.state = (self.a * self.state + self.c) % self.m
        # Normalize to the range [0, 1)
        return self.state / self.m


# Example usage
if __name__ == "__main__":
    lcg = LCG(seed=123)  # Initialize the PRNG with a seed
    random_numbers = [lcg.random() for _ in range(10)]  # Generate 10 random numbers
    print("Generated random numbers:", random_numbers)
