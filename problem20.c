/*
name: problem20.c
author:SHAIK MOHAMMAD IRFAN
Description: Find out the priority of your running program. Modify the priority with nice command. 
Date: 30th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int priority;
    pid_t pid = getpid();
    errno = 0; 
    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority failed");
        return 1;
    }

    printf("Current Priority: %d\n", priority);
    int new_nice_value = 5; 
    int result = nice(new_nice_value);
    if (result == -1 && errno != 0) {
        perror("nice failed");
        return 1;
    }
    errno = 0;
    priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority failed");
        return 1;
    }
	printf("New Priority after nice(%d): %d\n", new_nice_value, priority);
    return 0;
}

/*
OUTPUT:
current priority:0
new priority after Nice : 10
*/