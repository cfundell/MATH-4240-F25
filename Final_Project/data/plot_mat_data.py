import numpy as np
import matplotlib.pyplot as plt

x_cords = [1, 2, 4, 8, 16, 32]
N10_times = [0.000051, 0.000210, 0.000742, 0.000619]
N50_times = [0.000549, 0.000553, 0.000843, 0.000851, 0.001031, 0.001840]

N100_times = [0.002020,
0.001346,
0.001334,
0.000664,
0.000750,
0.002014
]

N500_times = [0.051032,
0.029176,
0.020312,
0.018967,
0.027615,
0.059496
]

N1000_times = [0.178017,
0.103227,
0.069356,
0.057091,
0.073114,
0.129973
]

N2500_times = [1.240082,
0.694000,
0.444161,
0.377918,
0.484036,
0.849658
]

N5000_times = [4.932923,
2.718196,
1.748489,
1.432785,
1.899809,
3.321010
]

N7500_times = [11.172691,
6.192941,
4.584739,
3.339180,
4.387765,
7.723003
]

N10000_times = [17.912541,
10.311757,
6.627911,
5.585784,
7.058409,
11.545922
]

N15000_times = [18.145517,
9.927488,
6.42403,
5.57745,
6.935755,
12.198675
]

# plt.plot(x_cords, N10_times, 'o')
# plt.plot(x_cords, N50_times, 'o')
# plt.plot(x_cords, N100_times, 'o')
# plt.plot(x_cords, N500_times, 'o')
# plt.plot(x_cords, N1000_times, 'o', color='b')
plt.plot(x_cords, N2500_times, 'o', color='g')
plt.plot(x_cords, N5000_times, 'o', color='r')
plt.plot(x_cords, N7500_times, 'o', color='k')
plt.plot(x_cords, N10000_times, 'o', color='m')
# plt.plot(x_cords, N15000_times, 'o', color='y')

# plt.plot(x_cords, N50_times)
# plt.plot(x_cords, N100_times)
# plt.plot(x_cords, N500_times)
# plt.plot(x_cords, N1000_times, color='b')
plt.plot(x_cords, N2500_times, color='g', label="N=2500")
plt.plot(x_cords, N5000_times, color='r', label="N=5000")
plt.plot(x_cords, N7500_times, color='k', label="N=7500")
plt.plot(x_cords, N10000_times, color='m', label="N=10000")
# plt.plot(x_cords, N15000_times, color='y', label="N=15000")

# Label the plot
plt.xlabel("Number of MPI processes")
plt.ylabel("Wall time (s)")
plt.title("Construction wall time of A and A^T")
plt.legend(loc="upper right")

# Save the plot
plt.savefig("Upper_N.png", dpi=300, bbox_inches='tight')

# Close the figure
plt.close()