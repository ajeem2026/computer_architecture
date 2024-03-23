#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include <math.h>

typedef struct {
    uint32_t mantissa: 23;
    uint32_t exponent: 8;
    uint32_t sign: 1;
} FloatBits;

typedef union {
    float f;
    FloatBits bits;
} FloatUnion;

float calculateMantissa(uint32_t mantissaBits) {

    //Here, we start with the implicit leading 1 in the normalized form
    float mantissa = 1.0; 
    //Go over each bit to calculate the mantissa
    for (int i = 0; i < 23; i++) { 
        mantissa += ((mantissaBits >> i) & 1) * pow(2, i - 23);
    }
    return mantissa;

    //float mantissa = 1.0f; 
    // // Go over each bit to calculate the mantissa
    // for (int i = 0; i < 23; i++) {
    //     // Extract the bit at the ith position from the right
    //     int mb = (mantissaBits >> i) & 1;
    //     // Add the bit's value, scaled appropriately, to the mantissa
    //     mantissa += mb * pow(2, -1 * (i + 1));
    // }
    // return mantissa;
}

int calculateExponent(uint32_t exponentBits) {
    //Another formula implementation step
    //Subtract the bias (127 for single-precision) to get the actual exponent value
    //return (int)exponentBits - 127;
    int exponent = 0;
    //int ep;
    //Bit shifting approach 
    //visit each one of them to see if they're set correctly using a for-loop
    for(int i = 0; i < 8; i++) {
        //we go right to left 
        //1001 0110 < look at 0 then 1 then 1 then 0
        int ep=(exponentBits>>i)&1; //right shift
        exponent=exponent+ (ep<<i);
    }
    return exponent-127;

}

bool isNormalized(float number) {
    FloatUnion fu;
    fu.f = number;
    //Here we setup a boolean condition to check if the number is normalized
    //a float is normalized if the exponent isn't all zeros or all ones (denormalized, infinity, or NaN)
    return !(fu.bits.exponent == 0 || fu.bits.exponent == 255);
}



float toDecimal(FloatUnion fu) {
    //first, check if the floating-point number is normalized
    //number considered normalized if its exponent is neither all zeros nor all ones
    //if not number is not normalized, it could be a denormalized number, infinity, or Not-a-Number (NaN)
    if (!isNormalized(fu.f)) {
        return NAN; 
    }

    //mantissa is computed by interpreting the mantissa bits as a fraction
    //where each bit represents a negative power of 2, starting from 2^-1 for the most significant bit
    //an mplicit leading 1 (for normalized numbers) is added at the beginning (represented by 1.0 here)
    float mantissa = calculateMantissa(fu.bits.mantissa);

    //exponent is stored in a biased form, where the bias for single-precision is 127
    //we subtract this bias from the value represented by the exponent bits for the actual exponent
    int exponent = calculateExponent(fu.bits.exponent);

   
    //The result represents the floating-point number in decimal form
    float decimal = mantissa * pow(2, exponent);

    //if the sign bit is 1, the number is negative; multiply by -1 to make the decimal value negative
    //if the sign bit is 0, the number is positive; return the decimal value as is
    return fu.bits.sign ? -decimal : decimal;
}


int main() {
    FloatUnion fu;
    printf("Enter a floating-point number: ");
    scanf("%f", &fu.f);

    if (!isNormalized(fu.f)) {
        printf("The number is not a normalized floating-point number.\n");
        return 1;
    }

    printf("Stored as a floating-point number (bit-level representation): ");
    printf("%u ", fu.bits.sign);

    for (int i = 7; i >= 0; i--) {
        printf("%u", (fu.bits.exponent >> i) & 1);
    }
    printf(" ");

    for (int i = 22; i >= 0; i--) {
        printf("%u", (fu.bits.mantissa >> i) & 1);
    }
    printf("\n");

    float decimalValue = toDecimal(fu);
    printf("Converted back to decimal: %f\n", decimalValue);

    return 0;
}
