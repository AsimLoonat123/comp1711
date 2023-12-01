#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

#define bufferr_size 1000
#define stdin stdin

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
    char line[bufferr_size];
   char filename[bufferr_size];
   int i = 0;
   FILE *input = NULL;
   FITNESS_DATA fitnessData[bufferr_size];
    while (1) {
        char menuOption;
        printf("Please select an option from below:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        scanf("%s", &menuOption);
        while (getchar() != '\n');

        

        switch(menuOption)
        {
            case 'A':
            case 'a':
                printf("Please specify the filename to be imported: ");
                fgets(line, bufferr_size, stdin);
                sscanf(line, " %s ", filename);
                input = fopen(filename, "r");
                
                if (!input) {
                    printf("Error opening the file.\n");
                    return 1;
                }
                else {
                    printf("File loaded.\n");
                }
                fclose(input);
            break;
            case 'B':
            case 'b':
                input = fopen(filename, "r");
                int recordNumber = numberOfRecords (input, i);
                printf("%d\n", recordNumber);
                fclose(input);
                break;
            case 'C':
            case 'c':
            printf("C has been selected!\n");
            break;
            case 'D':
            case 'd':
            printf("D has been selected\n");
            break;
            case 'E':
            case 'e':
            printf("E has been selected\n");
            break;
            case 'F':
            case 'f':
            printf("F has been selected\n");
            break;
            case 'Q':
            case 'q':
                return 0;
            
            default: 
                printf("Invalid choice. Try again.\n");
                break;
            }
    
    }
}