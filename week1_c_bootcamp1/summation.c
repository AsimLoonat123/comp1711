#include <stdio.h>

int main() {
    //declare variables as integers
    int a, b, c;
    
    //prompt user input for first integer
    printf("Enter the first integer: \n");

    //take user input
    scanf("%d", &a);

    //prompt user input for second integer
    printf("Enter the second integer: \n");

    //take second user input
    scanf("%d", &b);

    //summation and then store into variable c
    c = a + b;

    //display the result of the summation
    printf("The sum is: %d\n", c);

    return 0;
}