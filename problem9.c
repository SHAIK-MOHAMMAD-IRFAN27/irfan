/* 
  name : SHAIK MOHAMMAD IRFAN
roll : MT2024138
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
