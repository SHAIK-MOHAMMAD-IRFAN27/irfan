
/*
name: problem13.c
author: SHAIK  MOHAMMAD IRFAN 
description: program to wait for STDIN for 10 sec using select.
write proper print statement to verify the data is available witin 10 sec or not

date:23rd august 2024
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/select.h>
int main(){
struct timeval tv;
fd_set readfds;
int ret;
tv.tv_sec=10;
tv.tv_usec=0;
FD_ZERO(&readfds);
FD_SET(STDIN_FILENO,&readfds);
ret=select(STDIN_FILENO+1,&readfds,NULL,NULL,&tv);
if(ret==-1){
perror("error in select");
return 1;
}
else if(ret==0){
printf("no data within 10 seconds");
}
else{
if(FD_ISSET(STDIN_FILENO,&readfds)){
char buffer[1024];
if(fgets(buffer,sizeof(buffer),stdin)!=NULL){
printf("input data : %s",buffer);
}
}
}
return 0;
}
/*
OUTPUT:
file :pr13.txt
hi my name is irfan shaik (contents written in the file)
*/