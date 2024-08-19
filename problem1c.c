/*
name: Shaik Mohammad Irfan
roll number : MT2024138
*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int nums,char *args[]){
if(nums!=2){
fprintf(stderr,"no arguments");
return 1;
}
const char *filefifo = args[1];
if(mkfifo(filefifo,0666)==0){
printf("fifo file created ");
return 0;
}
else{
perror("mkfifo");
return -1;
}
}
