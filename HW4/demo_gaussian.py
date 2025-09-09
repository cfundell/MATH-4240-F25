import numpy
import my_gaussian

A = numpy.array([[-4.3, 7.1], [-0.2, 5.6]])
A_mine = numpy.array([[-4.3, 7.1, -44.1], [-0.2, 5.6, -28.4]])
b = numpy.array([-44.1, -28.4])

print(f"Matrix:\n{A}")
print("Solution using my algorithm:", my_gaussian.gaussian_elim(A_mine))
print("Solution using numpy:", numpy.linalg.solve(A, b))
