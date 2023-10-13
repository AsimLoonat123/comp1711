use gcc to compile

#include <stdio.h> include the Standard IO library
int main() {            #defines the main function
    int a = 10;         #defines an integer variable a and initialises it to 10
    printf("%d", a);    #format-prints the value of a as an integer (%d is a format specifier)
    return 0;           #returns from function with error code zero ("success")
}



CTRL + S before compiling with gcc
use code whatever.c to create another C codespace

%c single char
%s string
%d decimal integer
%f a floating point number for floats