#include <stdio.h>

int main()
{
    int array[5];
    int count, input, sum = 0;

    for (count = 0; count < 4 ; count++)
    {
        printf("Please input integer %d:\n", count);
        scanf("%d", &input);
        array[count] = input;
        sum = sum + array[count];
    }

    printf("The sum is: %d\n", sum);

    return(0);
}