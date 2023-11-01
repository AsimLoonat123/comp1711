#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    //open the file in read mode
    FILE *file = fopen("FitnessData_2023.csv", "r");

    //if the file contains nothing then give an error message
    if (file == NULL) 
    {
        perror("");
        return 1;
    }

    int buffer_size = 1000, numberOfRecords = 0, i = 0;
    char line_buffer[buffer_size], record[buffer_size];

    //fgets(line_buffer, buffer_size, file);
    //prints the first line of the file:
    //printf("%s", line_buffer);
    

    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        numberOfRecords++;
        printf("%s", line_buffer);
        //i++;
        //record[i] = line_buffer;
    }
    //fgets(line_buffer, buffer_size, file)
    //prints each line of the file
    //while (fgets(line_buffer, buffer_size, file) != NULL)
    //{
    //    printf("%s", line_buffer);
        //printf("%d\n", atoi(line_buffer)); //or printf("%d\n", atoi(line_buffer)) which only works if all the lines contain integer values check notes.md for more
    //}
    
    //printf("%s", record);
    //tokeniseRecord(line_buffer, ",", date, time, steps);
    //FITNESS_DATA fitnessData [] = {
    //    {date, time, steps}
    //};
    //printf("Number of steps in line 1 is: %s\n", steps[1]);
    printf("Number of records in file: %d\n", numberOfRecords);
    fclose(file);
    return 0;

}