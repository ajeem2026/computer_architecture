#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display an array using array indexing
void showList(int n, int* array) {
    // Print a newline for better formatting
    printf("\n");
    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // Print the current element using array indexing
        printf("%d ", array[i]);
    }
    // Print a newline for better formatting
    printf("\n");
}

// Function to generate an array of random numbers without repetition
int* randomNumbers(int n) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * sizeof(int));
    // Counter for the number of elements generated
    int count = 0;
    // Loop until the required number of unique elements is generated
    while (count < n) {
        // Generate a random number within the range [0, n-1]
        int num = rand() % n;
        // Flag to check if the generated number is already in the array
        int found = 0;
        // Loop through the array to check for duplicates
        for (int i = 0; i < count; i++) {
            // If a duplicate is found, set the flag and break out of the loop
            if (result[i] == num) {
                found = 1;
                break;
            }
        }
        // If the generated number is not in the array, add it
        if (!found) {
            result[count] = num;
            count++;
        }
    }
    // Return the resulting array of unique random numbers
    return result;
}

// Function to generate an array of random indexes without repetition
int* randomIndexes(int n) {
    // Allocate memory for the result array
    int* result = (int*)malloc(n * sizeof(int));
    // Initialize the array with -1 to mark uninitialized indexes
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    // Loop through each element to assign a unique index
    for (int num = 0; num < n; num++) {
        // Generate a random index within the range [0, n-1]
        int index = rand() % n;
        // Find the next available (uninitialized) index
        while (result[index] != -1) {
            index = rand() % n;
        }
        // Assign the current number to the chosen index
        result[index] = num;
    }
    // Return the resulting array of unique random indexes
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
        // Generate a random index within the range [0, i]
        int j = rand() % (i + 1);
        // Swap the values at positions i and j
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    // Return the resulting shuffled array
    return result;
}

// Main function
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

    // Loop through each size in the array
    for (int i = 0; i < num_sizes; i++) {
        // Retrieve the current size from the array
        int size = sizes[i];
        // Print the current size for reference
        printf(" Size: %5d ", size);

        // Variables to measure CPU time
        clock_t start, end;
        double cpu_time_used;
        // Pointer to store the resulting array
        int* result;

        // Measure time for randomNumbers
        start = clock();
        // Generate an array of unique random numbers
        result = randomNumbers(size);
        end = clock();
        // Calculate CPU time used and print it
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        // Display the result (commented out for brevity)
        // showList(size, result);
        // Free allocated memory to prevent memory leaks
        free(result);

        // Measure time for randomIndexes
        start = clock();
        // Generate an array of unique random indexes
        result = randomIndexes(size);
        end = clock();
        // Calculate CPU time used and print it
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        // Display the result (commented out for brevity)
        // showList(size, result);
        // Free allocated memory to prevent memory leaks
        free(result);

        // Measure time for randomShuffle
        start = clock();
        // Shuffle an array of values using Fisher-Yates algorithm
        result = randomShuffle(size);
        end = clock();
        // Calculate CPU time used and print it
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("%12.4f", cpu_time_used);
        // Display the result (commented out for brevity)
        // showList(size, result);
        // Free allocated memory to prevent memory leaks
        free(result);

        // Print a newline to separate rows in the table
        printf("\n");
    }
    // Print a newline at the end for better formatting
    printf("\n");
    // Return 0 to indicate successful execution
    return 0;
}
