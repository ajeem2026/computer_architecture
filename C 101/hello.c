#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// % is the format specifier
// %f diye 5/4 korle answer integer ey ashbe unless you use 5/4.0
//const vars have UPPERCASE names 
//for double: lf in &scan and %f in printf
//for string: no & needed in scanf
int main()
{
    char name[20];
    double networth;
    printf("Enter your grade: ");
    //to store information in a variable you need
    //to use & to dictate a pointer to the variable
    //scanf gives up after it sees a space 
    //tai we use fgets (varName, number of characters, input er jayga)
    fgets(name, 20, stdin); 

    printf("Enter your networth: ");
    scanf("%lf",&networth);

    printf("My name is %s and your value is %f.", name, networth);

    return 0;

}