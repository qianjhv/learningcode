#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void copy_toupper(void);    // 13-3

int main(int argc, char *argv[]) {
	// copy_toupper();

    /* 13-13 */
    FILE *f;
    char str[] = {' ', '.', '!', '^', '%', '*', '&', '$', '@', '#'};
    const char *source = "20x30.txt";
    const int SIZE = 61;
    char buffer[SIZE];

    const int ROW = 20, COL = 30;
    int arr[ROW][COL];
    f = fopen(source, "r");
    if (f == NULL) {
        fprintf(stderr, "Error, can't open %s!\n", source); 
        exit(1);
    }

    int j = 0;
    while (fgets(buffer, sizeof(buffer), f)) {
        for (int i = 0; i < sizeof(buffer) - 1; i++) {
            if ((i & 1) == 0) {
                arr[j][i] = buffer[i] - '0';
                printf("%d ", arr[j][i]);
            }
        }
        j++;
        putchar('\n');
    }
    fclose(f);

    /*
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d", arr[i][j]);
        }
        putchar('\n');
    }
    */
    
    
    int inner_compare(int arr[ROW][COL], int row, int col) {
        
        int tmp = arr[row][col];
        int top = arr[row - 1][col], bottom = arr[row + 1][col], left = arr[row][col - 1], right = arr[row][col + 1];
        if (abs(tmp - top) > 1 && abs(tmp - bottom) > 1 && abs(tmp - left) > 1 && abs(tmp - right) > 1) {
            return (top + bottom + left + right) / 4;
        }
        return tmp;
    }

    int **compare_all(int arr[ROW][COL], int row, int col) {
        int** res = malloc(row * sizeof(int*));

        for (int i = 0; i < row; i++) {
            res[i] = malloc(col * sizeof(int));
            for (int j = 0; j < col; j++) {
                int tmp = arr[i][j];
                if (i == 0 && j == 0) res[i][j] = (abs(tmp - arr[i][j+1]) > 1 &&  abs(tmp - arr[i + 1][j]) > 1) ? (arr[i][j+1] + arr[i+1][j]) / 2 : tmp;
                else if (i == 0 && j == col - 1) res[i][j] = (abs(tmp - arr[i][j-1]) > 1 &&  abs(tmp - arr[i + 1][j]) > 1) ? (arr[i][j-1] + arr[i+1][j]) / 2 : tmp;
                else if (i == row - 1 && j == 0) res[i][j] = (abs(tmp - arr[i-1][j]) > 1 &&  abs(tmp - arr[i][j+1]) > 1) ? (arr[i-1][j] + arr[i][j+1]) / 2 : tmp;
                else if (i == row-1 && j == col-1) res[i][j] = (abs(tmp - arr[i-1][j]) > 1 &&  abs(tmp - arr[i][j-1]) > 1) ? (arr[i-1][j] + arr[i][j-1]) / 2 : tmp;
                else res[i][j] = inner_compare(arr, row, col);
            }
        }
        return res;
    }

    int **fi = compare_all(arr, 20, 30);

/*
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d", fi[i][j]);
        }
        putchar('\n');
    }
 */   
    free(fi);

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
            fprintf(stderr, "Error, can't open %s!\n", argv[i]); 
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


/* 13-12 */
// :for i in range(20) | call setline(i + 1, join(map(range(30), {j->string(rand() % 10)}), ' ')) | endfor
/* 
FILE *f;
char str[] = {' ', '.', '!', '^', '%', '*', '&', '$', '@', '#'};
const char *source = "20x30.txt";
const int SIZE = 61;
char buffer[SIZE];

f = fopen(source, "r");
if (f == NULL) {
    fprintf(stderr, "Error, can't open %s!\n", source); 
    exit(1);
}

while (fgets(buffer, sizeof(buffer), f)) {
    for (int i = 0; i < sizeof(buffer) - 1; i++) {
        if ((i & 1) == 0) {
            int t = buffer[i] - '0';
            printf("%c", str[t]);
        }
    }
    putchar('\n');
}
fclose(f);
*/
