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

    //initialise the variables
    int buffer_size = 1000, numberOfRecords = 0, i = 1, stepsint, n = 1;
    char line_buffer[buffer_size], record[buffer_size], date[1000], time[1000], steps[1000];

    //initialise the struct
    FITNESS_DATA fitnessData [] = {
    };
    
    //loop while the line being checked isn't empty then loop to the next line of the file
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        //increment numberOfRecords so that the total number of records can be counted as each line is 1 record
        numberOfRecords++;

        //tokenise each line of the line into three separate variables
        tokeniseRecord(line_buffer, ",", date, time, steps);

        //convert steps to an integer
        stepsint = atoi(steps);

        //assign the date, time and steps to an element of an array in the struct
        strcpy(fitnessData[i].date, date);
        strcpy(fitnessData[i].time, time);
        fitnessData[i].steps = stepsint;
        
        //increment i so that the date, time and steps are assigned to the next element of the array
        i++;
        
    }

    //print the total number of records in the file
    printf("Number of records in file: %d\n", numberOfRecords);
    
    //loop three times
    for (n=1; n<60; n++) {
        //print the date, time and steps separated by /
        printf("%s/%s/%d\n", fitnessData[n].date, fitnessData[n].time, fitnessData[n].steps);          
    }

    //close the file
    fclose(file);
    return 0;

}