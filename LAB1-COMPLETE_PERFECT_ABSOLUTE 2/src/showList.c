#include "showList.h"
#include <stdio.h>

void showList(int n, int* array) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
