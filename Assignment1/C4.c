#include <stdio.h>

int main(int argc, char* argv[]) {
    
    char file_name[] = "shape.txt";
    char content[3];
    FILE *file;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    fscanf(file, "%s", content);
    fclose(file);
    printf("\n%s", content);
    
    return 0;
}