/*
name: problem1c.c
author: SHAIK  MOHAMMAD IRFAN 
description:  Create the following types of a files using (i) shell command (ii) system call 
a. Fifo
date:19th august 2024
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
/*
OUTPUT:fifo file created
*/