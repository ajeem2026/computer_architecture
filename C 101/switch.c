// Here we learn about switch statements
// Switch statements are basically a special type of if-statement
// The 'speacial' part is that swtich statements help us compare ONE specific value to a 
//... bunch of other values
#include <stdio.h>
#include <stdlib.h>

int main (){

    char grade = 'F';

// we could do all this with if-statements, but this is more concise 
switch (grade) {

case 'A':
    printf("You did great!");
    break; // it'll keep checking the cases below if we don't put the break statement

case 'B':
    printf("You did okay!");
    break;

case 'C':
    printf("You did poorly.");
    break;
case 'D':
    printf("Need for improvement!");
    break;
case 'F':
    printf("You failed to prepare.");
    break;

//default is like else-statement
default: 
    printf("Invalid grade");
}
}