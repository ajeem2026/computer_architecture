#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomNumbers.h"
#include "randomIndexes.h"
#include "randomShuffle.h"
#include "showList.h"

int main(void) {
    printf("\n");
    printf("%25s%12s%12s\n", "Numbers", "Indexes", "Shuffle");
    srand(time(NULL));
    int sizes[] = {10, 100, 1000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        printf(" Size: %5d ", size);
        clock_t start, end;
        double cpu_time_used;
        int* result;

        start = clock();
        result = randomNumbers(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
//        showList(size, result);
        free(result);

        start = clock();
        result = randomIndexes(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
//        showList(size, result);
        free(result);

        start = clock();
        result = randomShuffle(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
//        showList(size, result);
        free(result);

        printf("\n");
    }
    printf("\n");
    return 0;
}
