#include <stdio.h>
#include <time.h>
#define SIZE 10

int binarySearch(int arr[], int n, int key) {
    int mid, low = 0, high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        if (arr[mid] < key) {
            low = mid + 1;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1; //not found
}

int main(int argc, char* argv[]) {
    int arr[SIZE];
    int i, key, index;
    clock_t start_t, end_t;
    long double total_t; //for increased precision

    printf("Binary Search (Iterative approach)\n");
    printf("Enter %d elements:\n", SIZE); // the elements are assumed to be entered in ascending order for binary search to work
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter Key element to search:\n");
    scanf("%d", &key);
    start_t = clock();
    index = binarySearch(arr, SIZE, key);
    end_t = clock();
    total_t = (long double)(end_t - start_t) / CLOCKS_PER_SEC;
    if (index == -1) { 
        printf("Element not found");
    }
    else {
        printf("Element found at index %d\n", index + 1);
        printf("Total time taken by CPU (End Time - Start Time)/clock per_sec: %Lf\n", total_t);
    }
    return 0;
}
