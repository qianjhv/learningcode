#include <stdio.h>
#include <ctype.h>

int main(void) {

    char ch;
    unsigned int words = 0, letters = 0, temp = 0;

    while ((ch = getchar()) != EOF) {
        if (isalnum(ch)) {
            temp++;
            letters++;
        }
        if (temp && (ispunct(ch) || isspace(ch))) {
            words++;
            temp = 0;
        }
    }

    if (temp) {
        words++;
    }


    printf("Words = %u, letters / Word = %.2f\n", words, (double)letters / words);

    return 0;
}