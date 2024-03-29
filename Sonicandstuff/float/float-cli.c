#include <stdio.h>
#include <stdlib.h> // For atoi function

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf("%p\t0x%.2x\n", start+i, start[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1; // Return error code
    }

    int a = atoi(argv[1]); // Convert command-line argument to integer
    printf("int a = %d;\n", a);
    show_bytes((pointer) &a, sizeof(int));
    return 0;
}
