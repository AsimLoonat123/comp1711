#include <stdio.h>

int main(){
    int mark = 37;

    //first check if mark is equivalent to (==)
    if (mark == 0)
    {
       //only if true print a "zero" message
       printf ("The mark of %d is zero\n", mark);
    }
    //otherwise check if mark < 40
    else if (mark < 40)
    {
        //if true then print the "fail" message
        printf("The mark of %d is a fail\n", mark);
    }
    //this is the "catch-all" statement if the others fail
    else
    {
        //print the "pass" message
        printf("The mark of %d is a pass\n", mark);
    }

    return 0;
}