#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>

FILE *open_file(char filename[], char mode[]);

#endif /* UTILS_H */

//GUARDS to prevent double inclusions
//files that use this header must include it with #include "utils.h"
//other headers should be included here