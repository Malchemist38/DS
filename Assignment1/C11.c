#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    int* ptr;
    int num;
    int i;

    printf("Enter number of elements (Malloc): ");
    scanf("%d", &num);

    ptr = (int*)malloc(num * sizeof(int));
    if (ptr == NULL) {
        printf("Error allocating memory");
    }

    printf("Enter elements:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("\n");

    for (i = 0; i < num; i++) {
        printf("Memory address of %d is %p\n", ptr[i], (ptr + i));
    }

    free(ptr);
    return 0;
}