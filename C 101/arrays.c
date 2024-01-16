#include <stdio.h>
#include <stdlib.h>

int main()

{
    //Arrays are very useful data structures for storing things of same type
    int luckyNumbers [] = {7, 14 , 15, 16, 17, 18, 19, 20, 21};
    //conceptually, arrays are just a collection of variables
    printf("Now my lucky number is: %d\n", luckyNumbers[2]);
    luckyNumbers[2]= 130000;
    printf("Oh goodness! It changed to %d", luckyNumbers[2]);

    //Here we define the memory allocation of an array
    int capacity[10];

    capacity[0]= 1;
    capacity[1]= 10;
    capacity[2]= 20;

    //Strings are just an array of characters:
    char phrase[] = "Arrays";



    return 0;

}