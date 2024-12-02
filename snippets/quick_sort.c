#include <stdio.h>

void quick_sort_recursion(int arr[], int, int);
int partition(int arr[], int low, int high);
int lo_partition(int arr[], int low, int high);
void swap(int *a, int *b);


int main(int argc, char *argv[]) {
    int arr[] = {10, 7, 2, 9, 6, 1, 3, 12 ,10, 19, 5, 4, 7};
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
        int pivot = lo_partition(arr, low, high);

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

// Lomuto
int lo_partition(int arr[], int low, int high) {
    int pivot_value = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot_value) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


