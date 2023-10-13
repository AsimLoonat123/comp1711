#include <stdio.h>

int main() 
{
    //initialise an array for 10 integer values (0 to 9)
    int a [10];
    int count;

    //populate an array
    for (count = 0; count < 10 ; count++)
    {
        //populates the values 0, 11, 22, 33 etc.
        a[count] = count * 10 + count;
    }

    //read a[0] and a[1]
    printf("The first and second elements are %d and %d\n", a[0], a[1]);
    printf("Or, via pointers, %d and %d\n", *a, *(a+1));

    return(0);
}