#include <stdio.h>

int main() {
    //open the file in read mode
    FILE *file = fopen("FitnessData_2023.csv", "r");

    //if the file contains nothing then give an error message
    if (file == NULL) 
    {
        perror("");
        return 1;
    }

    int buffer_size = 1000, i, count = 0, sum;
    char line_buffer[buffer_size], record[buffer_size];
    

    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        count++;
    }


    printf("%d", count);
    fclose(file);
    return 0;
}