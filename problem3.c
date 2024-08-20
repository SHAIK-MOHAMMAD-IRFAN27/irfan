/*
name : SHAIK MOHAMMAD IRFAN
roll: MT2024138
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
