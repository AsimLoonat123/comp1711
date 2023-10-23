#include <stdio.h>

int main()
{
    //open the file for writing
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("");
        return 1;
    }
    int number, num_lines = 10;
    printf("Type %d numbers: ", num_lines);
    for (int i = 0; i < num_lines; i++)
    {
        scanf("%d", &number);
        //file printf writes into a file
        fprintf(file, "%d\n", number); // the \n makes sure each new input is on a separate line
    }
    //close the file before returning
    fclose(file);
    return 0;
}