#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const int Nmax = 4;
    int N;

    // read-in polynomial degree
    printf("\n Input polynomial degree (0-%i): ", Nmax);
    scanf("%i, &N");
    if (N<0 || N>Nmax) {
        printf(" Invalid value of N\n");
        printf(" N must satisfy: 0 <= N <= %i\n\n", Nmax);
        exit(1);
    }
    printf("\n");

    double b[Nmax + 1];
    for (int i = 0; i <= N; i++) {
        printf(" Set b[%i]: ", i);
        scanf("%lf", &b[1]);
    }

    printf("\n");

    // set x-coords
    const int NumPts = 25;
    double x[NumPts];
    for (int i = 0; i < NumPts; i++) {
        x[i] = -1.0 + i*(2.0/(1.0*(NumPts - 1 )));
    }

    // Calculate polynomial at x-coords
    double y[NumPts];
}