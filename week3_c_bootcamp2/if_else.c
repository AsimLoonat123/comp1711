#include <stdio.h>

int main() {
    //initialise variable to 40
    int mark = 40;

    //check if mark >= 40
    if (mark >= 40){
        //if TRUE print the "passed" message
        printf("The mark of %d is a pass\n", mark);
    }
    else {
        //if FALSE print the "failed" message
        printf("The mark of %d is a fail\n", mark);
    }
    
    return(0);

}