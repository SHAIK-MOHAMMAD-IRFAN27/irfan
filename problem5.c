/*
name: SHAIK MOHAMMAD IRFAN
roll : MT2024138
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
