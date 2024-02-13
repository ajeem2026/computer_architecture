#include <stdio.h>
#include <math.h>

int main() {
    float x = 1.0e38; // A large floating-point number
    
    // Multiply by a value to cause overflow
    float result = x * 1.0e10;
    
    printf("Result: %e\n", result);
    printf("Is result infinity? %d\n", isinf(result)); // Check if result is infinity
    
    return 0;
}
