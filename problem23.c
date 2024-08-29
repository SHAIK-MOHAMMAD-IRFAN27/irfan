/*
name :SHAIK MOHAMMAD IRFAN
ROLL: MT2024138
problem statement :program to create zombie state of running program
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

