/*
name: Shaik Mohammad Irfan
roll number : MT2024138
*/
#include<stdio.h>
#include<unistd.h>
int main(int nums,char *files[]){
if(nums!=3){
fprintf(stderr,"insufficient arguments");
return 1;
}
const char *target=files[1];
const char *linkpath=files[2];
if(link(target,linkpath)==0){
printf("hard link between %s to %s is successful ",linkpath,target);
return 0;
}
else{
perror("link");
return -1;
}
}
