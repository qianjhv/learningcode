#include <stdio.h>

void to_base_n(int, int);

int main(void) {

    for (int i=2; i<=16; i++) {
        to_base_n(1888, i);
        putchar('\n');
    }
    return 0;
}

void to_base_n(int a, int n) {
    if (a >= n) {
        to_base_n(a / n, n);
    }

    if (a % n > 9) {
        putchar(a % n + 55);
    }else {
        putchar((a % n) + '0');
    }
}