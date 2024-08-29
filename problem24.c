/*
name :SHAIK MOHAMMAD IRFAN
ROLL: MT2024138
problem statement :program to create orphan process of running program
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

