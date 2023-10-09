#include <stdio.h> //include the standard IO library
int main() { //defines the main function
    char name[15]; //defines a character string called name that can contain up to 15 characters

    printf("Hello, please enter your name: "); //prints a message prompting a user input
    scanf("%s", name); //allows input in string format and stores in variable name
    printf("Your name is %s\n", name); //prints the phrase in quotes in place of the %s format specifier

    return 0;
}