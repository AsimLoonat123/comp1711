#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#define bufferr_size 1000
#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;


int numberOfRecords (FILE *inputFile, int numberOfRecords)
{
    char line_buffer[bufferr_size];
    //loop while the line being checked isn't empty then loop to the next line of the file
    while (fgets(line_buffer, bufferr_size, inputFile) != NULL)
    {
        //increment numberOfRecords so that the total number of records can be counted as each line is 1 record
        numberOfRecords++;   
    }
    //print the total number of records in the file
    return numberOfRecords;
}


// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H