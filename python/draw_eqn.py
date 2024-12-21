import sympy as sp
from sympy.plotting import plot3d

# Define variables
x, y = sp.symbols("x y")

# Define the function z = 5x + 3y
z = 5 * x + 3 * y

# Plot the surface
plot3d(
    z, (x, 0, 20), (y, 0, 20), title="z = 5x + 3y", xlabel="x", ylabel="y", zlabel="z"
)
