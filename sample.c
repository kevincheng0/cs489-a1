#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

		struct stat fileStat;

    if (stat(argv[1], &fileStat) != 0) {
        fprintf(stderr, "Cannot access file address.\n");
        return -1;
    }

    printf("The file size is: %d bytes\n", (int)fileStat.st_size);
}
