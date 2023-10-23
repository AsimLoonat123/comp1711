#include <stdio.h>

int main() 
{
    //opening a file (fopen) produces a FILE pointer
    char filename[] = "data.txt";
    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    //an error produces a NULL pointer
    if (file == NULL)
    {
        //error message incase anything goes wrong
        perror("");
        return 1;
    }

    //close file
    fclose(file);
    return 0;
}