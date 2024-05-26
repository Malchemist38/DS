#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int* arr;
    int num;
    int i;

    printf("Enter number of elements (Calloc): ");
    scanf("%d", &num);

    arr = (int*)calloc(num, sizeof(int));
    if (arr == NULL) {
        printf("Error allocating memory");
    }

    printf("Enter elements:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n");

    for (i = 0; i < num; i++) {
        printf("Memory address of %d is %p\n", arr[i], (arr + i));
    }

    free(arr);
    return 0;
}