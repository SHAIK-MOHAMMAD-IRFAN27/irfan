/*
name: SHAIK MOHAMMAD IRFAN
roll : MT2024138
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
