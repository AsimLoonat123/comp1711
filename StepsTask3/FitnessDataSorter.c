#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

int tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
                if (strlen(ptr) <= 2)
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else 
    {
        return 1;
    }
    return 0;
}



int main() {
    char line[500];
    char filename[500];
    int i = 0;
    //initialise file as nothing
    FILE *input = NULL;
    //initialise the fitness data struct
    FitnessData fitnessData[500];
    //prompts user input
    printf("Enter Filename: ");
    fgets(line, 500, stdin);
    sscanf(line, " %s ", filename);
    //try open the file that the user has specified in read-only mode
    input = fopen(filename, "r");
    //if the file is empty or there is something wrong with the file print an error message
    if (!input) {
        printf("Error: could not open file\n");
        return 1;
    }
    //initialise the variables
    int numberOfRecords = 0, stepsint, n = 1;
    char line_buffer[500], date[500], time[500], steps[500];
    const char *delimiter = ",";
    //loop while the line being checked isn't empty then loop to the next line of the file
    while (fgets(line_buffer, 500, input))
    {
        //increment numberOfRecords so that the total number of records can be counted as each line is 1 record
        numberOfRecords++;
        int token = tokeniseRecord(line_buffer, ',', fitnessData[i].date, fitnessData[i].time, &fitnessData[i].steps);

        if (token == 1)
        {
            printf("Error: invalid file\n");
            return 1;
        }
                    
        //tokenise each line of the line into three separate variables
        tokeniseRecord(line_buffer, ',', fitnessData[i].date, fitnessData[i].time, &fitnessData[i].steps);
        i++;
                    
    }
    fclose(input);
    int k, j, temp_steps;
    char temp_time[500], temp_date[500];
    for (int k = 0; k < numberOfRecords - 1; k++) {
        for (int j = 0; j < numberOfRecords - k - 1; j++) {
            // If the element found is greater than the next element then swap them
            if (fitnessData[j].steps < fitnessData[j+1].steps) {
                // Swap the steps
                temp_steps = fitnessData[j].steps;
                fitnessData[j].steps = fitnessData[j+1].steps;
                fitnessData[j+1].steps = temp_steps;

                // Swap date
                strcpy(temp_date, fitnessData[j].date);
                strcpy(fitnessData[j].date, fitnessData[j+1].date);
                strcpy(fitnessData[j+1].date, temp_date);

                // Swap time
                strcpy(temp_time, fitnessData[j].time);
                strcpy(fitnessData[j].time, fitnessData[j+1].time);
                strcpy(fitnessData[j+1].time, temp_time);


            }
        }
    };
    strcat(filename, ".tsv");
    int l = 0;
    FILE *output = fopen(filename, "w");
    for (int l = 0; l < numberOfRecords; l++) {
        fprintf(output, "%s\t%s\t%d\n", fitnessData[l].date, fitnessData[l].time, fitnessData[l].steps);
    }
    //close files
    fclose(output);    
}