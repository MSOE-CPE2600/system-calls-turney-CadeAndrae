/**************************************************************
Filename: finfo.c 
Description: Displays the file information about a given file
provided via the command line.
Author: Cade Andrae
Date: 11/16/24
Compile Instructions: gcc finfo.c -o finfo
Test Instructions:
      - Usage: ./finfo <file_path>
**************************************************************/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h> 

// Determines and prints the type of file
void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) { 
        printf("File type: Regular file\n");
        } else if (S_ISDIR(mode)) {
            printf("File type: Directory\n");
        } else if (S_ISLNK(mode)) {
            printf("File type: Symbolic link\n");
        } else {
            printf("File type: Other\n");
        }
    }

// Prints the permission settings of the file
void print_permissions(mode_t mode) {
    printf("Permissions: ");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

// Takes a file path as a command-line argument, retrieves info, and prints details
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) == -1) {
        perror("Failed to get file info");
        return EXIT_FAILURE;
    }

    print_file_type(fileStat.st_mode);
    print_permissions(fileStat.st_mode);
    printf("Owner UID: %d\n", fileStat.st_uid);
    printf("File Size: %ld bytes\n", fileStat.st_size);

    char buffer[80];
    struct tm *timeInfo = localtime(&fileStat.st_mtime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeInfo);
    printf("Last Modification: %s\n", buffer);

    return 0;
}