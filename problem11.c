/*
name: problem11.c
author: SHAIK  MOHAMMAD IRFAN 
description:program to open a file , duplicate fd & append the file with both descriptors and 
check whether file is updated properly  or not

date:22nd august 2024
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int args,char *argv[]){
int fd1,fddup,fddup2,fdfcntl;
char buffer[50]="hi my name is irfan and im from andhra pradesh";
char buffer2[50]="how are you iam fine what about u?";
char buffer3[50]="im currently studying at iiit bangalore mtech";
char buffer4[50]="this is a program from hands on list problem 11";
fd1=open(argv[1],O_WRONLY |O_APPEND,0644 );
if(fd1==-1){
perror("error in opening file");
return 1;
}
if(write(fd1,buffer,sizeof(buffer))==-1){
perror("error in writing with fd1");
close(fd1);
return 1;
}
fddup=dup(fd1);
if(fddup==-1){
perror("error in duplicating fd1");
close(fd1);
return 1;
}
if(write(fddup,buffer2,sizeof(buffer2))==-1){
perror("error in writing with fddup");
close(fd1);
close(fddup);
return 1;
}
fddup2=dup2(fd1,fddup+1);
if(fddup2==-1){
perror("error in duplicating fd1 with dup2");
close(fd1);
close(fddup);
return 1;
}
if(write(fddup2,buffer3,sizeof(buffer3))==-1){
perror("error writing with fddup2");
close(fd1);
close(fddup);
close(fddup2);
return 1;
}
fdfcntl=fcntl(fd1,F_DUPFD,0);
if(fdfcntl==-1){
perror("error in creating a duplicate fd with fcntl function");
close(fd1);
close(fddup);
close(fddup2);
return 1;
}
if(write(fdfcntl,buffer4,sizeof(buffer4))==-1){
perror("error in writing with fdfcntl");
close(fd1);
close(fddup);
close(fddup2);
close(fdfcntl);
return 1;
}
close(fd1);
close(fddup);
close(fddup2);
close(fdfcntl);
printf("file updated successfully");
return 0;
}

/*
OUTPUT:
file:pr11.txt
file updated successfully
"hi my name is irfan and im from andhra pradeshhow are you iam 
fine what about u?im currently studying at
 iiit bangalore mtechthis is a program from hands on list problem "
 */