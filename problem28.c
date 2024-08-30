
/*
name: problem28.c
author: SHAIK  MOHAMMAD IRFAN 
description:Write a program to get maximum and minimum real time priority.  
date:29th august 2024
*/
#include<stdio.h>
#include<sched.h>
int main(){
int max_p,min_p;
max_p=sched_get_priority_max(SCHED_FIFO);
min_p=sched_get_priority_min(SCHED_FIFO);
if(max_p==-1 || min_p==-1){
perror("sched_get_max_priotity or sched_get_min_priority is failed\n");
return 1;
}
printf("SCHED_FIFO : MAX_priotity =%d ad min_priority is=%d\n ",max_p,min_p);
max_p=sched_get_priority_max(SCHED_RR);
min_p=sched_get_priority_min(SCHED_RR);
if(max_p==-1 || min_p==-1){
perror("sched_get_priority_max/min is failed\n");
return 1;
}
printf("SCHED_RR: max priority is =%d and min priority is =%d\n",max_p,min_p);
return 0;
}
/*
OUTPUT:
SCHED_FIFO : MAX_priotity =99 ad min_priority is=1
SCHED_RR: max priority is =99 and min priority is =1
 */