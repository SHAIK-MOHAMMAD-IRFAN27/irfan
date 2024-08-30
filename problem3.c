/*
name: problem3.c
author: SHAIK  MOHAMMAD IRFAN 
description:   Write a simple program to execute in an infinite loop at the background. Go to /proc directory and 
identify all the process related information in the corresponding proc directory. 
 
date:19th august 2024
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h> // required to close() function
int main(){
int fd;
fd = creat("problem3.txt",0644);
if(fd==-1){
perror("Error in creating the file");
return 1;
}
printf("File Destriptor of the file:'problem3.txt' is %d",fd);
close(fd);
return 0;
}
/*
OUTPUT:
File DEscriptor of the file 'problem3.txt' is 1
*/