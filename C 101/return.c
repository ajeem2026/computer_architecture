#include <stdio.h>
#include <stdlib.h>

double cube (double num){
    // double result= num*num*num;
    // return result;
    return num*num*num;
    //return breaks out of the function
    printf("\n================================");//this will never get touched
}

//function prototype: just the signature
//double cube(double num);

int main(){

    double input;
    printf("Enter a number: ");
    scanf("%lf",&input);

    //when the code reaches cube(), it will execute the code above and return the result
    printf("This is the number cubed: %f\n", cube(input));
    return 0;
}