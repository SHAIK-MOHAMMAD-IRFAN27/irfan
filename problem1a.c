/*
name: problem1a.c
author: SHAIK  MOHAMMAD IRFAN 
description:  Create the following types of a files using (i) shell command (ii) system call 
a. soft link (symlink system call)
date:19th august 2024
*/
#include<stdio.h>
#include<unistd.h>
int main(int nums,char *files[]){
if(nums!=3){
fprintf(stderr,"no sufficeint files ");
return 1;
}
const char *target=files[1];
const char *link=files[2];
if(symlink(target,link)==0){
printf("soft link created between %s and %s",target,link);
return 0;
}
else{
perror("symlink");
return -1;
}
}

/*
OUTPUT :
soft link created between file1 and file 2
*/