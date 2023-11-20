#include <stdio.h>

void printArray(int a[][3] ){
  for (size_t i = 0; i <= 1; ++i) {
     for (size_t j = 0; j <= 2; ++j) {
        printf("%d ", a[i][j]);
     }
     printf("\n"); // start new line of output 
     }
}

int main() {
  //initialises the array
  int array1[2][3] = {{1, 2, 3}, {4, 5, 6}}; //the square brackets contain the dimensions of the array [m][n] where the minimum of m and n is 1
  printf("Values in array1 by row are:\n");
  printArray(array1);

  int array2[2][3] = {1, 2, 3, 4, 5}; //passing each element in order where the final element is assumed to be a zero as it hasn't been given a value
  printf("Values in array2 by row are:\n");
  printArray(array2);


  int array3[2][3] = {{1, 2}, {4}};
  printf("Values in array3 by row are:\n");
  printArray(array3);
  
  int array4[2][3] = {{26, 05, 2005}, {16, 07, 2001}};
  printf("Values in array4 by row are:\n");
  printArray(array4);

  return 0;
}