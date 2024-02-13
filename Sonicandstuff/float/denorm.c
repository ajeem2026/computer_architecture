#include <stdio.h>

int main() {
    float normalized = 1.23456789e-38; // Normalized floating-point number
    float denormalized = 1.23456789e-45; // Denormalized floating-point number
    
    printf("Normalized: %e\n", normalized);
    printf("Denormalized: %e\n", denormalized);
    
    return 0;
}
