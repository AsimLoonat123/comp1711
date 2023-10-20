#include <stdio.h>

//in the brackets are the parameters of the function (input of the function)
int sum (int a, int b)
{
    int answer;
    answer = a + b;
    return answer;
}

//main automatically gets called first by default
int main()
{
    int y = 2;
    //call the function sum and set a as 5 and b as y
    int z = sum(5, y);

    printf("The sum of 5 and %d is %d\n", y, z);
    
    return 0;
}




    