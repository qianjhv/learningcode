#include <stdio.h>

void quick_sort_recursion(int arr[], int, int);
int partition(int arr[], int low, int high);


int main(int argc, char *argv[]) {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort_recursion(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void quick_sort_recursion(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        quick_sort_recursion(arr, low, pivot - 1);
        quick_sort_recursion(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot_value = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot_value) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot_value) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot_value;
    return low;
}


