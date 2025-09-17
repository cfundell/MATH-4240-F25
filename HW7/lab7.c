#include <stdio.h>
#include <math.h>

// Function to calculate the factorial, exponential, and natural logarithm of a number
int main() {
    // Factorial calculation
    int n = 4;
    int num_fact = 1;
    int i;
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else {
        for (i=1; i<=n; i++) {
            num_fact = num_fact * i;
        }
    }
    

    // Exponential calculation
    double one = 1.0;
    double exp_one = exp(one);
    double two = 2.0;
    double exp_two = exp(two);

    // Natural logarithm calculation
    double e = 2.718281828459045;
    double ln_e = log(e);
    double ten = 10.0;
    double ln_ten = log(ten);

    // Print results
    printf("Factorial of 4: %d\n", num_fact);
    printf("Exponential of 1: %.6f\n", exp_one);
    printf("Exponential of 2: %.6f\n", exp_two);
    printf("Natural logarithm of e: %.6f\n", ln_e);
    printf("Natural logarithm of 10: %.6f\n", ln_ten);

    return 0;
}