/*
name: problem26.c
author: SHAIK  MOHAMMAD IRFAN 
description:Write a program to execute an executable program. 
a. use some executable program 
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
date:30th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    
    const char *program_path = "./pr26sub"; /* code of use26.c */
    char *args[] = {"./pr26sub", "Irfan", NULL}; 
    if (execvp(program_path, args) == -1) {
        perror("Error executing program");
        return 1;
    }
    printf("This will not be printed if execvp() succeeds.\n");
    return 0;
}

/*
output :
Hello, Irfan!
*/
