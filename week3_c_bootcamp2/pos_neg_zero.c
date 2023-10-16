#include <stdio.h>

int main()
{
    int a;
    printf("Please enter a number to be checked:\n");
    scanf("%d", &a);

    if (a == 0)
    {
        printf("The number, %d, is zero\n", a);
    }
    else if (a > 0)
    {
        printf ("The number, %d, is positive\n", a);
    }
    else 
    {
        printf("The number, %d, is negative\n", a);
    }

    return 0;
}