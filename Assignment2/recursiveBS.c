#include <stdio.h>
#include <time.h>
#define SIZE 10

int RBS(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            return RBS(arr, low, mid - 1, key);
        else
            return RBS(arr, mid + 1, high, key);
    }
    return -1; //not found
}

void arrayPlot(int arr[]) {
    static int i = 0;
    if (i == SIZE) {
        return;
    }
        scanf("%d", &arr[i]);
        i++;
        arrayPlot(arr);
    return;
}

int main(int argc, char* argv[]) {
    int arr[SIZE];
    int key, index;
    clock_t start_t, end_t;
    long double total_t; //for increased precision

    printf("Binary Search (Recursive approach)\n");
    printf("Enter %d elements:\n", SIZE); // the elements are assumed to be entered in ascending order for binary search to work
    arrayPlot(arr);
    printf("Enter Key element to search:\n");
    scanf("%d", &key);
    start_t = clock();
    index = RBS(arr, 0, SIZE - 1, key);
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
