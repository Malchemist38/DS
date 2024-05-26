#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char first_name[] = "Mal";
    char last_name[] = "Chemist";

    if (strcmp(first_name, last_name) == 0) {
        printf("These strings are the same (Error)");
    }
    else {
        printf("The strings %s and %s are different\n", first_name, last_name);
    }

    if (strcmp(last_name, last_name) == 0) {
        printf("The strings %s and %s are the same\n", last_name, last_name);
    }
    else {
        printf("The strings are different (Error)");
    }
    
    return 0;
}