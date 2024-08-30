
/*
name: problem9.c
author: SHAIK  MOHAMMAD IRFAN 
description:Write a program to print the following information about a given file.
a. inode b. number of hard links c. uid d. gid e. size f. block size 
g. number of blocks h. time of last access 
i. time of last modification j. time of last change   

date:29th august 2024
*/
#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
void printfiledetails(const char *file){
struct stat file_stats;
if(stat(file,&file_stats)==-1){
perror("stat");
return ;
}
printf("file name :%s\n",file);
printf("Inode :%lu\n",file_stats.st_ino);
printf("no:of hard links : %lu\n",file_stats.st_nlink);
printf("UID :%u\n",file_stats.st_uid);
printf("GID %u\n",file_stats.st_gid);
printf("size: %ld bytes\n",file_stats.st_size);
printf("block size :%ld bytes\n",file_stats.st_blksize);
printf("no:of blocks :%ld\n",file_stats.st_blocks);
printf("last access time : %s\n",ctime(&file_stats.st_atime));
printf("last modification time : %s\n",ctime(&file_stats.st_mtime));
printf("last change time : %s",ctime(&file_stats.st_ctime));
}
int main(int args,char *argv[]){
if(args!=2){
perror("no arguments");
return 1;
}
int fd=open(argv[1],O_RDWR);
if(fd<0){
perror("error in openeng file");
return -1;
}
printfiledetails(argv[1]);
return 0;
}
/*
OUTPUT:
file name :pr9.txt
Inode :51980
no:of hard links : 1
UID :1000
GID 1000
size: 0 bytes
block size :4096 bytes
no:of blocks :0
last access time : Fri Aug 30 11:54:02 2024

last modification time : Fri Aug 30 11:54:02 2024

last change time : Fri Aug 30 11:54:02 2024
*/