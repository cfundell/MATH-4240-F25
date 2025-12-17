import numpy as np
import matplotlib.pyplot as plt


Ns = [100,	500,	1000,	2500,	5000,	7500,	10000,	15000,	20000]
speedups = [3.042169,	2.690567828,	3.118127,	3.281352039,	3.442891,	3.345938524,	3.206809,	4.000110371,	3.305794]

x_cords = [-1000, 25000]
y_cords = [3.0, 3.0]

plt.ylim(0, 5.0)
plt.xlim(-500, 20500)

plt.plot(x_cords, y_cords, linestyle='dashed', color="#7a7a7a")

plt.plot(Ns, speedups, 'o', color='b')
plt.plot(Ns, speedups, color='b')

# Label the plot
plt.xlabel("Size of matrix (N)")
plt.ylabel("Speedup")
plt.title("Maximum speedup vs Matrix Size")

# Save the plot
plt.savefig("Speedups.png", dpi=300, bbox_inches='tight')

# Close the figure
plt.close()