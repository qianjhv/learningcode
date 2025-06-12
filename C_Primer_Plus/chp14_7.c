#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

#define COLOR_RESET   "\033[0m"
#define COLOR_TITLE   "\033[1;34m"  // 粗体蓝色
#define COLOR_AUTHOR  "\033[0;32m"  // 绿色
#define COLOR_VALUE   "\033[0;33m"  // 黄色

char * s_gets(char *st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(int argc, char *argv[]) {

    struct book library[MAXBKS];
    int count = 0;
    int index, filecount, temp;
    FILE *pbooks;
    int size = sizeof(struct book);
    
    if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1) ;
    }

    rewind(pbooks);
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0 )
            puts("Current contents of book.dat:");


        printf("%d. ", count + 1);
        printf(COLOR_TITLE "<<%s>>" COLOR_RESET " by " COLOR_AUTHOR "%s" COLOR_RESET " : " COLOR_VALUE "$%.2f" COLOR_RESET "\n",library[count].title, library[count].author, library[count].value);
        count++ ;
    }

    filecount = count;

    if (count == MAXBKS) {
        fputs ( "The book.dat file is full.", stderr) ;
        exit(2);
    }

    puts("\nPlease add new book titles.");
    puts ("Press [enter] at the start of a line to stop.") ;
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
        puts ("Now enter the author.") ;
        s_gets(library[count].author, MAXAUTL);

        puts("Now enter the value.");
        temp = count++;
        char tempbuf[100];
        while (1) {
            s_gets(tempbuf, 100);
            if (sscanf(tempbuf, "%f", &library[temp].value) == 1)
                break;
            puts("The value is error, enter the value again: ");
        }

        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    if (count > 0) {
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++) {
            printf("%d. ", index + 1);
            printf(COLOR_TITLE "<<%s>>" COLOR_RESET " by " COLOR_AUTHOR "%18s" COLOR_RESET " : " COLOR_VALUE "%6.2f$" COLOR_RESET "\n",library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[filecount], size, count - filecount, pbooks);
    } else {
        puts("No books? Too bad.\n");
    }

    puts("\nBye.\n");
    fclose(pbooks) ;

    return 0;
}

char * s_gets(char *st, int n) {

    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);

    if (ret_val) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

