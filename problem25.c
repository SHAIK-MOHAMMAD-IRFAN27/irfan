/*
name: problem25.c
author: SHAIK  MOHAMMAD IRFAN 
description: Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call). 
date:28th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int pid1, pid2, pid3;
    pid_t waited_pid;
    int status;
    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed for child 1");
        return 1;
    } else if (pid1 == 0) {
        printf("First child process (PID: %d) is running.\n", getpid());
        sleep(2);  
        printf("First child process (PID: %d) is exiting.\n", getpid());
        exit(0);
    }
    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork failed for child 2");
        return 1;
    } else if (pid2 == 0) {
        printf("Second child process (PID: %d) is running.\n", getpid());
        sleep(4);  
        printf("Second child process (PID: %d) is exiting.\n", getpid());
        exit(0);
    }
    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork failed for child 3");
        return 1;
    } else if (pid3 == 0) {
        printf("Third child process (PID: %d) is running.\n", getpid());
        sleep(6);  
        printf("Third child process (PID: %d) is exiting.\n", getpid());
        exit(0);
    }
    printf("Parent process (PID: %d) is waiting for second child (PID: %d).\n", getpid(), pid2);
    waited_pid = waitpid(pid2, &status, 0);

    if (waited_pid == -1) {
        perror("waitpid failed");
    } else {
        printf("Parent process (PID: %d) detected that child (PID: %d) exited.\n", getpid(), waited_pid);
        if (WIFEXITED(status)) {
            printf("Child (PID: %d) exited with status: %d\n", waited_pid, WEXITSTATUS(status));
        }
    }
    wait(NULL); 
    wait(NULL); 
	printf("Parent process (PID: %d) is exiting.\n", getpid());
    return 0;
}
/*
OUTPUT:
First child process (PID: 1240) is running.
Parent process (PID: 1239) is waiting for second child (PID: 1241).
Third child process (PID: 1242) is running.
Second child process (PID: 1241) is running.
First child process (PID: 1240) is exiting.
Second child process (PID: 1241) is exiting.
Parent process (PID: 1239) detected that child (PID: 1241) exited.
Child (PID: 1241) exited with status: 0
Third child process (PID: 1242) is exiting.
Parent process (PID: 1239) is exiting.
*/