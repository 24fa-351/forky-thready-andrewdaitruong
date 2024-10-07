#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "forkypattern.h"

void fork_process(int process_number) {
    printf("Process %d started.\n", process_number);
    
    // Sleep for a random time between 1 and 8 seconds
    int sleep_time = rand() % 8 + 1;
    sleep(sleep_time);

    printf("Process %d exiting after %d seconds.\n", process_number, sleep_time);
}

//forks all processes at once
void pattern_one(int num_things) {
    for (int i = 1; i <= num_things; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            fork_process(i);
            exit(0);
        }
    }

    // Wait for all child processes to finish
    for (int i = 1; i <= num_things; i++) {
        wait(NULL);
    }
}

//forks one process after the next
void pattern_two(int num_things) {
    for (int i = 1; i <= num_things; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            fork_process(i);
            exit(0);
        }
        wait(NULL); // Wait for the current child to finish before forking the next
    }
}