/*
name: problem6.c
author: SHAIK  MOHAMMAD IRFAN 
description: Write a program to take input from STDIN and display on STDOUT.
 Use only read/write system calls  

date:20th august 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char buffer[1024];
ssize_t bytesread=read(STDIN_FILENO,buffer,sizeof(buffer));
if(bytesread== -1){
perror("error reading from STDIN");
exit(EXIT_FAILURE);
}
ssize_t byteswritten=write(STDOUT_FILENO,buffer,bytesread);
if(byteswritten==-1){
perror("error writing to the STANDARD OUTPUT");
exit(EXIT_FAILURE);
}
return 0;
}
/*
OUTPUT:
give some input text
that input will come as ouput text an printed on the screen
*/