#include <stdio.h>

int main()
{
    int a;
    printf("Please enter a number to be checked:\n");
    scanf("%d", &a);

    if (a % 4 == 0 && a % 5 == 0)
    {
        printf("This number is divisible by both 4 and 5\n");
    }
    else
    {
        printf("This number isn't divisible by both 4 and 5\n");
    }

    return 0;
}