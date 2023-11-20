#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printColumn(int a[][4], int colIndex, int rows, char when) {
    switch (when) {
        case 'B':
            printf("Values in column %d before change:\n", colIndex); break;

        case 'A':
            printf("Values in column %d after change:\n", colIndex); break;

        default: 
            printf("Invalid option\n");
            return;
    }

    for (int i = 0; i < rows; ++i) { //i < rows because rows starts at 1 but indexing starts at 0 so the column is column 3 but indexed by 2
        printf("%d\n", a[i][colIndex]);
    }
}

void changeColumn(int a[][4], int colIndex, int rows, int newValue) {
    for (int i = 0; i < rows; ++i) {
        a[i][colIndex] = newValue;
    }
}

int main() {
    //this is the array at the start
    int array1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int colIndexToChange = 2; // Change the values in the third column (column at index 2)
    int newValue = 19, i = 0;

    //print the column that is going to change
    printColumn(array1, colIndexToChange, 3, 'B'); // 'B' stands for Before
    
    //change the elements in the column
    changeColumn(array1, colIndexToChange, 3, newValue);
    
    //print the column after the change
    printColumn(array1, colIndexToChange, 3, 'A'); // 'A' stands for After

    srand(time(NULL));

    int arrayA[3][4] = {
        {rand() % 10, rand() % 10, rand() % 10},
        {rand() % 10, rand() % 10, rand() % 10},
        {rand() % 10, rand() % 10, rand() % 10}
    };

    int arrayB[3][4] = {
        {rand() % 10, rand() % 10, rand() % 10},
        {rand() % 10, rand() % 10, rand() % 10},
        {rand() % 10, rand() % 10, rand() % 10}
    };

    int arrayC[3][4] = {};

    for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", arrayA[i][j]);
     }
     printf("\n"); // start new line of output 
     }
    
    for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", arrayB[i][j]);
     }
     printf("\n"); // start new line of output 
     }

    for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        arrayC[i][j] = arrayA[i][j] * arrayB[i][j];
        printf("%d ", arrayC[i][j]);
     }
     printf("\n"); // start new line of output 
    }

    //printColumn(arrayA, colIndexToChange, 3, 'B');


    return 0;
}