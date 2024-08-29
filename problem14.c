/*
name:SHAIK MOHAMMAD IRFAN
ROLL : MT2024138
prioblem statement: program to find the type of file
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
void printfiletype(struct stat *fileStat){
if(S_ISREG(fileStat->st_mode)){
printf("File is a regulsr type of file");
}
else if(S_ISDIR(fileStat->st_mode)){
printf("file is a directory\n");
}
else if(S_ISCHR(fileStat->st_mode)){
printf("file is a character device");
}
else if(S_ISFIFO(fileStat->st_mode)){
printf("file is a fifo file");
}
else if(S_ISBLK(fileStat->st_mode)){
printf("file is a block type");
}
else if(S_ISLNK(fileStat->st_mode)){
printf("file is a symbolic link");
}
else{
printf("file is unknown");
}
}
int main(int args,char *argv[]){
if(args!=2){
fprintf(stderr,"usage: %s <file path>\n",argv[0]);
return 1;
}
struct stat fileStat;
if(stat(argv[1],&fileStat)<0){
perror("stat");
return 1;
}
printfiletype(&fileStat);
return 0;
}
