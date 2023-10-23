#include <stdio.h>
//allows you to use the atoi command
#include <stdlib.h>

int main()
{
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) 
    {
        perror("");
        return 1;
    }
    //if the buffer size is too small, only the beginning of the line will be read
    int buffer_size = 100; //should be larger than the longest line plus one extra character
    char line_buffer[buffer_size];
    //fgets reads the file line by line into a buffer 
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        //printf("%s", line_buffer);
        printf("%d\n", atoi(line_buffer)); //or printf("%d\n", atoi(line_buffer)) which only works if all the lines contain integer values check notes.md for more
    }

    fclose(file);
    return 0;
}