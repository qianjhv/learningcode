#include <stdio.h>

void copy_arr(int, int, const double [][*], double [*][*]);

int main(void) {

    double source[4][5] = {1.1, 3.1, 6.4, 7.6, 7.8, 1.9, 1.0, [2][4]=9.8, 2.0, [3]={1.2, 2.5}};
    double target[5][5];

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf("%.1f ", target[i][j]);
        }
        putchar('\n');
    }

    printf("\n-----------------------------\n");
    copy_arr(4, 5, source, target);
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf("%.1f ", target[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

void copy_arr(int rows, int cols, const double source[][cols], double (*target)[cols]) {

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            target[i][j] = source[i][j];
        }
    }

}