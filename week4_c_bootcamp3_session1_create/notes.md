Creating a file

FILE *file = fopen (filename, "w");

"w" means writing
fopen means open file
FILE *file produces a FILE pointer

r READ file
w Write to file
a Append to file
r+ read and write, from beginning
w+ read and write, overwriting
a+ read and write, appending