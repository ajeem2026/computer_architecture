#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define NUM_THREADS 10

// Global variables
int array[ARRAY_SIZE];
int sortedArray[ARRAY_SIZE];
clock_t start_times[NUM_THREADS];
clock_t end_times[NUM_THREADS];

// Bubble sort algorithm
void bubbleSort() {
    start_times[0] = clock();

    int i, j;
    for (i = 0; i < ARRAY_SIZE - 1; i++) {
        for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap elements
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    end_times[0] = clock();
}

// Merge sort algorithm
void merge(int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int leftArray[leftSize], rightArray[rightSize];

    // Copy data to temp arrays
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = array[low + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = array[mid + 1 + j];

    // Merge the temp arrays back into array[low..high]
    int i = 0, j = 0, k = low;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int low, int high) {
    start_times[1] = clock();

    if (low < high) {
        int mid = low + (high - low) / 2;

        // Recursively sort left and right halves
        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        // Merge the sorted halves
        merge(low, mid, high);
    }

    end_times[1] = clock();
}

int main() {
    // Initialize the array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Sort with bubble sort without threads
    bubbleSort();
    double bubble_time_no_threads = (double)(end_times[0] - start_times[0]) / CLOCKS_PER_SEC;

    // Sort with merge sort without threads
    mergeSort(0, ARRAY_SIZE - 1);
    double merge_time_no_threads = (double)(end_times[1] - start_times[1]) / CLOCKS_PER_SEC;

    printf("Without Threads:\n");
    printf("Bubble Sort Time: %f seconds\n", bubble_time_no_threads);
    printf("Merge Sort Time: %f seconds\n", merge_time_no_threads);

    // Initialize the array with random values again
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }

    // Sort with bubble sort using threads
    pthread_t bubble_thread;
    pthread_create(&bubble_thread, NULL, (void*)bubbleSort, NULL);
    pthread_join(bubble_thread, NULL);
    double bubble_time_with_threads = (double)(end_times[0] - start_times[0]) / CLOCKS_PER_SEC;

    // Sort with merge sort using threads
    pthread_t merge_thread;
    pthread_create(&merge_thread, NULL, (void*)mergeSort, (void*) (int[]){0, ARRAY_SIZE - 1});
    pthread_join(merge_thread, NULL);
    double merge_time_with_threads = (double)(end_times[1] - start_times[1]) / CLOCKS_PER_SEC;

    printf("\nWith Threads:\n");
    printf("Bubble Sort Time: %f seconds\n", bubble_time_with_threads);
    printf("Merge Sort Time: %f seconds\n", merge_time_with_threads);

    printf("                           ______                         \n");
    printf("                     _.-*\"'      \"`*-._                   \n");
    printf("                _.-*'                  `*-._              \n");
    printf("             .-'                            `-.           \n");
    printf("  /`-.    .-'                  _.              `-.        \n");
    printf(" :    `..'                  .-'_ .                `.      \n");
    printf(" |    .'                 .-'_.' \\ .                 \\     \n");
    printf(" |   /                 .' .*     ;               .-\"'     \n");
    printf(" :   L                    `.     | ;          .-'         \n");
    printf("  \\.' `*.          .-*\"*-.  `.   ; |        .'            \n");
    printf("  /      \\        '       `.  `-'  ;      .'              \n");
    printf(" : .\"\"`.  .       .-*'`*-.  \\     .      (_               \n");
    printf(" |              .'        \\  .             `*-.           \n");
    printf(" |.     .      /           ;                   `-.        \n");
    printf(" :    db      '       d$b  |                      `-.     \n");
    printf(" .   :PT;.   '       :P\"T; :                         `.   \n");
    printf(" :   :bd;   '        :b_d; :                           \\  \n");
    printf(" |   :$$; `'         :$$$; |                            \\ \n");
    printf(" |    TP              T$P  '                             ;\n");
    printf(" :                        /.-*\"'\".                       |\n");
    printf(".sdP^T$bs.               /'       \\                      \n");
    printf("$$$._.$$$$b.--._      _.'   .--.   ;                      \n");
    printf("`*$$$$$$P*'     `*--*'     '  / \\  :                      \n");
    printf("   \\                        .'   ; ;                      \n");
    printf("    `.                  _.-'    ' /                       \n");
    printf("      `*-._            _.-*'                              \n");
    printf("           `*=--..--=*'                                   \n");
    printf("GOTTA GO FAAAAAAAAAAAAAAAAAAAAAAAST!!!!!!!!!!!!!!!!!!!!!!!\n");


    return 0;
}
