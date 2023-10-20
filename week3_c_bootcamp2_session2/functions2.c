#include <stdio.h>

float sum (int a, int b)
{
    float answer;
    answer = a + b;
    return answer;
}

int main()
{
    int y = 2;
    //call the function sum and set a as 5 and b as y
    float z = sum(5, y);

    printf("The sum of 5 and %d is %f\n", y, z);
    
    return 0;
}