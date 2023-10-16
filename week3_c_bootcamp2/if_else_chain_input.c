#include <stdio.h>
int main()
{
    int mark;

    //asks the user to input the mark
    printf("Enter the mark: \n");
    //takes user input of the mark
    scanf("%d", &mark);

    if (mark == 0)
    {
        printf("The mark of %d is zero\n", mark);
    }
    else if (mark < 40)
    {
        printf("The mark of %d is a fail\n", mark);
    }
    else
    {
        printf("The mark of %d is a pass\n", mark);
    }
    return 0;
}