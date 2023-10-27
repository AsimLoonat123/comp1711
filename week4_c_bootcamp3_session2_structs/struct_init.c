#include <stdio.h>
//define a struct outside a function
struct student 
{
    //has 3 fields, each with its own type
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark; //unsigned means that it is always positive
};

int main () {
    //new_student is the name of the variable
    //this is to initialise the individual fields
    struct student new_student = {"Name Surname", "28932123", 35};

    //.operator access the name variable
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}