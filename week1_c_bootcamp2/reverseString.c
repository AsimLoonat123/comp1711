#include <stdio.h>

int main()
{
    char hello[] = "Hello";
    int length = 0;

    //loops between 5 and 0 
    for (i=5; i>=0; i--)
    {
        //prints the elements 5 to 0
        printf("%c", hello[i]);
    }

    printf("\n");
    return(0);
}