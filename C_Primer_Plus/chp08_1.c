#include <stdio.h>

int main(void) {

    char ch;
    unsigned int size = 0;

    while ((ch = getchar()) != EOF) {
        size++;
    }

    printf("%u\n", size);

    return 0;
}
