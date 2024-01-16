#include <stdio.h>
#include <stdlib.h>

//defining a function that returns nothing
void sayHi(){
    printf("Hello User!\n");
}

//defining a function with one parameter
void sayHello(char name[]){
    printf("Hello %s!\n", name);
}

//defining a function with multiple parameters
void sayAll(char name[], int age){
    printf("Hello %s! You are %d years old.\n", name, age);
}

//Main function is the one that gets called when we run our program
//If we want to call other functions, we must call them inside main function
int main(){
//Calling the function that we defined below 

    printf("This gets executed first.\n");
    //then it jumps below the function that we defined
    sayHi();
    sayHello("Abid");
    sayAll("Abid", 20);
    printf("This gets executed last.\n");
    return 0;
}

/*Cannot define a function after main anymore
if you do want to define a function after main, you can use a function prototype:
Function prototype
void sayHi(); */


