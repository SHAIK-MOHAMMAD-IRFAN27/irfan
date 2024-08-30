/*
name: problem27b.c
author: SHAIK  MOHAMMAD IRFAN 

description: Write a program to execute ls -Rl by the following system calls 
b) excelp
date:30th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (execlp("ls", "ls", "-Rl", NULL) == -1) {
        perror("Error executing ls with execlp");
        return 1;
    }
    return 0;
}
/*
OUTPUT :
gives output of the command ls -Rl
*/