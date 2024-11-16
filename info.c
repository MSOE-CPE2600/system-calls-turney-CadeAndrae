/**************************************************************
Filename: info.c 
Description: Provides data about the system using maintenance. 
system calls.
Author: Cade Andrae
Date: 11/16/24
Compile Instructions: gcc info.c -o info
Test Instructions:
      - Usage: ./info
**************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

int main() {
    struct timespec ts;
    struct utsname unameData;
    char hostname[256];

    // Get the current time in nanoseconds
    if (clock_gettime(CLOCK_REALTIME, &ts) == -1) {
        perror("Failed to get time");
        return EXIT_FAILURE;
    }
    printf("Current time (ns): %ld\n", ts.tv_nsec);

    // Get hostname
    if (gethostname(hostname, sizeof(hostname)) == -1) {
        perror("Failed to get hostname");
        return EXIT_FAILURE;
    }
    printf("Hostname: %s\n", hostname);

    // Get OS information
    if (uname(&unameData) == -1) {
        perror("Failed to get system information");
        return EXIT_FAILURE;
    }
    printf("OS Name: %s\n", unameData.sysname);
    printf("OS Release: %s\n", unameData.release);
    printf("OS Version: %s\n", unameData.version);
    printf("Hardware Type: %s\n", unameData.machine);

    // Get the number of processors
    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of CPUs: %ld\n", nprocs);

    // Get memory information
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("Failed to get memory info");
        return EXIT_FAILURE;
    }
    printf("Total Physical Memory (Bytes): %lu\n", info.totalram * info.mem_unit);
    printf("Free Physical Memory (Bytes): %lu\n", info.freeram * info.mem_unit);

    return 0;
}