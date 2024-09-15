#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void copy_toupper(void);    // 13-3

int main(int argc, char *argv[]) {
	// copy_toupper();

	
	return 0;
}

/* 13-3 */
void copy_toupper(void) {
	const unsigned int SLEN = 81;
	char ch;
	char source[SLEN], dst[SLEN];
	FILE *fo, *fi;
		

	puts("Enter name of source: ");
	fgets(source, sizeof(source), stdin);
	source[strcspn(source, "\n")] = '\0';
	puts("Enter name of destination: ");
	fgets(dst, sizeof(source), stdin);
	dst[strcspn(dst, "\n")] = '\0';

	fo = fopen(source, "r");
	fi = fopen(dst, "a+");

	while ((ch = getc(fo)) != EOF) {
		putc(toupper(ch), fi);
	}

	fclose(fo);
	fclose(fi);

}


/* 13-8 */
/* 
int counts = 0;
char ch;
FILE *f;

// argument judge
if (argc < 2) {
    fprintf(stderr, "Error, enter a character to search!\n");
    exit(1);
} else if (argc == 2) { // when just two arguments get character from stdin
    // first argument have to be a character
    if (strlen(argv[1]) != 1) {
        fprintf(stderr, "Error, enter a character to search not characters!\n");
        exit(1);
    }
    printf("Search %c from stdin file stream, use '\\n\\n' to stop!\n", argv[1][0]);
    char quit = 0;
    while ((ch = getc(stdin)) != EOF) {
        if (quit == '\n' && ch == '\n') {
            break;
        }
        if (ch == '\n') {
            quit = ch;
        } else {
            quit = 0;
        }
        if(ch == argv[1][0]) {
            counts++;
        }
    }
    printf("There are %d %c characters.\n", counts, argv[1][0]);
    exit(1);
} else {
    // first argument have to be a character
    if (strlen(argv[1]) != 1) {
        fprintf(stderr, "Error, enter a character to search not characters!\n");
        exit(1);
    }

    for (int i = 2; i < argc; i++) {
        counts = 0;
        f = fopen(argv[i], "r");
        if (f == NULL) {
            fprintf(stderr, "Error, can't open %s!\n", argv[2]); 
            continue;
        }
        for (int j = 0; j < strlen(argv[i]); j++) {
            if(ch == argv[i][j]) {
                counts++;
            }
        }
        while ((ch = getc(f)) != EOF) {
            if(ch == argv[1][0]) {
                counts++;
            }
        }
        printf("The file %s has %d character(s) %c.\n", argv[i], counts, argv[1][0]);
    }
    fclose(f);
}
**/


