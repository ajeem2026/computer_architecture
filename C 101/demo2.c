#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()

{
    
    char name[20];
    int age;
    char school[20];

    printf("What is your name?\n");
    fgets(name, 20, stdin);
    printf("Where do you go to school?\n");
    scanf("%s", school);  
    printf("What is your age?\n");
    scanf("%d", &age);

    printf("Welcome to my first C program %s! You are %d years old and you study at %s.", name, age, school);

    return 0;
     
}