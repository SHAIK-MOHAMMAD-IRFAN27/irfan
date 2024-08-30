
/*
name: problem29.c
author: SHAIK  MOHAMMAD IRFAN 
description: Write a program to get scheduling policy and
 modify the scheduling policy (SCHED_FIFO,  
SCHED_RR).  
date:29th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
int main() {
    int policy;
    struct sched_param param;
    policy = sched_getscheduler(0); 
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return 1;
    }
    switch(policy) {
        case SCHED_OTHER:
            printf("Current Scheduling Policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current Scheduling Policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown Scheduling Policy\n");
    }

 	param.sched_priority = sched_get_priority_max(SCHED_FIFO); 
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler failed");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);
 
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return 1;
    }

        switch(policy) {
        case SCHED_OTHER:
            printf("New Scheduling Policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("New Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("New Scheduling Policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown Scheduling Policy\n");
    }

        param.sched_priority = sched_get_priority_max(SCHED_RR); 
    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler failed");
        return 1;
    }

    printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);

    
    policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        return 1;
    }
    switch(policy) {
        case SCHED_OTHER:
            printf("New Scheduling Policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("New Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("New Scheduling Policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown Scheduling Policy\n");
    }

    return 0;
}
/*
OUTPUT:
Current Scheduling Policy: SCHED_OTHER
sched_setscheduler failed: Operation not permitted
*/