#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    
    char file_name[] = "shape.txt";
    char cwd[PATH_MAX];
    FILE *file;

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    fprintf(file, "509");
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        printf("Error finding directory location");
        return 1;
    }
    
    printf("File location: %s\n", cwd);
    fclose(file);
    
    return 0;
}