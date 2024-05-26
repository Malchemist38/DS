#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void build_segment_tree(int arr[], int tree[], int start, int end, int node) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build_segment_tree(arr, tree, start, mid, 2 * node + 1);
        build_segment_tree(arr, tree, mid + 1, end, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

int* construct_segment_tree(int arr[], int n) {
    int height = (int)(ceil(log2(n)));
    int max_size = 2 * (int)(pow(2, height)) - 1;
    int* tree = (int*)malloc(max_size * sizeof(int));
    build_segment_tree(arr, tree, 0, n - 1, 0);
    return tree;
}

int main() {
    int arr[] = {1, 1, 2, 2, 7, 7, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* segment_tree = construct_segment_tree(arr, n);

    printf("Segment Tree Array: ");
    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%d ", segment_tree[i]);
    }
    printf("\n");

    free(segment_tree);

    return 0;
}
