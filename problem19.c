/*
name: problem19.c
author: SHAIK  MOHAMMAD IRFAN 
description:. Write a program to find out time taken to
 execute getpid system call. Use time stamp counter. 
date:27th august 2024
*/
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
static inline uint64_t rdtsc(){
unsigned int lo,hi;
asm volatile ("rdtsc": "=a"(lo), "=d"(hi));
return ((unsigned long long)hi <<32) |lo;
}
int main(){
unsigned long long start,end;
pid_t pid;
start=rdtsc();
pid=getpid();
end=rdtsc();
printf("pID : %d\n",pid);
printf("time taken by getpid() is :%llu \n",(end-start));
return 0;
}
/*OUTPUT:
pID : 1138
time taken by getpid() is :7159
*/
