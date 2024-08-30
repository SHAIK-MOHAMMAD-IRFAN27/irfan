/*
name: problem21.c
author: SHAIK  MOHAMMAD IRFAN 
description:.program to create fork() call and print parent and child pid
date:27th august 2024
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
printf("child process PId is %d   \n",getpid());
printf("parent of the child process PID is %d ",getppid());
}else{
printf("parent process PID is %d \n",getpid());
printf("the child process PID is %d \n",getpid());
}
return 0;
}

/*
OUTPUT:
parent process PID is 1158
the child process PID is 1158
child process PId is 1159
parent of the child process PID is 12
*/