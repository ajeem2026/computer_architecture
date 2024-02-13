#include "randomNumbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* randomNumbers(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;
    while (count < n) {
        int num = rand() % n;
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (result[i] == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[count] = num;
            count++;
        }
    }
    return result;
}
