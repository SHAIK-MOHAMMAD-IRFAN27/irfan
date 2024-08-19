/*
name: Shaik Mohammad Irfan
roll number: MT2024138
*/
#include<stdio.h>
#include<unistd.h>
int main(int nums,char *files[]){
if(nums!=3){
fprintf(stderr,"no sufficeint files ");
return 1;
}
const char *target=files[1];
const char *link=files[2];
if(symlink(target,link)==0){
printf("soft link created between %s and %s",target,link);
return 0;
}
else{
perror("symlink");
return -1;
}
}
