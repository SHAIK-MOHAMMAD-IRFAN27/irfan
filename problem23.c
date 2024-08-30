/*
name: problem23.c
author: SHAIK  MOHAMMAD IRFAN 
description:program to create zombie state of running program 
date:28th august 2024
*/
#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
int pid=fork();
if(pid<0){
fprintf(stderr,"Fork failed");
return 1;
}else if(pid==0){
printf("child process  %d is exiting \n",getpid());
exit(0);
}else{
printf("parent process  %d is sleeping \n",getpid());
sleep(10);
printf("the parent process %d has woken up\n",getpid());
}
return 0;
}
/*
OUTPUT:
parent process  1201 is sleeping
child process  1202 is exiting
*/
