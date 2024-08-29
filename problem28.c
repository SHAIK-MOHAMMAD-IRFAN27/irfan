/*
name : SHAIK MOHAMMAD IRFAN
ROLL NO: MT2024138
problem statement :. Write a program to get maximum and minimum real time priority. 
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
