/*
name: problem5.c
author: SHAIK  MOHAMMAD IRFAN 
description:Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd.

date:20th august 2024
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
int fd;
char filename[31];
while(1){
for(int i=1;i<6;i++){
snprintf(filename,sizeof(filename),"file%d%d.txt",i,i);
fd=open(filename,O_CREAT|O_RDWR|O_EXCL,0644);
if(fd==-1){
perror("error in opening file");
exit(1);
}
printf("created file %s with fd:%d\n",filename,fd);
close(fd);
}
sleep(100);
}
return 0;
}
/*
OUTPUT:
created file file11.txt with fd:3
created file file22.txt with fd:3
created file file33.txt with fd:3
created file file44.txt with fd:3
created file file55.txt with fd:3
*/
