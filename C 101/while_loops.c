#include <stdio.h>
#include <stdlib.h>

int main(){

    int index=6;

    //loop through all the code as long as this condition is true
    while (index <= 5){
        //when index=6, we move on with our lives in the program
        printf("This is your current index: ");
        printf("%d\n", index);
        index++;
        //after this line C goes back up to check our condition
    }


    //What is an infinite loop?

    /*When you put in such a condition whereby the while-loop never becomes false*/
    while (index <= 5){
        //Here, we can't move on with our lives 
        //so the pain continues till infinity
        printf("This is your current index: ");
        printf("%d\n", index);
        // index++;
    }

    //What is a useless while loop?

    // int index =6;

    //This will print nothing because entering condition is not satisfied
    while(index <= 5){
        printf("%d\n", index);
        index++;
    }

    //What is a do-while loop?
    /*A loop where we can enter once, irrespective of entering condition being satisfied.
    To code this, just send "while ()" to the backside of your loop body*/

    //enter first, check later!
    do{
        printf("%d\n", index);
        index++;
    //Here, we do what's inside the loop before checking the entering condition
    } while(index <= 5);

    return 0;
}