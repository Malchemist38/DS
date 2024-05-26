#include <stdio.h>
#include <unistd.h> //for file location function
#include <limits.h> //for file path constant

int main(int argc, char* argv[]) {
    char file_name[] = "shape.txt";
    char cwd[PATH_MAX]; //predefined constant for the  maximum length of a file path
    FILE *file;

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    printf("File name: %s\n", file_name);
    
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        printf("Error finding directory location");
        return 1;
    }

    printf("File location: %s\n", cwd);
    fclose(file);

    return 0;
}
