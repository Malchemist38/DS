#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    
    char first_name[] = "Mal";
    char copied[6];
    int length;

    length = strlen(first_name);
    printf("Length of %s is %d\n", first_name, length);

    strcpy(copied, first_name);

    printf("Copied string is %s\n", copied);
    
    return 0;
}