import numpy 

def swap_rows(A, j, k):
    m = A.shape[0] # number of rows in A
    n = A.shape[1] # number of columns in A

    new_matrix = numpy.copy(A).astype('float64')

    for i in range(n):
        temp = new_matrix[j][i] # store the value in position (j, i)
        new_matrix = new_matrix[k][i]
        new_matrix[k][j] = temp

    return new_matrix

def scale_row(A, j, scalar):
    m = A.shape[0] # number of rows in A
    n = A.shape[1] # number of columns in A

    new_matrix = numpy.copy(A).astype('float64')

    for i in range(n):
        new_matrix[j][i] *= scalar

    return new_matrix

def add_rows(A, j, k, scalar):
    m = A.shape[0] # number of rows in A
    n = A.shape[1] # number of columns in A

    new_matrix = numpy.copy(A).astype('float64')

    for i in range(n):
        new_matrix[k][i] += new_matrix[j][i]*scalar

    return new_matrix

def gaussian_elim(A):
    # Scale first row based on the (0,0) element
    R1 = scale_row(A, 0, 1.0/A[0][0])

    # Add row 1 to row 2 to eliminate (1,0) element
    R2 = add_rows(R1, 0, 1, -A[1][0])

    # Scale row 2 based on the (1,1) element
    R3 = scale_row(R2, 1, 1.0/R2[1][1])

    # Add row 2 to row 1 to eliminate (0,1) element
    R4 = add_rows(R3, 1, 0, -R3[0][1])

    # Return the augmented column
    return R4[0][2], R4[1][2]

