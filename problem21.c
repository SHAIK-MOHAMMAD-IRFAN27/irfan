/*
name :SHAIK MOHAMMAD IRFAN
ROLL: MT2024138
problem statement :program to create fork() call and print parent and child pid
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

