/**************************************************************
Filename: pinfo.c 
Description: Take a single command line parameter that is a 
process identifier and print out the process ID, process 
priority, and scheduling method.
Author: Cade Andrae
Date: 11/17/24
Compile Instructions: gcc pinfo.c -o pinfo
Test Instructions:
      - Usage: ./pinfo <PID>
**************************************************************/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>

// Takes a scheduling policy as an argument and prints the scheduling method to the console
void print_scheduler(int policy) {
    switch (policy) {
        case SCHED_OTHER:
            printf("Scheduling method: Normal\n");
            break;
        case SCHED_FIFO:
            printf("Scheduling method: FIFO\n");
            break;
        case SCHED_RR:
            printf("Scheduling method: Round Robin\n");
            break;
        default:
            printf("Unknown scheduling method\n");
            break;
    }
}

// Gets the process ID, priority, and scheduling method of a specified process or the current process if no argument is provided
int main(int argc, char *argv[]) {
    pid_t pid;
    int priority, policy;

    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        pid = getpid();
    }

    errno = 0;
    priority = getpriority(PRIO_PROCESS, pid);
    if (errno != 0) {
        perror("Error retrieving priority");
        return EXIT_FAILURE;
    }
    printf("Process ID: %d\n", pid);
    printf("Process Priority: %d\n", priority);

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("Error retrieving scheduling method");
        return EXIT_FAILURE;
    }
    print_scheduler(policy);

    return 0;
}