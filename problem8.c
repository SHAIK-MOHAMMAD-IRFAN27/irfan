/* name : SHAIK MOHAMMAD IRFAN
roll : MT2024138
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int args,char *argv[]){
char line[100];
if(args!=2){
printf("no sufficient arguments");
return 1;
}
const char *filename=argv[1];
int fd=open(filename,O_RDONLY,0600);
if(fd==-1){
perror("file couldnt be opened");
return -1;
}
while(fgets(line,sizeof(line)

