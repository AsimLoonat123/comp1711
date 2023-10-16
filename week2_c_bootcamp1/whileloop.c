#include <stdio.h>
int main() {
    //a is initialised to zero 
    int a = 0;

    //only enters the while loop if a < 5
    while (a < 5){

        printf("a is equal to %d\n", a);
        //increment a
        a++;
    }
    printf("I've finished the loop and a is equal to %d\n", a);

    return(0);
}