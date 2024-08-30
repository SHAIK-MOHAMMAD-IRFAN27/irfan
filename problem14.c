/*
name: problem14.c
author: SHAIK  MOHAMMAD IRFAN 
description:  Write a program to find the type of a file. 
a. Input should be taken from command line. 
b. program should be able to identify any type of a file. 

date:24th august 2024
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
void printfiletype(struct stat *fileStat){
if(S_ISREG(fileStat->st_mode)){
printf("File is a regular type of file");
}
else if(S_ISDIR(fileStat->st_mode)){
printf("file is a directory\n");
}
else if(S_ISCHR(fileStat->st_mode)){
printf("file is a character device");
}
else if(S_ISFIFO(fileStat->st_mode)){
printf("file is a fifo file");
}
else if(S_ISBLK(fileStat->st_mode)){
printf("file is a block type");
}
else if(S_ISLNK(fileStat->st_mode)){
printf("file is a symbolic link");
}
else{
printf("file is unknown");
}
}
int main(int args,char *argv[]){
if(args!=2){
fprintf(stderr,"usage: %s <file path>\n",argv[0]);
return 1;
}
struct stat fileStat;
if(stat(argv[1],&fileStat)<0){
perror("stat");
return 1;
}
printfiletype(&fileStat);
return 0;
}
/*OUTPUT:
pr14 file
file is a fifo file 
*/
