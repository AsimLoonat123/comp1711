#include <stdio.h>

int main() {
    int a = 5, i = 0;
    
    //i tells you how many times the loop runs.
    //the first part (i=1) tells the starting value of i
    //the second part (i<5) says run less than 5 times (i.e. 4 times only)
    //i++ is the incrementor - it adds 1 to the value of i each time the loop repeats
    for (i=1; i<5; i++) {

        //print i as an integer and print a line after
        printf("%d\n", i);

    }

    return(0);
}