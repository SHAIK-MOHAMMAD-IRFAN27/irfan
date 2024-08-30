/*
name: problem8.c
author: SHAIK  MOHAMMAD IRFAN 
description: Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached.    

date:22nd august 2024
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int args,char *argv[]){
char line[100];
FILE *file;
if(args!=2){
printf("no sufficient arguments");
return 1;
}
const char *filename=argv[1];
file=fopen(filename,"r");
if(file==NULL){
perror("file couldnt be opened");
return -1;
}
while(fgets(line,sizeof(line),file)!=NULL){
	printf("%s",line);
}
fclose(file);
return 0;
}
/*
OUTPUT:
file pr8 will be read
hello 
im irfan
im from Andhra 
i like eating
etc etc etc*/