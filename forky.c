#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "forkypattern.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [123] <num>\n", argv[0]);
        return 1;
    }

    int num_things = atoi(argv[2]);
    if (num_things < 1 || num_things > 256) {
        printf("Number of things must be between 1 and 256.\n");
        return 1;
    }
    
    if (argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '3') {
        printf("Invalid pattern number. Gotta be 1/2/3\n");
        return 1;
    }
    

    srand(time(NULL)); // Seed the random number generator

    if (argv[1][0] == '1') {
        pattern_one(num_things);
    } 
    else if (argv[1][0] == '2') {
        pattern_two(num_things);
    }
    // else if (argv[1][0] == '3') {
    //     pattern_three(num_things);
    // }

    return 0;
}
