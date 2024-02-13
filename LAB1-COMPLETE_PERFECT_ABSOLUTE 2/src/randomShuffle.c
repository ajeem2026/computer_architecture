#include "randomShuffle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* randomShuffle(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        result[i] = i;
    }

    // Fisher-Yates shuffle for the array of values
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    return result;
}
