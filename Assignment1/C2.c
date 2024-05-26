#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char* argv[]) {

    char file_name[] = "shape.txt";
    char cwd[PATH_MAX];
    FILE* file;

    file = fopen(file_name, "r"); //assuming the file is still present from C1
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        printf("Error finding directory location");
        return 1;
    }
    
    printf("File location opened: %s\n", cwd);
    fclose(file);
    printf("File location closed: %s\n", cwd);
    
    return 0;
}