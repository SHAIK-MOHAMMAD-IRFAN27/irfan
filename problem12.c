
/*
name: problem12.c
author: SHAIK  MOHAMMAD IRFAN 
description: program to findout the opening mode of a file using fcntl

date:23rd august 2024
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int agrs,char *argv[]){
int fd=open(argv[1],O_CREAT |O_RDWR ,0644);
if(fd==-1){
perror("error opening file");
return 1;
}
int flags=fcntl(fd,F_GETFL,0);
if(flags==-1){
perror("error getting file flags");
close(fd);
return 1;
}
if(flags & O_RDONLY){
printf("file opened in read only mode\n ");
}else if(flags & O_WRONLY){
printf("file opened in write only mode \n");
}else if(flags & O_RDWR){
printf("file opened in read write mode \n");
}else{
printf("cant know the file access mode");
}
close(fd);
return 0;
}
/*OUTPUT:
file pr12.txt
file opened in read write mode*/