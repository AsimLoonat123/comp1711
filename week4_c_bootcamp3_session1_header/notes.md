header file doesnt contain the actual function

the implementation file contains the actual function and is called by the header file

to compile:

gcc -c utils.c //will produce utils.o
gcc -c create_file_h.c //will produce create_file_h.o
gcc create_file_h.o utils.o -o create_file