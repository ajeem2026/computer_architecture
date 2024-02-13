#include "randomIndexes.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* randomIndexes(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int num = 0; num < n; num++) {
        int index = rand() % n;
        while (result[index] != -1) {
            index = rand() % n;
        }
        result[index] = num;
    }
    return result;
}
