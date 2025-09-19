#include <stdio.h>
#include <math.h>

// Factorial function
int factorial(int n) {
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
    return num_fact;
}

// Exponential function
double exponential(double x) {
    double e = 2.718281828459;
    double x0 = round(x);
    double z = x - x0;
    double e_to_x = 0;
    // Calculate exponential
    for (int i=0; i<=10; i++) {
        e_to_x += pow(e, x0) * pow(z, i)/factorial(i);
    } 
    return e_to_x;
}

// Call factorial and exponential functions
int main() {
    FILE* outfile = fopen("exp.data", "w");
    double x_values[5];
    printf("Enter five values to raise e to: ");
    int input = scanf("%lf %lf %lf %lf %lf", &x_values[0], &x_values[1], &x_values[2], &x_values[3], &x_values[4]);

    int array_length = sizeof(x_values) / sizeof(x_values[0]);

    printf("Input array: ");
    fprintf(outfile, "Input array:");
    for (int i = 0; i < array_length; i++) {
        printf("%lf", x_values[i]);
        fprintf(outfile, " %lf", x_values[i]);
    }
    
    printf("\n");
    fprintf(outfile, "\n");

    printf("Output array: ");
    fprintf(outfile, "Output array:");
    for (int i = 0; i < array_length; i++) {
        printf("%f ", exponential(x_values[i]));
        fprintf(outfile, " %lf", exponential(x_values[i]));
    }

    printf("\n");

    return 0;
}

