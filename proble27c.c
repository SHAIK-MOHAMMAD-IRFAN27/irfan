/*
name: problem27c.c
author: SHAIK  MOHAMMAD IRFAN 

description: Write a program to execute ls -Rl by the following system calls 
c)execle
date:30th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *envp[] = { "HOME=/usr/home", "LOGNAME=home", NULL };
    if (execle("/bin/ls", "ls", "-Rl", NULL, envp) == -1) {
        perror("Error executing ls with execle");
        return 1;
    }
    return 0;
}
/*
OUTPUT :
gives output of the command ls -Rl
*/