#include <stdio.h>

void transform(double source[], double target[], int n, double (*sin) (double));

int main(void) {


    return 0;
}

void transform(double source[], double target[], int n, double (*sin) (double)) {
    for (int i = 0; i < n; i++) {
        target[i] = sin(source[i]);
    }
}
