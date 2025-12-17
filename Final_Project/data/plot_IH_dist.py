import numpy as np
import matplotlib.pyplot as plt

def normal_distribution(x):
    return ( 1/np.sqrt(2 * np.pi) ) * np.exp(-x**2 / 2)

# x_cords = range(-600, 600, 1) 
# x_cords = [x / 100.0 for x in x_cords]
x_cords = np.linspace(-6, 6, 1000)
y_cords = [normal_distribution(x) for x in x_cords]
plt.plot(x_cords, y_cords)

# Load the data
data = np.loadtxt("IH_1000.data")

# Create the histogram with probability density
plt.hist(
    data,
    bins=50,
    range=(-6, 6),
    density=True,        # y-axis becomes probability density
    edgecolor="black",   # draw lines around bins
    linewidth=0.5,
    label="Calculated Irwin-Hall",
    color="#ff9100")

# Label the plot
plt.plot(x_cords, y_cords, color="#003cff", label="Gaussian distribution")
plt.legend(loc="upper left")
plt.xlabel("Value")
plt.ylabel("Probability Density")
plt.title("Probability Histogram of Irwin-Hall distribution for N = 1,000")

# Save the plot
plt.savefig("irwin-hall_1000.png", dpi=300, bbox_inches='tight')

# Close the figure
plt.close()
