//these are header files
#include <stdio.h> 
#include <stdlib.h> // Defines exit().

//mode() generalises the function to all cases
FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("");
        exit(1); //exits program with return status 1
    }
    return file;
}

int main() {
    char filename [] = "data.txt";
    //call the file with a filename and an access mode type
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}