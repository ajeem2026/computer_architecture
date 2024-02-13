#include <stdio.h> 
  
float fahrenheit_to_celsius(float f) 
{ 
    return ((f - 32.0) * 5.0 / 9.0); 
} 
  
int main() 
{ 
    float f = 32; 
  
    // Passing parameter to function 
    printf("Temperature in Degree Celsius : %0.2f\n", 
           fahrenheit_to_celsius(f)); 
    return 0; 
}
