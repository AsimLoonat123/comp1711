#include <stdio.h>
int main()
{
    int a;
    a=2;

    //switch with variable being checked in brackets
    switch (a)
    {
        //if a is 0 then:
        case 0: printf("Option 0 has been selected\n");
        //break concludes a case 
        break;
        
        //if a is 1 then:
        case 1: printf("Option 1 has been selected\n");
        break;

        //if a is anything else then:
        default: printf("A different option has been selected\n");
    }
    return 0;
}
