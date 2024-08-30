
/*
name: problem24.c
author: SHAIK  MOHAMMAD IRFAN 
description:program to create orphan process of running program
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
sleep(10);
printf("child process  %d is an orphan process since parent is exited. its new parent is %d \n",getpid(),getppid());
}else{
printf("parent process with PID %d is terminating  now ",getpid());
exit(0);
}
return 0;
}

/*
OUTPUT:
parent process with PID 1218 is terminating  now 
child process  1219 is an orphan process since parent is exited. its new parent is 12
*/