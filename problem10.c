/* 
name: SHAIK MOHAMMAD IRFAN
roll : MT2024138
problem statement:write program to open file in RW mode,write 10 bytes move  the file pointer by 10 byte use lseek write 10 bytes again 
a. check the return value of lseek
b.open file with od and check the empty spaces between data

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int args,char *argv[]){
if(args!=2){
perror("no arguments");
return 1;
}
int fd;
off_t offset;
char buffer1[11]="Hiiamirfan";
char buffer2[11]="iamwalking";
fd=open(argv[1],O_RDWR | O_CREAT,0644);
if(fd==-1){
perror("error opening file");
return 1;
}
if(write(fd,buffer1,10)==-1){
perror("error in writing file");
close(fd);
return 1;
}
offset=lseek(fd,10,SEEK_CUR);
if(offset==-1){
perror("error using lseek");
close(fd);
return 1;
}
else{
printf("the currrent cursor moved to %ld \n",(long)offset);
}
if(write(fd,buffer2,10)==-1){
perror("error in writing file");
close(fd);
return 1;
}
close(fd);
return 0;
}
