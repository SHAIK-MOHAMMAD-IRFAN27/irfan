/*
name: problem4.c
author: SHAIK  MOHAMMAD IRFAN 
description:Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
 
date:20th august 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main(int nums,char *args[]){
int fd;
if(nums!=2){
fprintf(stderr,"insufficient arguments");
}
fd=open(args[1],O_RDWR,0644);
if(fd==-1){
perror("error in opening file\n");
return 1;
}
printf("file opened successfully in RDWR mode with FD : %d\n",fd);
int fdexcl=open(args[1],O_EXCL | O_RDWR) ;
if(fdexcl==-1){
perror("error in opening file due to EXCL flag\n");
return 1;
}
printf("file opened with EXCL flag successfully with FD: %d\n",fdexcl);
close(fd);
close(fdexcl);
return 0;
}

/*
OUTPUT:
file opened successfully in RDWR mode with FD:3
file opened with EXCL flag successfully with FD:4
*/
