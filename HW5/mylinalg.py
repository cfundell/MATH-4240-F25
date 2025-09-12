"""
Much of this code is adopted from 'gauss_elimination_solve.py' on Canvas. If I'm not supposed to do this please let me know. 

Gauss elimination (no partial pivoting) 
solve linear system Ax = b
with a given example 
A size 3 by 3 matrix
b size 3 by 1 vector
compared with numpy solve results
"""
import matplotlib.pyplot as plt
import numpy as np

# input A and b

#A = np.array([[3.0,1,-1],[1.0,-1,1],[2.0,1,1]])
#b = np.array([1.0,-3,0])

# A = np.array([[-2,0,1],[-1.0,7,1],[5,-1,1]])
# b = np.array([-4.0,-50,-26])

def GaussElimination(A,b):
    print('A and b are:')
    print(A)
    print(b)

    AA = np.copy(A)
    bb = np.copy(b)

    # Assumes that the matrix is square
    num_rows = len(A)
    num_cols = len(A)
    print(num_rows)

    #main loop
    print('Gaussian Elimination === ') 
    for col in range(num_cols-1):
        print('Gauss elemination along col=',col,':')
        for row in range(col+1,num_rows):
            m = (A[row][col]/A[col][col])
            A[row][col:] = A[row][col:] - m*A[col][col:]
            b[row] = b[row] - m*b[col]
        print(A) 
        print(b)

    #back substituion
    print('Back substitution === ')
    x= np.zeros(num_cols)
    x[num_rows-1] = b[num_rows-1]/A[num_rows-1][num_cols-1]
    for row in range(num_rows-2,-1,-1):
        x[row] = (b[row] - np.dot(A[row][row+1:],x[row+1:]))/A[row][row]

    print(x)

    #compare with numpy solve
    from numpy import linalg as la
    xx = la.solve(AA,bb)
    print(xx)

    print('Error compuared with numpy solve is ', la.norm(x-xx))

    return x

    

if __name__ == "__main__":
    A = np.array([[1, -0.2, 0.04, -0.008], [1, -0.1, 0.01, 0.001], [1, 0.1, 0.01, 0.001], [1, 0.2, 0.04, 0.008]])
    b = np.array([np.cos(-0.2), np.cos(-0.1), np.cos(0.1), np.cos(0.2)])

    x_vec = GaussElimination(A,b)

    def p_x(x):
        return x_vec[0] + x_vec[1] * x + x_vec[2] * x**2 + x_vec[3] * x**3 

    def f_x(x):
        return np.cos(x)
    
    x_values = np.linspace(-1.1, 1.1, 100)

    p_values = p_x(x_values)
    f_values = f_x(x_values)

    plt.plot(x_values, f_values, label="f(x) = cos(x)")
    plt.plot(x_values, p_values, label=f"p(x) = {x_vec[0]} + {x_vec[1]}x + {x_vec[2]}x^2 + {x_vec[3]}x^3")

    plt.title('Cosine vs. Interpolating Polynomial')
    plt.legend()

    plt.savefig('cos_vs_interpolated.png', bbox_inches='tight')

    print("Plot saved to \'cos_vs_interpolated.png\'.")