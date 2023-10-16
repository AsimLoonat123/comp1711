#include <stdio.h>
int main()
{
    int mark;

    printf("Enter the mark:\n");
    scanf("%d", &mark);
    printf("The mark to be checked is: %d\n", mark);

    //this check if mark is >= 0 AND <= 100
    if (mark >= 0 && mark <= 100)
    {
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
    }
    //if the input value is not between 0 and 100 then:
    else
    {
        //output the error message
        printf("Marks must be between 0 and 100\n");
    }

    return 0;
}