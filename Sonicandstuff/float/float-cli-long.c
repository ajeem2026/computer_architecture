#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1; // Return error code
    }

    char *endptr;
    long a = strtol(argv[1], &endptr, 10); // Convert string to long integer
    if (*endptr != '\0') {
        printf("Invalid input: %s\n", argv[1]);
        return 1; // Return error code
    }

    printf("int a = %ld;\n", a);
    return 0;
}
