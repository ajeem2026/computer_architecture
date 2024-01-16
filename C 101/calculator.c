#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    printf("Welcome to my calculator!\n");
    double num1;
    double num2;

    printf("Enter your first number: ");
    scanf("%lf", &num1);

    printf("Enter your second number: ");
    scanf("%lf", &num2);

    double result= num1+num2;

    printf("The result is: %f\n", result);

    return 0;


}