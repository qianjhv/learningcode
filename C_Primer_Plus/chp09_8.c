#include <stdio.h>

double loop_pow(int, int);
double recursion_pow(int, int);

int main(int argc, char *argv[]) {

    printf("---------- pow(a, n), n >= 0 --------------\n\n");

    for (int i=0; i<=6; i++) {
        for (int j=0; j<=6; j++) {
            printf("%.2f\t", loop_pow(i, -j));
        }
        putchar('\n');
    }

    printf("\n---------- pow(a, n), n <= 0 --------------\n\n");

    for (int i=0; i<=6; i++) {
        for (int j=0; j<=6; j++) {
            printf("%.2f\t", recursion_pow(i, -j));
        }
        putchar('\n');
    }

    return 0;
}

double loop_pow(int a, int n) {

    double result = 1.0;

    if (a == 0) {
        return 0.0;
    }

    if (n > 0) {
        for (int i=n; i>0; i--) {
            result *= a;
        }
    } else if (n < 0) {
        for (int i=n; i<0; i++) {
            result *= (double)1 / a;
        }
    }

    return result;
}

double recursion_pow(int a, int n) {

    double result = 0;

    if (a == 0) {
        return result;
    }

    if (n > 0) {
        result = a * recursion_pow(a, n - 1);
    } else if (n < 0) {
        result = (double)1 / a * recursion_pow(a, n + 1);
    } else {
        result = 1;
    }

    return result;
}
