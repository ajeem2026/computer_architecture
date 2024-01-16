#include <stdio.h>
#include <stdlib.h>

int main()

{
    char color[20];
    char noun[20];
    char celebrityF[20];
    char celebrityL[20];


    //no need to define a pointer variable in scanner for string

    /*is an array of characters, and when using %s in scanf, 
    it automatically knows to read the input into the array. 
    The array name itself represents the address of the first element in the array, 
    so you don't need the & operator.*/


    printf("Enter the name of your chosen color: ");
    scanf("%s", color);
    printf("Enter the name of your chosen noun: ");
    scanf("%s", noun);
    printf("Enter the name of your chosen celebrity: ");
    //an example of how C needs you to be very specific about
    //what the user can enter 
    scanf("%s", celebrityF);
    scanf("%s", celebrityL);


    printf("Roses are %s \n", color);
    printf("%s are blue\n", noun);
    printf("I love %s %s \n", celebrityF, celebrityL);

    return 0;

}