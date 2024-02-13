#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showList(int n, int* array) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

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

int main(void) {
    
    printf("\n");
    printf("%25s%12s%12s\n", "Numbers", "Indexes", "Shuffle");
    
    srand(time(NULL));
    
    int sizes[] = {10, 100, 1000, 10000, 2100000};
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
        //showList(size, result);
        free(result);

        start = clock();
        result = randomIndexes(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        //showList(size, result);
        free(result);

        start = clock();
        result = randomShuffle(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        //showList(size, result);
        free(result);

        printf("\n");
    }
    printf("\n");
    return 0;
}
