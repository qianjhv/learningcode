#include <stdio.h>

void copy_arr(double [], double [], int);
void copy_ptr(const double [], double *, int);

int max_in_arr(const int *arr_start, int *arr_end);

int max_index(const int*, int N);

int max_minus_min(const int *arr_start, int *arr_end);

int main(void) {

    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];

    printf("-------------------- chapter 10-2 test code below---------\n\n");

    copy_arr(source, target1, 5);
    for (int i=0; i<sizeof(target1)/sizeof(target1[0]); i++) {
        printf("%.1f\t", target1[i]);
    }

    printf("\n");

    copy_ptr(source, target2, 5);
    for (int i=0; i<sizeof(target2)/sizeof(target2[0]); i++) {
        printf("%.1f\t", *(target2 + i));
    }

    printf("\n\n\n-------------------- chapter 10-3 test code below---------\n\n");

    int arr[] = {1, 2, 3, -1, 5, 9, 11, 20, 13};
    printf("The largest number in arr is %d.\n", max_in_arr(arr, arr + sizeof(arr)/sizeof(arr[0])));

    printf("\n\n\n-------------------- chapter 10-4 test code below---------\n\n");
    printf("The largest number in arr is %dth.\n", max_index(arr, sizeof(arr)/sizeof(arr[0])));

    printf("\n\n\n-------------------- chapter 10-5 test code below---------\n\n");
    printf("Max - Min = %d.\n", max_minus_min(arr, arr + sizeof(arr)/sizeof(arr[0])));

    return 0;
}

void copy_arr(double source[], double target[], int N) {

    for (int i=0; i<N; i++) {
        target[i] = source[i];
    }

}

void copy_ptr(const double source[], double *target, int N) {

    for (int i=0; i<N; i++) {
        *target++ = *(source + i);
    }

}

int max_in_arr(const int *arr_start, int *arr_end) {

    int max = *arr_start;
    while (arr_start < arr_end) {
        if (max < *arr_start) {
            max = *arr_start;
        }
        arr_start++;
    }

    return max;

}

int max_index(const int *arr, int N) {
    
    int max = *arr;
    for (int i=1; i<N; i++) {
        if (max < arr[i]) {
            max = i;
        }
    }

    return max + 1;

}

int max_minus_min(const int *arr_start, int *arr_end) {

    int max = *arr_start, min = *arr_start;
    while (arr_start < arr_end) {
        if (max < *arr_start) {
            max = *arr_start;
        }
        if (min >  *arr_start) {
            min = *arr_start;
        }
        arr_start++;
    }

    return max - min;

}