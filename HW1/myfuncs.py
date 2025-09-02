def fact(n):
    n_fact = 1
    for k in range(n):
        n_fact = (k+1)*n_fact
    
    return n_fact

def exp(x):
    e_stored = 2.718281828459051
    x0 = int(round(x))
    z = x - x0
    e_to_x = 0
    for n in range(10):
        e_to_x += (e_stored**x0) * (z**n)/fact(n)

    return e_to_x

def ln(x):
    s = x
    for k in range(3):
        s = s**k - 1 + x/(exp(s**k))

    return s


