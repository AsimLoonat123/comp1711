#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
        //initialise the variable menuOption as a character
        char menuOption;
        //print the menu
        printf("Please select an option from below:\n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        //ask the user for the input
        scanf("%s", &menuOption);
        //clear the bit where the user types so that when fgets is used later, the enter key isn't taken
        while (getchar() != '\n');

        

        switch(menuOption)
        {
            case 'A':
            case 'a':
                printf("Input filename: ");
                //get a character from the user
                fgets(line, bufferr_size, stdin);
                sscanf(line, " %s ", filename);
                //try open the file that the user has specified in read-only mode
                input = fopen(filename, "r");
                //if the file is empty or there is something wrong with the file print an error message
                if (!input) {
                    printf("Error: could not open file\n");
                    return 1;
                }
                //close file
                fclose(input);
            break;
            case 'B':
            case 'b':
                //open the file that the user has specified
                input = fopen(filename, "r");
                //call the function numberOfRecords and specify the two parameters of the file name and i
                //store the result as recordNumber
                int recordNumber = numberOfRecords (input, i);
                //print the record number
                printf("Total records: %d\n", recordNumber);
                //close file
                fclose(input);
                break;
            case 'C':
            case 'c':
                //open the file that the user has specified
                input = fopen(filename, "r");
                //initialise the variables
                int numberOfRecords = 0, i = 1, stepsint, n = 1;
                char line_buffer[bufferr_size], date[500], time[500], steps[500];
                const char *delimiter = ",";
                //loop while the line being checked isn't empty then loop to the next line of the file
                while (fgets(line_buffer, bufferr_size, input) != NULL)
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
                int fewestSteps;
                int lineWithFewestSteps=1;
                //set the fewest steps to be the steps of the first line
                fewestSteps = fitnessData[1].steps;
                //only looping from 2 because it needs to check if the second line's steps is less than the first
                for (n=2; n<numberOfRecords+1; n++) 
                {
                    //update the line that contains the fewest steps and also the value of the fewest steps if the line being checked has less steps than the current fewest steps
                    if (fitnessData[n].steps < fewestSteps)
                    {
                        fewestSteps = fitnessData[n].steps;
                        lineWithFewestSteps = n;
                    }
                    
                }
                //output the date and time that has the fewest steps
                printf("Fewest steps: %s %s\n", fitnessData[lineWithFewestSteps].date, fitnessData[lineWithFewestSteps].time);
                //close file
                fclose(input);
            break;
            case 'D':
            case 'd':
                //open the file that the user has specified
                input = fopen(filename, "r");
                //initialise the variables
                numberOfRecords = 0, i = 1, stepsint, n = 1;
                line_buffer[bufferr_size], date[500], time[500], steps[500];
                //loop while the line being checked isn't empty then loop to the next line of the file
                while (fgets(line_buffer, bufferr_size, input) != NULL)
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
                int largestSteps;
                int lineWithLargestSteps=1;
                //set the largest steps to be the steps of the first line
                largestSteps = fitnessData[1].steps;
                //only looping from 2 because it needs to check if the second line's steps is more than the first
                for (n=2; n<numberOfRecords+1; n++) 
                {
                    //update the line that contains the fewest steps and also the value of the fewest steps if the line being checked has less steps than the current fewest steps
                    if (fitnessData[n].steps > largestSteps)
                    {
                        largestSteps = fitnessData[n].steps;
                        lineWithLargestSteps = n;
                    }
                    
                }
                //output the date and time that has the largest number of steps
                printf("Largest steps: %s %s\n", fitnessData[lineWithLargestSteps].date, fitnessData[lineWithLargestSteps].time);
                //close file
                fclose(input);
            break;
            case 'E':
            case 'e':
                //open the file that the user has specified
                input = fopen(filename, "r");
                //initialise the variables
                numberOfRecords = 0, i = 1, stepsint, n = 1;
                line_buffer[bufferr_size], date[500], time[500], steps[500];
                //loop while the line being checked isn't empty then loop to the next line of the file
                while (fgets(line_buffer, bufferr_size, input) != NULL)
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
                float sumOfSteps = 0;
                float mean = 0;
                for (n=1; n<numberOfRecords+1; n++) 
                {
                    //add up the number of steps in the file
                    sumOfSteps = sumOfSteps + fitnessData[n].steps;
                }
                //calculate the mean by dividing the total sum of the steps by the total number of records
                mean = sumOfSteps / numberOfRecords;
                int intMean;
                intMean = roundf(mean);

                printf("Mean step count: %d\n", intMean);
                //close file
                fclose(input);
            break;
            case 'F':
            case 'f':
                //open the file that the user has specified
                input = fopen(filename, "r");
                //initialise the variables
                numberOfRecords = 0, i = 1, stepsint, n = 1;
                line_buffer[bufferr_size], date[500], time[500], steps[500];
                //loop while the line being checked isn't empty then loop to the next line of the file
                while (fgets(line_buffer, bufferr_size, input) != NULL)
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
                int numberOfRecordsOver500 = 0, maxNumberOfRecordsOver500 = 0, period = 0, startOfPeriod = 0, endOfPeriod, lengthOfPeriod = 0, maxLengthOfPeriod = 0;
                for (n=1; n<numberOfRecords+1; n++) 
                {
                    if (fitnessData[n].steps > 500)
                    {
                        lengthOfPeriod++;
                    }
                    else
                    {
                        if (lengthOfPeriod > maxLengthOfPeriod)
                        {
                            maxLengthOfPeriod = lengthOfPeriod;
                            endOfPeriod = n-1;
                        }
                        lengthOfPeriod = 0;
                    }
                    startOfPeriod = endOfPeriod - maxLengthOfPeriod + 1;

                }
                period = 15 * maxNumberOfRecordsOver500;
                printf("Longest period start: %s %s\n", fitnessData[startOfPeriod].date, fitnessData[startOfPeriod].time);
                printf("Longest period end: %s %s\n", fitnessData[endOfPeriod].date, fitnessData[endOfPeriod].time);
                //close file
                fclose(input);
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