#include <stdio.h>

int fn(char);

int main(int argc, char *argv[]) {

    char ch;
    while ((ch = getchar()) != EOF) {
        if (fn(ch) != -1) {
            printf("%c - %d\t", ch, fn(ch));
        }
        if (ch == '\n') {
            putchar('\n');
        }
    }

    return 0;
}

int fn(char ch) {

    if (ch >= 65 && ch <= 90) {
        return ch - 64;
    } else if (ch >= 97 && ch <= 122) {
        return ch - 96;
    } else {
        return -1;
    }

}