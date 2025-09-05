# Module that implements factorial, square root, exponential, and natural logarithm functions

# Factorial
def fact(n):
    # Some checks to account for erroneous inputs 
    n_int = int(n)
    if n < 0:
        print("Cannot compute factorials with negative numbers.")
        return
    elif (n - n_int != 0):
        print("Cannot compute factorials with non-integers.")
        return

    # Compute factorial
    n_fact = 1
    for k in range(n):
        n_fact = (k+1)*n_fact
    
    return n_fact

# Square root
def sqrt(x, kmax=10, Tol=10**-12, print_setting=0):
    x_n = 5 #initial guess

    for n in range(kmax):
        previous_x_n = x_n
        x_n = 0.5 * (x_n + x/x_n)

        diff_between_iterations = abs(previous_x_n - x_n)
        if diff_between_iterations <= Tol:
            if print_setting == 1: 
                print(f"Approximate value of x^0.5 reached after", str(n+1), "iterations:", x_n)
            return x_n

    if print_setting == 1:
        print(f"Maximum number of iterations reached. Final value:", x_n)    
    return x_n

# Exponential
# kmax: maximum number of iterations
# Tol: tolerence of final result. If the difference between iterations is <= Tol, return value
# print_setting: determines the amount of information printed during calculation. Default is 0, or return final number without printing
def exp(x, kmax=10, Tol=10**-12, print_setting=0):
    e_stored = 2.718281828459051
    x0 = int(round(x))
    z = x - x0
    e_to_x = 0
    for n in range(kmax):
        previous_e_to_x = e_to_x
        e_to_x += (e_stored**x0) * (z**n)/fact(n)
                
        diff_between_iterations = abs(previous_e_to_x - e_to_x)
        if diff_between_iterations <= Tol:
            if print_setting == 1: 
                print(f"Approximate value of e^x reached after", str(n+1), "iterations:", e_to_x)
            return e_to_x

    if print_setting == 1:
        print(f"Maximum number of iterations reached. Final value:", e_to_x)
    return e_to_x

# Natural Logarithm
def ln(x, kmax=100, Tol=10**-12, print_setting=0):
    s = x
    for k in range(100):
        previous_s = s
        s = s - 1 + x/(exp(s))

        diff_between_iterations = abs(previous_s - s)
        if diff_between_iterations <= Tol:
            if print_setting == 1: 
                print(f"Approximate value of ln(x) reached after", str(k+1), "iterations:", s)
            return s

    if print_setting == 1:
        print(f"Maximum number of iterations reached. Final value:", s)    
    return s
