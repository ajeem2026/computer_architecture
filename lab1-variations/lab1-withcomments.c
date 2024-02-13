#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display an array using array indexing
void showList(int n, int* array) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to generate an array of random numbers without repetition
int* randomNumbers(int n) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * sizeof(int));
    // Counter for the number of elements generated
    int count = 0;
    while (count < n) {
        // Generate a random number
        int num = rand() % n;
        // Check if the number is already in the result array
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (result[i] == num) {
                found = 1;
                break;
            }
        }
        // If the number is not in the array, add it
        if (!found) {
            result[count] = num;
            count++;
        }
    }
    return result;
}

// Function to generate an array of random indexes without repetition
int* randomIndexes(int n) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * sizeof(int));
    // Initialize the array with -1
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int num = 0; num < n; num++) {
        // Generate a random index
        int index = rand() % n;
        // Find the next available index
        while (result[index] != -1) {
            index = rand() % n;
        }
        // Assign the number to the index
        result[index] = num;
    }
    return result;
}

// Function to shuffle an array using Fisher-Yates algorithm
int* randomShuffle(int n) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * sizeof(int));
    // Initialize the array with values from 0 to n-1
    for (int i = 0; i < n; i++) {
        result[i] = i;
    }

    // Fisher-Yates shuffle for the array of values
    for (int i = n - 1; i > 0; i--) {
        // Generate a random index
        int j = rand() % (i + 1);
        // Swap the values at positions i and j
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    return result;
}

int main(void) {
    // Print a newline for better formatting
    printf("\n");
    // Print headers for the result table
    printf("%25s%12s%12s\n", "Numbers", "Indexes", "Shuffle");
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Array of sizes to test
    int sizes[] = {10, 100, 1000, 10000, 2100000};
    // Calculate the number of sizes in the array
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    
    // Loop through each size
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        // Print the current size
        printf(" Size: %5d ", size);
        
        // Variables to measure CPU time
        clock_t start, end;
        double cpu_time_used;
        int* result;

        // Measure time for randomNumbers
        start = clock();
        result = randomNumbers(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        // Display the result (commented out for brevity)
        // showList(size, result);
        // Free allocated memory
        free(result);

        // Measure time for randomIndexes
        start = clock();
        result = randomIndexes(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        // Display the result (commented out for brevity)
        // showList(size, result);
        // Free allocated memory
        free(result);

        // Measure time for randomShuffle
        start = clock();
        result = randomShuffle(size);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        // Display the result (commented out for brevity)
        // showList(size, result);
        // Free allocated memory
        free(result);

        // Print a newline to separate rows in the table
        printf("\n");
    }
    // Print a newline at the end for better formatting
    printf("\n");
    return 0;
}
