#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Define the number of threads to use
#define NUM_THREADS 3

// Structure to hold thread data
typedef struct {
    int size;
    int* result;
} ThreadData;

// Function prototypes
void* randomNumbersThread(void* arg);
void* randomIndexesThread(void* arg);
void* randomShuffleThread(void* arg);

// Function to display an array using pointer arithmetic
void showList(int n, int* array) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
}

// Function to generate an array of random numbers without repetition
int* randomNumbers(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;
    while (count < n) {
        int num = rand() % n;
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (*(result + i) == num) {
                found = 1;
                break;
            }
        }
        if (!found) {
            *(result + count) = num;
            count++;
        }
    }
    return result;
}

// Function to generate an array of random indexes without repetition
int* randomIndexes(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        *(result + i) = -1;
    }

    for (int num = 0; num < n; num++) {
        int index = rand() % n;
        while (*(result + index) != -1) {
            index = rand() % n;
        }
        *(result + index) = num;
    }
    return result;
}

// Function to perform array shuffling using Fisher-Yates algorithm
int* randomShuffle(int n) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        *(result + i) = i;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = *(result + i);
        *(result + i) = *(result + j);
        *(result + j) = temp;
    }
    return result;
}

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

        // Thread data for each parallelizable function
        ThreadData data[NUM_THREADS];
        pthread_t threads[NUM_THREADS];

        // Create threads for each parallelizable function
        for (int j = 0; j < NUM_THREADS; j++) {
            data[j].size = size;
            data[j].result = NULL;
            pthread_create(&threads[j], NULL, j == 0 ? randomNumbersThread : (j == 1 ? randomIndexesThread : randomShuffleThread), &data[j]);
        }

        // Wait for all threads to complete
        for (int j = 0; j < NUM_THREADS; j++) {
            pthread_join(threads[j], NULL);
        }

        // Print CPU time and results for each thread (data[i].result)
        // ...
        // For demonstration, let's print the results using showList function
        //for (int j = 0; j < NUM_THREADS; j++) {
        //    showList(size, data[j].result);
        //    free(data[j].result);
        //}

        printf("\n");
    }

    printf("\n");
    return 0;
}

// Function to generate random numbers (thread entry point)
void* randomNumbersThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int size = data->size;
    data->result = randomNumbers(size);
    pthread_exit(NULL);
}

// Function to generate random indexes (thread entry point)
void* randomIndexesThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int size = data->size;
    data->result = randomIndexes(size);
    pthread_exit(NULL);
}

// Function to perform array shuffling (thread entry point)
void* randomShuffleThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int size = data->size;
    data->result = randomShuffle(size);
    pthread_exit(NULL);
}
