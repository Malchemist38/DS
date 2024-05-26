#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {

    char last_name[] = "chemist";
    int i;

    printf("Lowercased name: %s\n", last_name);

    for (i = 0; i < strlen(last_name); i++) {
        last_name[i] = toupper(last_name[i]);
    }

    printf("Uppercased name: %s\n", last_name);

    return 0;
}