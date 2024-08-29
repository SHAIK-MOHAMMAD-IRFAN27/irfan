/*
name :SHAIK MOHAMMAD IRFAN
ROLL: MT2024138
problem statement :open a file,call fork and write to file by child and parent
and check output of file
*/
#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
int main(int args,char* argv[]){
if(args!=2){
printf("no file given as input \n");
return 0;
}
int fd=open(argv[1],O_WRONLY,0644);
if(fd<0){
perror("failed to open file \n");
return 1;
}
int pid=fork();
if(pid<0){
fprintf(stderr,"Fork failed");
return 1;
}else if(pid==0){
const char *child_msg="this is written by child process\n ";
write(fd,child_msg,sizeof(child_msg)-1);
printf("child process PID %d wrote in the file \n",getpid());
}else{
const char *parent_msg="This is written by parent process\n";
write(fd,parent_msg,sizeof(parent_msg)-1);
printf("parent process PID  %d wrote into this file \n",getpid());
}
close(fd);
return 0;
}

