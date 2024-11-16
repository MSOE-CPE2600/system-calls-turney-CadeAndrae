/**************************************************************
Filename: pmod.c 
Description: Modifies its own priority to REDUCE it by 10 , 
sleeps for 1,837,272,638 nano seconds, and prints a goodbye 
message and exits.
Author: Cade Andrae
Date: 11/16/24
Compile Instructions: gcc pmod.c -o pmod
Test Instructions:
      - Usage: ./pmod
**************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

int main() {
    // Lower priority by 10
    if (nice(10) == -1 && errno != 0) {
        perror("Failed to change priority");
        return EXIT_FAILURE;
    }
    printf("Priority reduced by 10.\n");

    // Sleep for 1,837,272,638 nanoseconds
    struct timespec ts;
    ts.tv_sec = 1;
    ts.tv_nsec = 837272638;
    if (nanosleep(&ts, NULL) == -1) {
        perror("Nanosleep failed");
        return EXIT_FAILURE;
    }

    printf("Goodbye!\n");
    return 0;
}