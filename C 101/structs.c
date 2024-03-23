#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//What is a struct?

/* Struct is a data structure that can store groups of data types
(like string, int, double all together)*/

//What is a struct used for?
/*To model real world entities like a student: */
struct Student{ //struct has Capital letter like Classes in OOP

//TEMPLATE FOR A STUDENT (different attributes of a student)
        char name[100];
        char major[100];
        double grade;
        int age;
    }; //struct compensate the limitation of a C-array where you can only store similar data types in the array

int main(){
    //Creating an actual student with a student container 
    struct Student student1;
    {   
        /* data */
        student1.age = 22;
        student1.grade = 3.78;
        /*Since an string is just an array [] of characters,
        we cannot randomly assign values to it, so we use strcpy() function*/
        strcpy(student1.name, "Abid");
        strcpy(student1.major, "Physics");
    };

    struct Student student2;

    {
        /* Student 2 data */
        student2.age = 19;
        student2.grade = 3.50;
        strcpy(student2.name, "Elli");
        strcpy(student2.major, "Politics");
    }

    printf("%s\n",student1.name);
    printf("%s\n",student1.major);
    printf("%f\n",student1.grade);
    printf("%d\n\n",student1.age);

    printf("%s\n",student2.name);
    printf("%s\n",student2.major);
    printf("%f\n",student2.grade);
    printf("%d\n",student2.age);






    return 0;
}