#include <stdio.h>
#include <math.h>

int main() {
    // Create a special floating-point value with all ones in the exponent and a non-zero fraction
    unsigned int special_value_bits = 0b01111111111111111111111111111111; // All ones in exponent
    float special_value;
    memcpy(&special_value, &special_value_bits, sizeof(float)); // Convert bit pattern to float

    printf("Special value: %f\n", special_value);
    
    // Check if the special value is infinity or NaN
    if (isinf(special_value)) {
        printf("Special value is infinity\n");
    } else if (isnan(special_value)) {
        printf("Special value is NaN\n");
    } else {
        printf("Special value is neither infinity nor NaN\n");
    }

    return 0;
}
