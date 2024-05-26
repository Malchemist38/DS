#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {

    char first_name[] = "Mal";
    char last_name[] = "Chemist";
    char full_name [15];

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);

    printf("%s", full_name);

    return 0;
}