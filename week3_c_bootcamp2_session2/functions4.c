#include <stdio.h>

//the function to convert fahrenheit to celsius takes a float variable 
float fahr_to_celsius (float f_temp)
{
    float c_temp;
    //calculates the conversion
    c_temp = (f_temp - 32)/1.8;
    //returns a float variable c_temp
    return c_temp;
}

//the function to convert fahrenheit to kelvin
float fahr_to_kelvin (float f_temp)
{
    float k_temp;
    //calculates the conversion
    k_temp = fahr_to_celsius(f_temp) + 273.15;
    //returns the temperature in kelvin
    return k_temp;
}

int main () 
{
    float fahrenheit;
    char option;

    printf ("Enter a temperature to convert in Fahrenheit:\n");
    scanf ("%f", &fahrenheit);
    
    //outputs a menu-style option system
    printf ("\n");
    printf ("Select A to convert to Celsius\n");
    printf ("Select B to convert to Kelvin\n");
    printf ("Select Q to quit\n");

    //this space before the %c is very important without it, the scan command doesnt work
    // because it takes your previous keystroke which would be the enter key
    scanf(" %c", &option);

    //depending on what option the user chose it calls the relevant function for the conversion
    switch (option)
    {
        case 'A': printf ("Converted to degrees Celsius: %f\n", fahr_to_celsius(fahrenheit));
                  break;

        case 'B': printf ("Converted to Kelvin: %f\n", fahr_to_kelvin(fahrenheit));
                  break;

        case 'Q': break;

        default:  break;
    }

    return 0;
}