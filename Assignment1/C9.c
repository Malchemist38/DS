#include <stdio.h>
#include <string.h>
#include <ctype.h> //for lowercase function

int main(int argc, char* argv[]) {

    char last_name[] = "CHEMIST";
    int i;
    
    printf("Uppercased name: %s\n", last_name);

    for (i = 0; i < strlen(last_name); i++) {
        last_name[i] = tolower(last_name[i]);
    }

    printf("Lowercased name: %s\n", last_name);

    return 0;
}