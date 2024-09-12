#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// LCG 算法的参数
#define A 1103515245
#define C 12345
#define M 2147483648

unsigned int call_count(void);
void sort_rand_number(void);
void print_arr_count(void); 
int * make_array(int elem, int val);
void show_array(const int ar[], int n);

unsigned int my_srand(unsigned int);
unsigned int my_rand();

unsigned int seed = 1;

int main(int argc, char *argv[]) {

    /*
    for(int i=0; i<5; i++) {
        printf("%d\n", call_count());
    }

    printf("%d\n", call_count());
    */

    // sort_rand_number();

    // print_arr_count();

    int size = 40;
    int * pa = make_array(size, 6);
    printf("%d  --\n", sizeof(pa));
    show_array(pa, size);
    free(pa);

    return 0;
}


// 4
unsigned int call_count(void) {
    static unsigned int count = 0;
    return ++count;
}

// 5
void sort_rand_number(void) {

    unsigned int temp;
    unsigned int arr[100];
    my_srand(time(NULL));

    for(int i=0; i<99; i++) {
        arr[i] = my_rand(seed) % 10 + 1;
    }

    for(int i=0; i<99; i++) {
        for(int j=i+1; j<99; j++) {
            if(arr[i] < arr[j]) {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
        }
    }

    for(int i=0; i<99; i++) {
        printf("%d\t", arr[i]);
    }

}

// 6
void print_arr_count(void) {

    const unsigned int TEST_ARR[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    unsigned int cnt[10] = {};
    
    my_srand(1234);
    for(int i=0; i<1000; i++) {
        int temp = my_rand() % 10 + 1;
        cnt[temp - 1]++;
    }

    for(int i=0; i<9; i++) {
        printf("%d -> %d\n", TEST_ARR[i], cnt[i]);
    }

}

// 8

int * make_array(int elem, int val) {
    int *pnt = (int *) malloc(elem * sizeof(int));
    for(int i=0; i<elem; i++) {
        pnt[i] = val;
    }
    return pnt;
}

// 8
void show_array(const int ar[], int n) {
    for(int i=0; i<n; i++) {
        if(i % 8 == 0) {
            printf("\n");
        }
        printf("%d\t", ar[i]);
    }
}

// 设置随机数种子
unsigned int my_srand(unsigned int new_seed) {
    seed = new_seed;
}

// 自定义随机数函数
unsigned int my_rand() {
    seed = (A * seed + C) % M;
    return seed;
}
