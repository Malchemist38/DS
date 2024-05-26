#include <stdio.h>

int main(int argc, char* argv[]) {
    
    char file_name[] = "shape.txt";
    FILE* file;
    int fp_position;

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    fseek(file, 0, SEEK_END); //moves the pointer to the end of the file
    fp_position = ftell(file);
    printf("%d", fp_position);
    fclose(file);
    
    return 0;
}