#include <stdio.h>
#include "convert.h"

int main()
{
    float f = 32;

    // Passing parameter to function
    printf("Temperature in Degree Celsius : %0.2f\n",
           fahrenheit_to_celsius(f));
    return 0;
}
