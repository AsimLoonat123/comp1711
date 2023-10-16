#include <stdio.h>
int main()
{
    int mark;
    printf("Please enter the mark:\n");
    scanf("%d", &mark);

    if (mark >= 70)
    {
        printf("This is a distinction!\n");
    }
    else if (mark >= 50)
    {
        printf("This is a pass!\n");
    }
    else 
    {
        printf("This is a fail!\n");
    }
    return 0;
}