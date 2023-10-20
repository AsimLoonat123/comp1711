Notes for session 2
to call a function from main you must put hte function being called before main

i.e.

int sum()
{

}

int main()
{
    sum
}


Order matters, the compiler reads from top to bottom. 
A function needs to be defined before it is used in the program. 
That's easy in our simple programs so far bu tharder in more complex programs to ensure the funcions are all in the right order.
So C allows us to declare functions before they are used (‘forward declarations’)
A function declaration (sometime called a function prototype) is justthe definition of the function without the payload.
int sum (int a, int b);